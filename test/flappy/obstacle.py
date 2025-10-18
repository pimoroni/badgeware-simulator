import math
import random
from lib import *

sprites = SpriteSheet(f"assets/obstacles.png", 2, 1)

class Obstacle:
  obstacles = []
  next_spawn_time = None

  def spawn():
    Obstacle.obstacles.append(Obstacle())
    Obstacle.next_spawn_time = io.ticks + 2000

    # clean up any obstacles that are now off screen and can be removed
    Obstacle.obstacles = [o for o in Obstacle.obstacles if o.x > -24]

  def __init__(self):
    self.x = screen.width
    self.gap_height = 60
    self.gap_y = random.randint(15, screen.height - self.gap_height - 15)
    self.passed = False

  def update(self):
    self.x -= 1

  def bounds(self):
    # be a little generous with obstacle bounding boxes for collisions
    return (
      (self.x, 0, 24, self.gap_y - 2),
      (self.x, self.gap_y + self.gap_height + 2, 24, 120 - self.gap_y + self.gap_height - 2)
    )

  def draw(self):
    screen.scale_blit(sprites.sprite(0, 0), self.x, self.gap_y - 72, 24, 24)
    screen.scale_blit(sprites.sprite(0, 0), self.x, self.gap_y - 48, 24, 24)
    screen.scale_blit(sprites.sprite(1, 0), self.x, self.gap_y - 24, 24, 24)

    screen.scale_blit(sprites.sprite(1, 0), self.x, self.gap_y + self.gap_height, 24, -24)
    screen.scale_blit(sprites.sprite(0, 0), self.x, self.gap_y + self.gap_height + 24, 24, -24)
    screen.scale_blit(sprites.sprite(0, 0), self.x, self.gap_y + self.gap_height + 48, 24, -24)

    # draw monas bounding box for debugging
    # screen.brush = brushes.color(0, 255, 0, 50)
    # screen.draw(shapes.rectangle(*self.bounds()[0]))
    # screen.draw(shapes.rectangle(*self.bounds()[1]))