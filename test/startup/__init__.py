import json
import math
from lib import *

animate_over = 2
wait_over = 3
fade_over = 2

loaded_frame_filename = None
loaded_frame = None

def update(ticks):
  global loaded_frame, loaded_frame_filename

  ticks %= int(((animate_over + wait_over + fade_over) * 1000))
  time = ticks / 1000

  if time < animate_over:
    frame = round((time / animate_over) * 46)
    filename = f"frames/splash1_{frame:05d}.png"
    if loaded_frame_filename != filename:      
      loaded_frame = Image.load(filename)
      loaded_frame_filename = filename
      screen.blit(loaded_frame, 0, 0)
  elif time < animate_over + wait_over:
    pass # do nothing, just pause on final frame
  else:
    screen.brush(brushes.color(0, 0, 0))
    screen.draw(shapes.rectangle(0, 0, 160, 120))
    alpha = int(255 * ((time - animate_over - wait_over) / fade_over))
    loaded_frame.alpha(255 - alpha)
    screen.blit(loaded_frame, 0, 0)
  
  return True