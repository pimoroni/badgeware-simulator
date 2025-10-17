import math
from lib import *

screen.antialias = Image.X2

mona = Image.load("assets/mona.png")
large_font = PixelFont.load("../assets/fonts/ignore.ppf")
small_font = PixelFont.load("../assets/fonts/ark.ppf")

bold = [
  brushes.color(211, 250, 55),
  brushes.color(48, 148, 255),
  brushes.color(95, 237, 131),
  brushes.color(225, 46, 251),
  brushes.color(216, 189, 14),
  brushes.color(255, 128, 210)
]


def draw_status():
  screen.blit(mona, 0, 18)
  screen.font = small_font
  screen.brush = brushes.color(255, 255, 255)
  screen.text("mona's quest", 65, 0)

  screen.font = large_font
  screen.text("4/9", 5, 70)
  screen.font = small_font
  screen.brush = brushes.color(140, 160, 180)
  screen.text("tasks", 7, 94)
  screen.text("done", 10, 102)

def draw_tiles():
  screen.font = large_font
  pos = (68, 31)
  for y in range(0, 3):
    for x in range(0, 3):
      v = (math.sin(io.ticks / 250 + (x + y)) / 2) + 0.5
      b = 0.5 + (v / 2)

      border_brush = brushes.color(255 * (1.5 - b), 128 * (1.5 - b), 210 * (1.5 - b))
      text_brush = brushes.color(225 * b, 128 * b, 210 * b)

      index = x + (y * 3)
      xo = x * 34
      yo = y * 34
      tile = shapes.squircle(0, 0, 1, 6)
      w, h = screen.measure_text(str(index))
      label_pos = (xo + pos[0] - (w / 2) + 1, yo + pos[1] - (h / 2) - 1)

      if index in [0, 4, 7, 8]:
        screen.brush = bold[index % 6]
        tile.transform = Matrix().translate(*pos).translate(xo, yo).scale(16)
        screen.draw(tile)

        screen.brush = brushes.color(0, 0, 0, 150)
        screen.text(str(index), *label_pos)
      else:
        tile.transform = Matrix().translate(*pos).translate(xo, yo).scale(16)
        screen.brush = border_brush
        screen.draw(tile)
        screen.brush = brushes.color(35, 41, 37)
        tile.transform = Matrix().translate(*pos).translate(xo, yo).scale(14)
        screen.draw(tile)
        screen.brush = text_brush
        screen.text(str(index), *label_pos)
