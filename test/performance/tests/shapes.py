import math
from lib import *

def run_test():
  
  rect = shapes.rectangle(50, 30, 60, 60)
  rect.transform = rect.transform.translate(80, 60).rotate(io.ticks / 10).translate(-80, -60)

  screen.brush(brushes.color(255, 0, 0))
  screen.draw(rect)
