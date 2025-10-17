import math
import random
from lib import *
from obstacle import *

sprites = SpriteSheet(f"assets/mona.png", 7, 2)
alive = sprites.animation(0, 0, 7)
dead = sprites.animation(0, 1, 5)

class Mona:
  def __init__(self):
    self.pos = (10, 50)
    self.score = 0
    self.velocity = 0
    self.gravity = 9.88
    self.last_update = None
    self.died_at = None
    self.done_dying = False

  def update(self):
    if self.is_dead():
      return

    if self.last_update:
      td = (io.ticks - self.last_update) / 1000
      self.velocity = self.velocity + (self.gravity * td)
      self.pos = (self.pos[0], self.pos[1] + self.velocity)

      if self.pos[1] > 92:
        self.die()

      if self.pos[1] <= 0:
        self.pos = (self.pos[0], 0)
        self.velocity = 0

    self.last_update = io.ticks

    # check if we've passed or hit any obstacles
    mb = self.bounds()
    for obstacle in Obstacle.obstacles:
      for ob in obstacle.bounds():
        x1 = max(ob[0], mb[0])
        y1 = max(ob[1], mb[1])
        x2 = min(ob[0] + ob[2], mb[0] + mb[2])
        y2 = min(ob[1] + ob[3], mb[1] + mb[3])

        collided = x1 < x2 and y1 < y2

        if collided:
          self.die()

      if obstacle.passed == False:
        if obstacle.x < self.pos[0]:
          obstacle.passed = True
          self.score += 1

  def is_dead(self):
    return self.died_at != None

  def is_done_dying(self):
    return (io.ticks - self.died_at) > 1500

  def die(self):
    if not self.died_at:
      self.died_at = io.ticks

  def jump(self):
    self.velocity = -2.5

  def bounds(self):
    # be a little generous with monas bounding box for collisions
    return (self.pos[0] + 3, self.pos[1] + 2, 18, 20)

  def draw(self):
    if not self.is_dead():
      # this is a bit gnarly but basically we want to convert mona's currently
      # velocity into the correct animation frame for her motion.
      frame = max(-1, min(self.velocity, 2)) + 1 # clamp velocity to between 0 and 3

      # monas animation frames are ordered from flying to falling, so scale the
      # clamped velocity to the 0...7 sprites that represent her
      frame = int(frame * 2)
      sprite = alive.frame(int(frame))
      screen.blit(sprite, self.pos[0], self.pos[1])
    else:
      frame = (io.ticks - self.died_at) / 100
      if frame < dead.count():
        sprite = dead.frame(frame)
        screen.blit(sprite, self.pos[0], self.pos[1])

    # draw monas bounding box for debugging
    # screen.brush = brushes.color(255, 0, 0, 50)
    # screen.draw(shapes.rectangle(*self.bounds()))
