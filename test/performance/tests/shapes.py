import math
from lib import *

def run_test():
  
  
  size = math.sin(io.ticks / 1000)
  rect = shapes.rectangle(50, 30, 60, 60)
  test = screen.transform
  print(test)
  x = math.sin(io.ticks / 1000) * 10
  y = math.cos(io.ticks / 1000) * 10
  screen.transform = Matrix().translate(x, y)
  rect.transform = Matrix().translate(80, 60).rotate(io.ticks / 10).scale(size).translate(-80, -60)

  screen.brush(brushes.color(255, 0, 0))
  screen.draw(rect)
