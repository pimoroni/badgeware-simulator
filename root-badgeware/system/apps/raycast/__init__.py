from picovector import algorithm
import math
from map import Map
from player import Player

wall_sprite = image.load("assets/CONCRETE_4C_SMALL.PNG")
size = 2

# grotty way to quickly define the map as a string to make it easy to edit
world_map = """
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
X       X                      X
XXXXXXX X                      X
X       X                      X
X       X                      X
X                              X
X       X                      X
XXXXXXXXX                      X
X                              X
X                              X
X                              X
X                              X
X                              X
X                              X
X                              X
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

def update():
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

  d_proj = (screen.width / 2) / math.tan(deg2rad(player.fov) / 2)
  wall_height = 1

  for i in range(0, 160):
    ray = result[i]
    for entry in ray:
      gp = entry[2]
      offset = entry[4]
      ray_angle = entry[6]
      mv = map.get_tile(int(gp.x), int(gp.y))

      if not mv:
        continue

      if mv.solid:
        distance = entry[5]
        if distance <= 0: break

        perp_distance = distance * math.cos(ray_angle - deg2rad(player.angle))
        perp_distance = max(perp_distance, 0.0001)
        height = (wall_height * d_proj) / perp_distance

        sxy = vec2(i, 60 - (height / 2))
        uv1 = vec2(int(offset * wall_sprite.width), 0)
        uv2 = vec2(int(offset * wall_sprite.width), wall_sprite.height - 1)

        screen.blit_vspan(wall_sprite, sxy, height, uv1, uv2)

        b = distance * 10
        b = int(max(0, min(255, b)))
        screen.alpha = b
        screen.pen = color.rgb(20, 40, 60)
        screen.rectangle(sxy.x, sxy.y, 1, height)
        screen.alpha = 255
        # wall_sprite.alpha = 255 - b


        break