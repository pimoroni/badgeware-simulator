import json
import math
from lib import *

font = PixelFont.load("../assets/fonts/sins.ppf")

test = "sprites"

test_module = __import__(f"tests/{test}")

_samples = []
_sample_count = 50
def update():
  # clear the screen
  screen.brush = brushes.color(30, 50, 70)
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  # run test and measure time taken
  start = time.ticks_us()
  test_module.run_test()
  end = time.ticks_us()

  # add sample to rolling samples
  global _samples, _sample_count
  _samples.append(end - start)
  if len(_samples) > _sample_count:
    _samples = _samples[-_sample_count:]

  # draw average FPS
  fps = round(1000000 / max(1, (sum(_samples) / float(len(_samples)))))
  screen.font = font
  width, height = screen.measure_text(f"{fps}FPS", 16)
  width = int(width + 4)
  height = int(height - 1)
  screen.brush = brushes.color(155, 0, 0)
  screen.draw(shapes.rectangle(screen.width - width, 0, width, height))
  screen.brush = brushes.color(255, 255, 255)
  screen.text(f"{fps}FPS", screen.width - width + 1, -1, 16)

  return True