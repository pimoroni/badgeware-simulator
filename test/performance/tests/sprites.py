import math
from lib import *

sprites = SpriteSheet(f"assets/mona-dead.gif.png", 7, 1)


def run_test():
  screen.brush = brushes.color(20, 30, 40)
  screen.clear()

  screen.blit(sprites.sprite(2, 0), 20, 20)
  time.sleep(0.25)
