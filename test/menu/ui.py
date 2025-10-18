import math
import random
from lib import *

black = brushes.color(0, 0, 0)
background = brushes.color(35, 41, 37)
phosphor = brushes.color(211, 250, 55)
phosphor_glow = brushes.color(211, 250, 55, 20)

def draw_background():
  screen.brush = black
  screen.draw(shapes.rectangle(0, 0, 10, 10))
  screen.draw(shapes.rectangle(150, 0, 10, 10))
  screen.draw(shapes.rectangle(0, 0, 110, 10))
  screen.draw(shapes.rectangle(150, 0, 110, 10))

  screen.brush = background
  screen.draw(shapes.rounded_rectangle(0, 0, 160, 120, 8))

  draw_terminal()

terminal = []
for i in range(0, 25):
  terminal.append(random.randint(20, 100))
last_terminal_line_added = None
added_terminal_lines = 0

def draw_terminal():
  global last_terminal_line_added, terminal, added_terminal_lines
  new_line_speed = 250
  if not last_terminal_line_added or io.ticks - last_terminal_line_added > new_line_speed:
    terminal = terminal[1:]
    random.seed(io.ticks)
    terminal.append(random.randint(0, 100))
    last_terminal_line_added = io.ticks
    added_terminal_lines += 1

  screen.brush = brushes.color(211 / 3.5, 250 / 3.5, 55 / 3.5)
  for i in range(0, 25):
    y = 20 + i * 5
    yo = ((io.ticks - last_terminal_line_added) / new_line_speed) * 5
    y = int(y - yo)

    random.seed(i + added_terminal_lines)
    cx = 0
    while cx < terminal[i]:
      w = random.randint(3, 10)
      screen.draw(shapes.rectangle(cx + 6, y, w, 2))
      cx += w + 2

  screen.brush = brushes.color(35, 41, 37, 100)
  screen.draw(shapes.rectangle(0, 15, 160, 5))
  screen.draw(shapes.rectangle(0, 15, 160, 3))
  screen.draw(shapes.rectangle(0, 15, 160, 1))

def draw_header():
  # create animated header text
  dots = "." * int(math.sin(io.ticks / 250) * 2 + 2)
  label = f"Mona-OS v4.03{dots}"
  pos = (5, 2)

  # fake a bit of phosphor glow
  screen.brush = phosphor_glow
  for y in range(-1, 2):
    for x in range(-1, 2):
      screen.text(label, pos[0] + x, pos[1] + y)

  # draw the OS title
  screen.brush = phosphor
  screen.text(label, *pos)

  # draw the battery indicator
  battery_level = 100
  pos = (137, 4)
  size = (16, 8)
  screen.brush = phosphor_glow
  for y in range(-1, 2):
    for x in range(-1, 2):
      screen.draw(shapes.rectangle(pos[0] + x, pos[1] + y, *size))
  screen.brush = phosphor
  screen.draw(shapes.rectangle(*pos, *size))
  screen.draw(shapes.rectangle(pos[0] + size[0], pos[1] + 2, 2, 4))
  screen.brush = background
  screen.draw(shapes.rectangle(pos[0] + 1, pos[1] + 1, size[0] - 2, size[1] - 2))

  # draw the battery fill level
  width = ((size[0] - 4) / 100) * battery_level
  screen.brush = phosphor
  screen.draw(shapes.rectangle(pos[0] + 2, pos[1] + 2, width, size[1] - 4))

