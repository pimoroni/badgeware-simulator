import math
import random
from lib import *

sprites = SpriteSheet(f"assets/sprites.png", 7, 2)

class Mona:
  def __init__(self):
    self.pos = (10, 50)
    self.velocity = 0
    self.gravity = 9.88
    self.last_update = None

  def update(self):
    if self.last_update:
      td = (io.ticks - self.last_update) / 1000
      self.velocity = self.velocity + (self.gravity * td)
      self.pos = (self.pos[0], self.pos[1] + self.velocity)

      if self.pos[1] > 80:
        self.pos = (self.pos[0], 80)
        self.velocity = 0

      if self.pos[1] <= 0:
        self.pos = (self.pos[0], 0)
        self.velocity = 0

    self.last_update = io.ticks

  def jump(self):
    self.velocity = -2.5

  def draw(self):
    screen.blit(sprites.sprite(0, 0), self.pos[0], self.pos[1])

  def bounds(self):
    pass