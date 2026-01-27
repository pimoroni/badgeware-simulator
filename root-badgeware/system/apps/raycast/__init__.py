from picovector import algorithm
import math
import time
from map import Map
from player import Player

import micropython

def _noop(fn):
    return fn

native = getattr(micropython, "native", _noop)
viper  = getattr(micropython, "viper",  _noop)

wall_sprite = image.load("assets/CONCRETE_4C_SMALL.PNG")
size = 2

# grotty way to quickly define the map as a string to make it easy to edit
world_map = """
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X       X            X         X
XXXXXXX X            X         X
X       X            X         X
X       X            X         X
X                    X         X
X       X                      X
XXXXXXXXX                      X
X                              X
X                              X
X               XXXXXXXXX      X
X     XXX       X       X      X
X     X X           XXXXX      X
X     X X               X      X
X                       X      X
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
"""
world_map = world_map.strip().split("\n")

# convert "grotty" map into real map object
map = Map(len(world_map[0]), len(world_map))
for y in range(map.height):
  for x in range(map.width):
    v = world_map[y][x]
    map.get_tile(x, y).solid = True if v == "X" else False

# convert map data into format used by DDA algorithm to detect intersections
map_dda_flags = map.build_dda_flags()

player = Player(vec2(16, 8), 0)

def deg2rad(angle):
  return angle * (math.pi / 180.0)

pen_lut = [color.rgb(20, 40, 60, a) for a in range(256)]

# precompute degrees->radians once
deg2rad_k = math.pi / 180.0

# hoist commonly used functions
raycast = algorithm.raycast
cos = math.cos
tan = math.tan

lengths = 0
@native
def render(result):
  global lengths


  # cache attrs (attribute lookups are slow in MicroPython)
  screen_w = screen.width

  screen_blit_vspan = screen.blit_vspan
  screen_rect = screen.rectangle
  wall_sprite_w = wall_sprite.width
  wall_sprite_h = wall_sprite.height
  wall_height = 1
  half_screen_w = screen_w * 0.5
  half_fov_rad = (player.fov * deg2rad_k) * 0.5
  d_proj = half_screen_w / tan(half_fov_rad)

  player_angle_rad = player.angle * deg2rad_k  # used for cos correction
  d_proj = (screen.width / 2) / math.tan(deg2rad(player.fov) / 2)
  wall_height = 1

  lengths = 0

  wall_blits = []

  for i in range(160):
    ray = result[i]

    if len(ray) < 1:
       continue;


    # Most rays will only use the first hit; avoid iterating full ray list if possible.
    for entry in ray:
        distance = entry[5]
        # if distance <= 0:
        #     break

        offset = entry[4]
        ray_angle = entry[6]

        # perp distance (fish-eye correction); ray_angle is assumed radians here.
        perp = distance * cos(ray_angle - player_angle_rad)
        if perp < 0.0001:
            perp = 0.0001

        height = (wall_height * d_proj) / perp

        x = i
        y = int(60 - (height * 0.5))
        u = int(offset * wall_sprite_w)

        wall_blits.append(("blit_vspan", (wall_sprite, x, y, height, u, 0, u, wall_sprite_h - 1)))
        #screen_blit_vspan(wall_sprite, sxy, height, uv1, uv2)

        # brightness
        b = int(distance * 10)
        if b < 0:
            b = 0
        elif b > 255:
            b = 255

        # If your color.rgb allocates, you can cache a 256-entry LUT (see below).
        wall_blits.append(("pen", (pen_lut[b])))
        wall_blits.append(("rectangle", (x, y, 1, height)))

        break

  screen.batch(wall_blits)
  #screen_blit_vspan(wall_blits)

frame_times = []
def update():
  global frame_times

  start = time.ticks_ms()

  # draw sky and floor
  screen.pen = color.brown
  screen.rectangle(0, 0, 160, 60)
  screen.pen = color.taupe
  screen.rectangle(0, 60, 160, 60)

  # movement scale
  delta_scale = io.ticks_delta / 1000

  # move player based on button states
  if io.BUTTON_A in io.held:
    player.angle -= 90 * delta_scale
    player.angle %= 360

  if io.BUTTON_C in io.held:
    player.angle += 90 * delta_scale
    player.angle %= 360

  if io.BUTTON_UP in io.held:
    player.pos += player.vector() * 10 * delta_scale

  if io.BUTTON_DOWN in io.held:
    player.pos -= player.vector() * 10 * delta_scale

  result = algorithm.raycast(player.pos, player.angle, player.fov, 160, 100, map_dda_flags, map.width, map.height, screen.width)

  render(result)

  end = time.ticks_ms()
  duration = max(1, end - start)
  frame_times.append(duration)
  frame_times = frame_times[-20:]

  fps = round(1000 / (sum(frame_times) / len(frame_times)), 1)
  screen.pen = color.rgb(255, 255, 255)
  screen.text(f"{fps}fps", 2, 0)
  screen.text(f"{lengths/160}avg", 2, 10)
