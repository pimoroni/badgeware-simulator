import math
from lib import *

test_phrase_size = 16
test_phrase = "Prow scuttle parrel provost Sail ho shrouds spirits boom mizzenmast yardarm. Pinnace holystone mizzenmast quarter crow's nest nipperkin grog yardarm hempen halter furl. Swab barque interloper chantey doubloon starboard grog black jack gangway rutters."
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

test_phrase_wrapped = wrap_and_measure(screen, test_phrase, test_phrase_size, 150)
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

def run_test():
  vector_font_test()