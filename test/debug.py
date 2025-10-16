import json
import math
from lib import *
import gc

# font = Font.load("assets/MonaSans-Medium-Low.af")
# screen.font = font
# screen.antialias = Image.X4


_update_rate = 0.5 # update every half second
_mem_samples = []
_tick_samples = []
_sample_count = 20

_last_ticks_us = 0
def update():
  global _last_ticks_us, _mem_samples, _tick_samples

  ticks_us = time.ticks_us()

  if ((ticks_us - _last_ticks_us) / 1000 / 1000) > _update_rate:
    # add new memory usage sample
    gc.collect()
    _mem_samples.append(gc.mem_free())
    if len(_mem_samples) > _sample_count:
      _mem_samples = _mem_samples[-_sample_count:]

    # add new timing sample
    _tick_samples.append(ticks_us - _last_ticks_us)
    _last_ticks_us = ticks_us

  # render fps chart
  screen.brush = brushes.color(0, 0, 0, 150)
  screen.draw(shapes.rectangle(00, 0, 20, 10))
  screen.brush = brushes.color(0, 255, 0, 150)
  for i in range(0, min(len(_mem_samples), 20)):
    height = (_tick_samples[i] / 1000000) * 10
    screen.draw(shapes.rectangle(i, 10 - height, 1, height))

  # render memory use chart
  screen.brush = brushes.color(0, 0, 0, 150)
  screen.draw(shapes.rectangle(21, 0, 20, 10))
  screen.brush = brushes.color(0, 0, 255, 150)
  for i in range(0, min(len(_mem_samples), 20)):
    height = (_mem_samples[i] / 250000) * 10
    screen.draw(shapes.rectangle(i + 21, 10 - height, 1, height))


  #screen.brush = brushes.color(255, 255, 255)
  #screen.text(f"{fps} FPS", 2, -3, 16)

  return True