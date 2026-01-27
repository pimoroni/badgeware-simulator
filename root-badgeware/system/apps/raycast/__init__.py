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

lengths = 0
@native
def build(rays):
  # cache attrs (attribute lookups are slow in MicroPython)
  cos = math.cos

  wall_sprite_w = wall_sprite.width
  wall_sprite_h = wall_sprite.height
  wall_height = 1

  player_angle_rad = player.angle * deg2rad_k  # used for cos correction
  d_proj = (screen.width / 2) / math.tan(deg2rad(player.fov) / 2)
  wall_height = 1
  whdproj = wall_height * d_proj

  draws = [None] * (160*3)

  x, y, u, b, perp, height = None, None, None, None, None, None
  offset, distance, ray_angle = None, None, None

  for i in range(160):
    #_, _, _, _, offset, distance, _ = rays[i][0]
    ray = rays[i][0]
    offset = ray[4]
    distance = ray[5]

    height = whdproj / distance

    x = i
    y = int(60 - (height * 0.5))
    u = offset

    # brightness
    b = int(distance * 10)
    if b < 0: b = 0
    elif b > 255: b = 255

    draws[i * 3 + 0] = ("blit_vspan", wall_sprite, x, y, height, u, 0, u, 1)
    draws[i * 3 + 1] = ("pen", pen_lut[b])
    draws[i * 3 + 2] = ("rectangle", x, y, 1, height)

    # screen.blit_vspan(wall_sprite, x, y, height, u, 0, u, wall_sprite_h - 1)
    # screen.pen = pen_lut[b]
    # screen.rectangle(x, y, 1, height)

  return draws


frame_times = []
def update():
  global frame_times

  frame_start = time.ticks_ms()

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

  start = time.ticks_ms()
  rays = algorithm.raycast(player.pos, player.angle_radians(), player.fov, 160, 100, map_dda_flags, map.width, map.height, screen.width)
  raycast_time = time.ticks_ms() - start

  start = time.ticks_ms()
  draws = build(rays)
  build_time = time.ticks_ms() - start

  start = time.ticks_ms()
  screen.batch(draws)
  render_time = time.ticks_ms() - start

  screen.pen = color.rgb(255, 255, 255)
  screen.text(f"raycast: {raycast_time}ms", 2, 85)
  screen.text(f"build: {build_time}ms", 2, 95)
  screen.text(f"render: {render_time}ms", 2, 105)


  screen.pen = color.rgb(255, 255, 255)


  frame_end = time.ticks_ms()
  frame_duration = max(1, frame_end - frame_start)
  frame_times.append(frame_duration)
  frame_times = frame_times[-20:]

  fps = round(1000 / (sum(frame_times) / len(frame_times)), 1)
  screen.pen = color.rgb(255, 255, 255)
  screen.text(f"{fps}fps", 2, 0)
