import math
from lib import *

sprites = SpriteSheet(f"/assets/mona-sprites/mona-dance.png", 6, 1)


def run_test():
  screen.brush = brushes.color(20, 30, 40)
  screen.clear()

  screen.blit(sprites.sprite(4, 0), 20, 20)
  h = math.sin(io.ticks / 1000) * 50
  screen.scale_blit(sprites.sprite(4, 0), 20, 60, 60, h)

  screen.scale_blit(sprites.sprite(4, 0), 100, 60, h, 40)
