import math
from lib import *

# test_phrase_size = 16
# test_phrase = "Prow scuttle parrel provost Sail ho shrouds spirits boom mizzenmast yardarm. Pinnace holystone mizzenmast quarter crow's nest nipperkin grog yardarm hempen halter furl. Swab barque interloper chantey doubloon starboard grog black jack gangway rutters."
# def vector_font_test():
#   lines = wrap_and_measure(screen, test_phrase, test_phrase_size, 150)

#   overflow = test_phrase_size * len(lines) - 120 + 4
#   y = math.sin(io.ticks / 1000) * (overflow / 2) - (overflow / 2)
#   for line in lines:
#     text, width = line
#     screen.brush = brushes.color(0, 0, 0)
#     screen.text(text, 5 + 1, y + 1, test_phrase_size)
#     screen.brush = brushes.color(255, 255, 255)
#     screen.text(text, 5, y, test_phrase_size)
#     screen.brush = brushes.color(255, 255, 255, 100)

#     screen.draw(shapes.line(5, y, width, y, 1))
#     y += test_phrase_size

# test_phrase_wrapped = wrap_and_measure(screen, test_phrase, test_phrase_size, 150)
# def vector_font_test_pre_wrap():
#   overflow = test_phrase_size * len(test_phrase_wrapped) - 120 + 4
#   y = math.sin(io.ticks / 1000) * (overflow / 2) - (overflow / 2)
#   for line in test_phrase_wrapped:
#     text, width = line
#     screen.brush = brushes.color(0, 0, 0)
#     screen.text(text, 5 + 1, y + 1, test_phrase_size)
#     screen.brush = brushes.color(255, 255, 255)
#     screen.text(text, 5, y, test_phrase_size)
#     y += test_phrase_size

pixel_fonts = {
  "bacteria": PixelFont.load("assets/bacteria.ppf"),
  "nope": PixelFont.load("assets/nope.ppf"),
  "vest": PixelFont.load("assets/vest.ppf"),
  "sins": PixelFont.load("assets/sins.ppf"),
  "ignore": PixelFont.load("assets/ignore.ppf"),
}

phrase = "Prow scuttle parrel provost Sail ho shrouds spirits boom mizzenmast yardarm. Pinnace holystone mizzenmast quarter crow's nest nipperkin grog yardarm hempen halter furl. Swab barque interloper chantey doubloon starboard grog black jack gangway rutters."

def run_test():
  i = round(io.ticks / 1000) % len(pixel_fonts)
  name = list(pixel_fonts.keys())[i]

  max_width = math.sin(io.ticks / 1000) * 50 + 100

  screen.brush = brushes.color(0, 0, 0, 100)
  screen.draw(shapes.rectangle(0, 0, max_width, 120))
  screen.font = pixel_fonts[name]
  screen.brush = brushes.color(255, 255, 255)
  print(screen.font.name)

  lines = wrap_and_measure(screen, phrase, 1, max_width=max_width)
  x = 0
  y = 0
  for line in lines:
    text, width = line
    screen.text(text, x, y)
    y += int(screen.font.height * 0.9)
