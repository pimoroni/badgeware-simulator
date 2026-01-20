from picovector import algorithm
import math

size = 2

class Player:
  def __init__(self):
    self.pos = vec2(8, 8)
    self.angle = 0
    self.fov = 100

  def set_angle(self, angle):
    self.angle = angle

  def vector(self, offset=0, length=1):
    return vec2(
      math.cos((self.angle + offset) * (math.pi / 180)) * length,
      math.sin((self.angle + offset) * (math.pi / 180)) * length
    )

world_map = [
  [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
  [1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
  [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
]
MAP_SIZE_X = len(world_map[0])
MAP_SIZE_Y = len(world_map)
world_map_flags = bytearray(MAP_SIZE_X * MAP_SIZE_Y)

for y in range(MAP_SIZE_Y):
    for x in range(MAP_SIZE_X):
        world_map_flags[y * MAP_SIZE_X + x] = world_map[y][x]

def gtos(p):
  return vec2(
    80 + math.floor((p.x - player.pos.x) * size),
    60 + math.floor((p.y - player.pos.y) * size),
  )

def gtom(p):
  return vec2(
    160 - (size * 22) + math.floor(p.x * size),
    120 - (size * 16) + math.floor(p.y * size),
  )

def point_add(p1, p2):
  return vec2(
    p1.x + p2.x,
    p1.y + p2.y
  )

def map_value(x, y):
  x = int(x)
  y = int(y)
  if 0 <= x < len(world_map[0]) and 0 <= y < len(world_map):
    return world_map[y][x]
  return 1

intersection = None
intersection_distance = None
def dda_cb(step, ip, ig, edge, offset, distance):
  global intersection, intersection_distance
  mv = map_value(ig.x, ig.y)

  if mv == 1:
    sip = gtom(ip)
    screen.pen = color.rgb(255, 255, 255, b)
    screen.put(sip)
    intersection = ip
    intersection_distance = distance

    b = 255 - (int(distance) * 10)
    screen.pen = color.rgb(255, 255, 255, b)
    screen.put(sip)

  return map_value(ig.x, ig.y) == 0

player = Player()

def update():
  global player, intersection_distance
  screen.clear(color.rgb(20, 40, 60))

  player.pos = vec2(
    math.sin(io.ticks / 2000) * 2 + 11,
    math.cos(io.ticks / 2000) * 2 + 8
  )
  player.set_angle(io.ticks / 30)






  # draw player position
  pen(255, 255, 255)
  screen.circle(gtom(player.pos), 2)

  pen(255, 255, 255, 100)
  screen.line(gtom(player.pos), gtom(player.pos + player.vector(offset = -player.fov / 2, length=5)))
  screen.line(gtom(player.pos), gtom(player.pos + player.vector(offset = player.fov / 2, length=5)))


  pen(100, 100, 100, 100)
  for x in range(0, len(world_map[0])):
    for y in range(0, len(world_map)):
      sp = gtom(vec2(x, y))
      if map_value(x, y) == 1:
        screen.rectangle(sp.x, sp.y, size, size)

  # cast rays for player sight
  # for fova in range(-player.fov / 2, player.fov / 2):
  #   algorithm.dda(player.pos, player.vector(offset = fova), dda_cb)
  d_proj = (screen.width / 2) / math.tan(player.fov * (math.pi / 180) / 2)

  result = algorithm.dda(player.pos, player.angle, player.fov, 160, 20, world_map_flags, MAP_SIZE_X, MAP_SIZE_Y)

  for i in range(0, 160):
    ray = result[i]
    for entry in ray:
      step = entry[0]
      ip = entry[1]
      gp = entry[2]
      mv = map_value(gp.x, gp.y)

      if mv == 1:
        distance = entry[5]
        height = (2 / distance) * d_proj

        b = distance * 10
        screen.pen = color.rgb(255 - b, 255 - b, 255 - b)

        screen.rectangle(i, 60 - (height / 2), 1, height)

        # screen.pen = color.rgb(255, 255, 255)
        # sip = gtom(ip)
        # screen.pen = color.rgb(255, 255, 255, b)
        # screen.put(sip)

        break

