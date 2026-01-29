from picovector import algorithm
import math
import time
from map import Map
from player import Player
from texture import atlas, load_texture
import micropython

def _noop(fn):
    return fn

native = getattr(micropython, "native", _noop)
viper  = getattr(micropython, "viper",  _noop)

enemy = SpriteSheet("assets/PlayerWalk 48x48.png", 8, 1).animation(0, 0, 8)
sky_texture = image.load("assets/sky.png")
wall_sprite = image.load("assets/CONCRETE_4C.PNG")
floor_sprite = image.load("assets/COBBLES_2D.PNG")

load_texture(128, "assets/CONCRETE_4A.PNG")
load_texture(129, "assets/CONCRETE_4C.PNG")
load_texture(130, "assets/CONCRETE_6A.PNG")
load_texture(131, "assets/CONCRETE_6B.PNG")
load_texture(132, "assets/CONCRETE_6C.PNG")


load_texture(2, "assets/COBBLES_2D.PNG")

size = 2

# grotty way to quickly define the map as a string to make it easy to edit
world_map = """
################z###############
#  !    #            #         #
####### #          ! #  !!!!!  #
#       z   !   @    #         #
#   !   #            #         #
#                    #         #
#       #                !     #
#####z###      !               z
#!                  !  !       #
#!     !                       #
#!              #########      #
z!    #z#       #       #      #
#!    #!#           #####   !  #
#!    # #    !          #      #
#!                      #      #
################################
"""
world_map = world_map.strip().split("\n")


player_start_pos = None
sprites = []

# convert "grotty" map into real map object
map = Map(len(world_map[0]), len(world_map))
for y in range(map.height):
  for x in range(map.width):
    v = world_map[y][x]
    if v == "#":
      map.get_tile(x, y).solid = True
      map.get_tile(x, y).texture_index = 128

    if v == "z":
      map.get_tile(x, y).solid = True
      map.get_tile(x, y).texture_index = 130

    if v == "@":
      player_start_pos = vec2(x + 0.5, y + 0.5)

    if v == "!":
      sprites.append(vec2(x + 0.5, y + 0.5))

# convert map data into format used by DDA algorithm to detect intersections
map_dda_flags = map.build_dda_flags()

player = Player(player_start_pos, 0, map)

shade_pen_lut = [color.rgb(20, 40, 60, a) for a in range(256)]

frame_times = []
def update():
  global frame_times
  frame_start = time.ticks_ms()

  player.process_inputs()

  start = time.ticks_ms()
  draw_sky()
  draw_sky_time = time.ticks_ms() - start

  start = time.ticks_ms()
  draw_floor()
  draw_floor_time = time.ticks_ms() - start

  start = time.ticks_ms()
  rays = algorithm.raycast(player.pos, player.angle, player.fov, 160, 100, map_dda_flags, map.width, map.height, screen.width)
  raycast_time = time.ticks_ms() - start

  start = time.ticks_ms()
  draw_world(rays)
  draw_world_time = time.ticks_ms() - start

  start = time.ticks_ms()
  draw_sprites()
  draw_sprites_time = time.ticks_ms() - start

  # draw timing stats
  screen.pen = color.rgb(255, 255, 255)
  screen.text(f"raycast: {raycast_time}ms", 2, 65)
  screen.text(f"sky: {draw_sky_time}ms", 2, 75)
  screen.text(f"floor: {draw_floor_time}ms", 2, 85)
  screen.text(f"world: {draw_world_time}ms", 2, 95)
  screen.text(f"sprites: {draw_sprites_time}ms", 2, 105)

  # draw fps counter
  frame_end = time.ticks_ms()
  frame_duration = max(1, frame_end - frame_start)
  frame_times.append(frame_duration)
  frame_times = frame_times[-60:]
  fps = round(1000 / (sum(frame_times) / len(frame_times)))
  screen.text(f"{fps}fps", 2, 0)

