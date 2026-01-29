from picovector import algorithm
import math
import time
from map import Map
from player import Player
from texture import atlas, load_texture
import micropython

def _noop(fn):
    return fn

mode(DIRTY)

native = getattr(micropython, "native", _noop)
viper  = getattr(micropython, "viper",  _noop)

enemy = SpriteSheet("assets/PlayerWalk 48x48.png", 8, 1).animation(0, 0, 8)
sky_texture = image.load("assets/sky.png")

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
      map.set_tile(x, y, 0b10000000, 128)

    if v == "z":
      map.set_tile(x, y, 0b10000000, 130)

    if v == "@":
      player_start_pos = vec2(x + 0.5, y + 0.5)

    if v == "!":
      sprites.append(vec2(x + 0.5, y + 0.5))

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
  rays = algorithm.raycast(player.pos, player.angle, player.fov, 160, 100, map.flags, map.width, map.height, screen.width)
  raycast_time = time.ticks_ms() - start

  start = time.ticks_ms()
  draw_world(rays)
  draw_world_time = time.ticks_ms() - start

  start = time.ticks_ms()
  draw_sprites()
  draw_sprites_time = time.ticks_ms() - start

  frame_end = time.ticks_ms()
  frame_duration = max(1, frame_end - frame_start)

  # draw timing stats
  screen.pen = color.yellow
  screen.text(f"raycast: {raycast_time}ms", 2, 85)
  screen.text(f"sky: {draw_sky_time}ms", 2, 95)
  screen.text(f"floor: {draw_floor_time}ms", 2, 105)
  screen.text(f"world: {draw_world_time}ms", 82, 85)
  screen.text(f"sprites: {draw_sprites_time}ms", 82, 95)
  screen.pen = color.white
  screen.text(f"total: {frame_duration}ms", 82, 105)

  # draw fps counter
  ticks = max(1, io.ticks_delta)
  frame_times.append(ticks)
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
  frustrum_left_x = player_dir.x - plane.x
  frustrum_left_y = player_dir.y - plane.y
  frustrum_right_x = player_dir.x + plane.x
  frustrum_right_y = player_dir.y + plane.y

  screen_height = screen.height
  blit_hspan = screen.blit_hspan

  for y in range(half_height + 1, screen_height):
    # distance in world coordinates to this row on screen
    distance = camera_height / (y - half_height)

    # floor left and right coordinates in world space for this row
    floor_left_x = player.pos.x + distance * frustrum_left_x
    floor_left_y = player.pos.y + distance * frustrum_left_y

    floor_right_x = player.pos.x + distance * frustrum_right_x
    floor_right_y = player.pos.y + distance * frustrum_right_y

    # select correct texture and mipmap level
    tex_id = int(distance / 4)
    if tex_id > 4: tex_id = 4
    tex = atlas[2][tex_id]

    blit_hspan(tex, 0, y, 160, floor_left_x, floor_left_y, floor_right_x, floor_right_y)

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

  textures = map.textures
  map_width = map.width
  blit_vspan = screen.blit_vspan
  rectangle = screen.rectangle

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

    texture = textures[int(tile_pos.y) * map_width + int(tile_pos.x)]

    # select texture and mipmap level
    mipmap = int(distance / 5)
    if mipmap > 4: mipmap = 4
    tex = atlas[texture][mipmap]

    # draw wall column and shading
    blit_vspan(tex, x, y, height, u, 0, u, 1)

    # calculate how dark to shade this area, the rounding and multiplying
    # recreates the "banding" effect seen in the shading in DOOM
    shade = round(int(distance / 2.5) * 20)

    if shade > 255: shade = 255
    screen.pen = shade_pen_lut[shade]
    rectangle(x, y, 1, height)

@native
def draw_sprites():
  f = enemy.frame(io.ticks / 100)

  frustum_width = math.tan(player.fov * 0.5)
  player_dir = player.vector()
  plane = vec2(-player_dir.y * frustum_width, player_dir.x * frustum_width)
  inverse_determinant = 1.0 / (plane.x * player_dir.y - player_dir.x * plane.y)

  screen_width = screen.width
  screen_height = screen.height

  blit_vspan = screen.blit_vspan

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
    sw = abs((int)(screen_height / p.y))
    sh = sw # abs((int)(screen_height / p.y))
    sx = (int)((screen_width / 2) * (1 + p.x / p.y)) - (sw / 2)
    sy = -sh / 2 + screen_height / 2

    # blit the sprite in columns, checking for depth against world
    for x in range(sw):
      if (sx + x) < 0 or (sx + x) >= screen_width:
        continue

      if p.y >= column_distances[int(sx + x)]:
        continue

      u = x / sw
      blit_vspan(f, sx + x, sy, sh, u, 0, u, 1)
