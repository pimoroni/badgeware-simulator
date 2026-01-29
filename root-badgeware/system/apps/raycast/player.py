import math

class Player:
  def __init__(self, pos, angle, map, fov=80):
    self.pos = pos
    self.angle = angle * math.pi / 180
    self.fov = fov * math.pi / 180
    self.map = map

  def turn_to(self, angle):
    self.angle = angle * math.pi / 180

  def turn_by(self, amount):
    self.angle += amount * math.pi / 180

  def move_by(self, v):
    radius = 0.25
    nx = self.pos.x + v.x
    if not self.map.get_tile(nx + radius, self.pos.y).solid and \
       not self.map.get_tile(nx - radius, self.pos.y).solid:
      self.pos.x = nx

    ny = self.pos.y + v.y
    if not self.map.get_tile(self.pos.x, ny + radius).solid and \
       not self.map.get_tile(self.pos.x, ny - radius).solid:
      self.pos.y = ny

  def process_inputs(self):
    # scale movement based on last frame time
    scale = io.ticks_delta / 1000

    turn_speed = 160 * scale # 160 degrees per second
    walk_speed = 5 * scale # 5 world units per second

    if io.BUTTON_A in io.held:
      self.turn_by(-turn_speed)

    if io.BUTTON_C in io.held:
      self.turn_by(turn_speed)

    if io.BUTTON_UP in io.held:
      self.move_by(self.vector() * walk_speed)

    if io.BUTTON_DOWN in io.held:
      self.move_by(self.vector() * -walk_speed)

  # return a unit vector representing the players viewing direction
  def vector(self):
    return vec2(math.cos(self.angle), math.sin(self.angle))