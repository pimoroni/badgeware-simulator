import math
import random
from lib import *
import icon


mona = SpriteSheet(f"../assets/mona-sprites/mona-default.png", 11, 1)
screen.font = PixelFont.load("../assets/fonts/ark.ppf")
screen.antialias = Image.X2

# find installed apps and create icons
icons = []
for path in os.listdir(".."):
  if is_dir(f"../{path}"):
    if file_exists(f"../{path}/icon.png"):
      x = len(icons) % 3
      y = math.floor(len(icons) / 3)
      pos = (x * 48 + 33, y * 48 + 42)
      sprite = Image.load(f"../{path}/icon.png")
      icons.append(icon.Icon(pos, len(icons), sprite, path))

terminal = []
for i in range(0, 25):
  terminal.append(random.randint(20, 100))
last_terminal_line_added = None
added_terminal_lines = 0

active = 0
def update():
  global active, icons, terminal, last_terminal_line_added, added_terminal_lines
  screen.brush = brushes.color(0, 0, 0)
  screen.draw(shapes.rectangle(0, 0, 160, 120))
  screen.brush = brushes.color(35, 41, 37)
  screen.draw(shapes.rounded_rectangle(0, 0, 160, 120, 8))

  if io.BUTTON_C in io.pressed:
    active += 1

  if io.BUTTON_A in io.pressed:
    active -= 1

  if io.BUTTON_UP in io.pressed:
    active -= 3

  if io.BUTTON_DOWN in io.pressed:
    active += 3

  active %= len(icons)

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

  for i in range(0, len(icons)):
    icon = icons[i]
    icon.activate(active == i)
    icon.draw()

  for i in range(0, len(icons)):
    if i == active:
      w, _ = screen.measure_text(icons[i].name)
      screen.brush = brushes.color(211, 250, 55, 75)
      screen.draw(shapes.rounded_rectangle(80 - (w / 2) - 4, 100, w + 8, 15, 4))
      screen.brush = brushes.color(255, 255, 255)
      screen.text(icons[i].name, 80 - (w / 2), 101)


  draw_header()


def draw_header():
  # create animated header text
  dots = "." * int(math.sin(io.ticks / 250) * 2 + 2)
  label = f"Mona-OS v4.03{dots}"
  pos = (5, 2)

  # fake a bit of phosphor glow
  screen.brush = brushes.color(211, 250, 55, 20)
  for y in range(-1, 2):
    for x in range(-1, 2):
      screen.text(label, pos[0] + x, pos[1] + y)

  # draw the OS title
  screen.brush = brushes.color(211, 250, 55)
  screen.text(label, *pos)

  battery_level = 40
  pos = (137, 4)
  size = (16, 8)

  screen.brush = brushes.color(211, 250, 55, 20)
  for y in range(-1, 2):
    for x in range(-1, 2):
      screen.draw(shapes.rectangle(pos[0] + x, pos[1] + y, *size))
  screen.brush = brushes.color(211, 250, 55, 200)
  screen.draw(shapes.rectangle(*pos, *size))
  screen.draw(shapes.rectangle(pos[0] + size[0], pos[1] + 2, 2, 4))
  screen.brush = brushes.color(35, 41, 37)
  screen.draw(shapes.rectangle(pos[0] + 1, pos[1] + 1, size[0] - 2, size[1] - 2))

  # draw the battery fill level
  width = (16 / 100) * battery_level
  screen.brush = brushes.color(211, 250, 55, 150)
  screen.draw(shapes.rectangle(pos[0] + 2, pos[1] + 2, width, size[1] - 4))






