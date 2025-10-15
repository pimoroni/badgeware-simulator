import math
from lib import *

canvas = Image(0, 0, 160, 120)
font = PixelFont.load("assets/nope.ppf")

def update():
  print("--------------------------------------------")
  screen.brush = brushes.color(20, 40, 60)
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  screen.brush = brushes.color(255, 40, 60)
  screen.font = font
  screen.text("test", 0, 0)

  time.sleep(1)
  return True