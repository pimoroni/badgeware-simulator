import json
import math
from lib import *

#splash1_00000


_last_frame = None

def update(ticks):
  global _last_frame

  frame = round(ticks / 50)
  frame %= 47

  if frame != _last_frame:
    filename = f"frames/splash1_{frame:05d}.png"
    image = Image.load(filename)
    screen.blit(image, 0, 0)

  _last_frame = frame

  return True