@native
def draw_sky():
  # calculate u texture coordinate for left and right side of sky texture
  # so that it wraps with a full rotation of the player
  u0 = ((player.angle - player.fov) / (2 * math.pi))
  u1 = ((player.angle + player.fov) / (2 * math.pi))

  half_height = int(screen.height / 2)

  for y in range(0, half_height):
    v = y / half_height

    screen.blit_hspan(sky_texture, 0, y, 160, u0, v, u1, v)

@native
def draw_floor():
  # calculate camera frustrum plane relative to player position and direction
  frustum_width = math.tan(player.fov * 0.5)
  player_dir = player.vector()
  plane = vec2(-player_dir.y * frustum_width, player_dir.x * frustum_width)

  half_height = int(screen.height / 2)
  camera_height = half_height

  # camera frustrum left and right vectors in world space
  frustrum_left = vec2(player_dir.x - plane.x, player_dir.y - plane.y)
  frustrum_right = vec2(player_dir.x + plane.x, player_dir.y + plane.y)

  for y in range(half_height + 1, screen.height):
    # distance in world coordinates to this row on screen
    distance = camera_height / (y - half_height)

    # floor left and right coordinates in world space for this row
    floor_left = vec2(
      player.pos.x + distance * frustrum_left.x,
      player.pos.y + distance * frustrum_left.y
    )

    floor_right = vec2(
      player.pos.x + distance * frustrum_right.x,
      player.pos.y + distance * frustrum_right.y
    )

    # select correct texture and mipmap level
    tex = atlas[2][min(4, int(distance / 4))]
    screen.blit_hspan(tex, 0, y, 160, floor_left.x, floor_left.y, floor_right.x, floor_right.y)

  # add distance fade effect to floor
  step = 10
  for y in range(0, half_height, step):
    screen.pen = shade_pen_lut[max(0, 200 - int(y * 5))]
    screen.rectangle(0, y + 60, 160, step)

column_distances = [0] * 160

@native
def draw_world(rays):
  global column_distances

  projection_distance = (screen.width / 2) / math.tan(player.fov / 2)

  for x in range(160):
    tile_pos = rays[x][0][2]
    offset = rays[x][0][4]
    distance = rays[x][0][5]

    column_distances[x] = distance

    # calculate height of wall span and y offset on screen
    height = projection_distance / distance
    y = int(60 - (height * 0.5))

    # u coordinate of texture is offset of ray intersection with tile
    u = offset

    # calculate how dark to shade this area, the rounding and multiplying
    # recreates the "banding" effect seen in the shading in DOOM
    shade = min(255, round(int(distance / 2.5)) * 20)

    tile = map.get_tile(tile_pos.x, tile_pos.y)

    # select texture and mipmap level
    tex = atlas[tile.texture_index][min(4, int(distance / 5))]

    # draw wall column and shading
    screen.blit_vspan(tex, x, y, height, u, 0, u, 1)
    screen.pen = shade_pen_lut[shade]
    screen.rectangle(x, y, 1, height)

@native
def draw_sprites():
  f = enemy.frame(io.ticks / 100)

  frustum_width = math.tan(player.fov * 0.5)
  player_dir = player.vector()
  plane = vec2(-player_dir.y * frustum_width, player_dir.x * frustum_width)
  inverse_determinant = 1.0 / (plane.x * player_dir.y - player_dir.x * plane.y)

  for pos in sprites:
    p = pos - player.pos # relative to player
    p = vec2(            # transform into camera space
      inverse_determinant * (player_dir.y * p.x - player_dir.x * p.y),
      inverse_determinant * (-plane.y * p.x + plane.x * p.y)
    )

    # sprite behind camera, skip
    if p.y <= 0:
      continue

    # calculate screen coordinates for sprite (width, height, x, y)
    sw = abs((int)(screen.height / p.y))
    sh = abs((int)(screen.height / p.y))
    sx = (int)((screen.width / 2) * (1 + p.x / p.y)) - (sw / 2)
    sy = -sh / 2 + screen.height / 2

    # blit the sprite in columns, checking for depth against world
    for x in range(sw):
      if (sx + x) < 0 or (sx + x) >= screen.width:
        continue

      if p.y >= column_distances[int(sx + x)]:
        continue

      u = x / sw
      screen.blit_vspan(f, sx + x, sy, sh, u, 0, u, 1)
