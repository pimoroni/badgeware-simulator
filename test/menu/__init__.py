import math
from lib import *

mona = SpriteSheet(f"../assets/mona-sprites/mona-default.png", 11, 1)
screen.font = PixelFont.load("../assets/fonts/ark.ppf")
screen.antialias = Image.X4

# load the app icons
import os
def file_exists(path):
  try:
    os.stat(path)
    return True
  except OSError:
    return False

def get_app_list():
  apps = []
  for dir in os.listdir(".."):
    flags = os.stat(f"../{dir}")
    if flags[0] & 0x4000: # is a directory
      if file_exists(f"../{dir}/icon.png"):
        apps.append({
          "name": dir,
          "icon": Image.load(f"../{dir}/icon.png")
        })
  return apps

class Icon:
  brushes = [
    brushes.color(211, 250, 55, 255),
    brushes.color(48, 148, 255),
    brushes.color(95, 237, 131, 255),
    brushes.color(225, 46, 251, 255),
    brushes.color(216, 189, 14, 255),
    brushes.color(255, 128, 210, 255),
  ]

  def __init__(self, pos, index, icon, name):
    self.active = False
    self.pos = pos
    self.icon = icon
    self.name = name
    self.index = index
    self.spin = False

  def activate(self, active):
    if not self.active and active:
      self.spin = True
      self.spin_start = io.ticks

    self.active = active

  def draw(self):
    if self.spin:
      duration = 100
      frame = io.ticks - self.spin_start
      c = round(math.cos(frame / duration) * 4) / 4
      #c = math.cos(frame / duration)
      width = c # don't allow it to dissapear completely
      if width >= 0 and width < 0.1:
        width = 0.1
      if width <= 0 and width > -0.1:
        width = -0.1
      sprite_width = c * self.icon.width
      sprite_offset = abs(sprite_width) / 2

      if frame > (duration * 6):
        self.spin = False
    else:
      width = 1
      sprite_width = self.icon.width
      sprite_offset = sprite_width / 2

    squircle = shapes.squircle(0, 0, 20, 4)
    squircle.transform = Matrix().translate(*self.pos).scale(width, 1)
    screen.brush = brushes.color(0, 0, 0, 25)
    squircle.transform = squircle.transform.scale(1.1, 1.1)
    screen.draw(squircle)
    squircle.transform = squircle.transform.scale(1 / 1.1, 1 / 1.1)
    screen.brush = Icon.brushes[self.index]
    squircle.transform = squircle.transform.translate(-1, -1)
    screen.draw(squircle)
    squircle.transform = squircle.transform.translate(2, 2)
    screen.brush = brushes.color(0, 0, 0, 50)
    screen.draw(squircle)

    if sprite_width > 0:
      screen.scale_blit(self.icon, self.pos[0] - sprite_offset - 1, self.pos[1] - 13, sprite_width, 24)

    if not self.active:
      screen.brush = brushes.color(35, 41, 37, 125)
      screen.draw(shapes.rectangle(self.pos[0] - 24, self.pos[1] - 24, 48, 48))



apps = get_app_list()

# create app icons
icons = []
for i in range(0, len(apps)):
  x = i % 3
  y = math.floor(i / 3)
  pos = (x * 48 + 33, y * 48 + 42)
  app = apps[i]
  icons.append(Icon(pos, i, app["icon"], app["name"]))

active = 0
def update():
  global active, icons
  screen.brush = brushes.color(35, 41, 37)
  screen.draw(shapes.rectangle(0, 0, 160, 120))


  if io.BUTTON_C in io.pressed:
    active += 1

  if io.BUTTON_A in io.pressed:
    active -= 1

  if io.BUTTON_UP in io.pressed:
    active -= 3

  if io.BUTTON_DOWN in io.pressed:
    active += 3

  active %= len(apps)

  for i in range(0, len(icons)):
    icon = icons[i]
    icon.activate(active == i)
    icon.draw()
  # for i in range(0, len(apps)):
  #   x = i % 3
  #   y = math.floor(i / 3)
  #   index = (y * 3 + x)
  #   is_active = index == active
  #   draw_icon((x * 48 + 33, y * 48 + 44), index, is_active, apps[i])

  for i in range(0, len(apps)):
    if i == active:
      w, _ = screen.measure_text(apps[i]["name"])
      screen.brush = brushes.color(20, 40, 60, 200)
      screen.draw(shapes.rounded_rectangle(80 - (w / 2) - 4, 100, w + 8, 15, 4))
      screen.brush = brushes.color(255, 255, 255)
      screen.text(apps[i]["name"], 80 - (w / 2), 101)


  dots = "." * int(math.sin(io.ticks / 250) * 2 + 2)
  screen.brush = brushes.color(16, 20, 17)
  #screen.draw(shapes.rectangle(0, 0, 160, 14))

  # a bit of phosphor glow
  screen.brush = brushes.color(211, 250, 55, 30)
  screen.text(f"MonaOS v4.03{dots}", 5 - 1, 2 - 1)
  screen.text(f"MonaOS v4.03{dots}", 5, 2 - 1)
  screen.text(f"MonaOS v4.03{dots}", 5 + 1, 2)
  screen.text(f"MonaOS v4.03{dots}", 5 + 1, 2 + 1)

  screen.brush = brushes.color(211, 250, 55)
  screen.text(f"MonaOS v4.03{dots}", 5, 2)

