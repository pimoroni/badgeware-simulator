import json
import math
from lib import *

font = Font.load("assets/MonaSans-Medium-Low.af")



test_phrase_size = 16
test_phrase = "Prow scuttle parrel provost Sail ho shrouds spirits boom mizzenmast yardarm. Pinnace holystone mizzenmast quarter crow's nest nipperkin grog yardarm hempen halter furl. Swab barque interloper chantey doubloon starboard grog black jack gangway rutters."
test_phrase_wrapped = wrap_and_measure(screen, test_phrase, test_phrase_size, 150)
def vector_font_test():
  lines = wrap_and_measure(screen, test_phrase, test_phrase_size, 150)
  
  overflow = test_phrase_size * len(lines) - 120 + 4
  y = math.sin(io.ticks / 1000) * (overflow / 2) - (overflow / 2)
  for line in lines:
    text, width = line
    screen.brush(brushes.color(0, 0, 0))
    screen.text(text, 5 + 1, y + 1, test_phrase_size)
    screen.brush(brushes.color(255, 255, 255))
    screen.text(text, 5, y, test_phrase_size)
    y += test_phrase_size

def vector_font_test_pre_wrap():
  overflow = test_phrase_size * len(test_phrase_wrapped) - 120 + 4
  y = math.sin(io.ticks / 1000) * (overflow / 2) - (overflow / 2)
  for line in test_phrase_wrapped:
    text, width = line
    screen.brush(brushes.color(0, 0, 0))
    screen.text(text, 5 + 1, y + 1, test_phrase_size)
    screen.brush(brushes.color(255, 255, 255))
    screen.text(text, 5, y, test_phrase_size)
    y += test_phrase_size

_samples = []
_sample_count = 100

def update(ticks):
  screen.antialias(2);

  # clear the screen
  screen.brush(brushes.color(30, 50, 70))
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  # run test and measure time taken
  start = time.ticks_us()
  #vector_font_test()
  vector_font_test_pre_wrap()
  end = time.ticks_us()

  # add sample to rolling samples
  global _samples, _sample_count
  _samples.append(end - start)
  if len(_samples) > _sample_count:
    _samples = _samples[-_sample_count:]

  # draw average FPS
  fps = round(1000000 / (sum(_samples) / float(len(_samples))))
  screen.font(font)
  width, height = screen.measure_text(f"{fps} FPS", 16)
  screen.brush(brushes.color(0, 0, 0))
  screen.draw(shapes.rectangle(0, 0, width + 4, height))
  screen.brush(brushes.color(255, 255, 255))  
  screen.text(f"{fps} FPS", 2, -3, 16)

  return True