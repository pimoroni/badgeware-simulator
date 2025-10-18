import math
import random
from lib import *
import icon
import ui

# define the list of installed apps
#
# - hack them!
# - replace them with your own
# - reorder them
# - what would mona do...?
apps = [
  ("mona's quest", "quest"),
  ("mona pet", "monagotchi"),
  ("flappy mona", "flappy"),
  ("gallery", "gallery"),
  ("monasketch", "sketch"),
  ("badge", "badge")
]

mona = SpriteSheet(f"../assets/mona-sprites/mona-default.png", 11, 1)
screen.font = PixelFont.load("../assets/fonts/ark.ppf")
#screen.antialias = Image.X2

# find installed apps and create icons
icons = []
for app in apps:
  name, path = app[0], app[1]

  if is_dir(f"../{path}"):
    if file_exists(f"../{path}/icon.png"):
      x = len(icons) % 3
      y = math.floor(len(icons) / 3)
      pos = (x * 48 + 33, y * 48 + 42)
      sprite = Image.load(f"../{path}/icon.png")
      icons.append(icon.Icon(pos, name, len(icons), sprite))

active = 0
def update():
  global active, icons

  # process button inputs to switch between icons
  if io.BUTTON_C in io.pressed:
    active += 1
  if io.BUTTON_A in io.pressed:
    active -= 1
  if io.BUTTON_UP in io.pressed:
    active -= 3
  if io.BUTTON_DOWN in io.pressed:
    active += 3
  active %= len(icons) #

  ui.draw_background()
  ui.draw_header()

  # draw menu icons
  for i in range(0, len(icons)):
    icon = icons[i]
    icon.activate(active == i)
    icon.draw()

  # draw label for active menu icon
  for i in range(0, len(icons)):
    if i == active:
      label = f"{icons[i].name}"
      w, _ = screen.measure_text(label)
      screen.brush = brushes.color(211, 250, 55)
      screen.draw(shapes.rounded_rectangle(80 - (w / 2) - 4, 100, w + 8, 15, 4))
      screen.brush = brushes.color(0, 0, 0, 150)
      screen.text(label, 80 - (w / 2), 101)
