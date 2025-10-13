import math
from lib import *

portrait = Image.load(f"assets/portrait.png")

def run_test():
  screen.brush = brushes.color(20, 30, 40)
  screen.clear()

  screen.blit(portrait, 20, 20)
  time.sleep(0.25)
