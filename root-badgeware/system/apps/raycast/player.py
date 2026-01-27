import math

class Player:
  def __init__(self, pos, angle, fov=80):
    self.pos = pos
    self.angle = angle
    self.fov = fov

  def set_angle(self, angle):
    self.angle = angle

  def angle_radians(self):
    return self.angle * math.pi / 180

  def vector(self):
    return vec2(
      math.cos((self.angle) * (math.pi / 180)),
      math.sin((self.angle) * (math.pi / 180))
    )