import random
import math
from lib import *

phosphor = brushes.color(211, 250, 55, 150)
white = brushes.color(235, 245, 255)
faded = brushes.color(235, 245, 255, 100)
small_font = PixelFont.load("../assets/fonts/ark.ppf")
large_font = PixelFont.load("../assets/fonts/absolute.ppf")

def fake_number():
  return random.randint(10000, 99999)

def placeholder_if_none(text):
  if text:
    return text
  old_seed = random.seed()
  random.seed(int(io.ticks / 100))
  chars = "!\"£$%^&*()_+-={}[]:@~;'#<>?,./\\|"
  text = ""
  for i in range(0, 20):
    text += random.choice(chars)
  random.seed(old_seed)
  return text

class User:
  levels = [
    brushes.color( 21 / 4,  27 / 4,  35 / 4),
    brushes.color(  3 / 4,  58 / 4,  22 / 4),
    brushes.color( 25 / 4, 108 / 4,  46 / 4),
    brushes.color( 46 / 4, 160 / 4,  67 / 4),
    brushes.color( 86 / 4, 211 / 4, 100 / 4),
  ]

  def __init__(self):
    self.handle = None
    self.name = None
    self.followers = None
    self.contribs = None
    self.repos = None
    self.avatar = None

  def draw_stat(self, title, value, x, y):
    screen.brush = white if value else faded
    screen.font = large_font
    screen.text(value if value else str(fake_number()), x, y)
    screen.font = small_font
    screen.brush = phosphor
    screen.text(title, x - 1, y + 13)

  def draw(self):
    # draw contribution graph background
    old_seed = random.seed(1)
    size = 15
    graph_width = 53 * (size + 2)
    xo = int(-math.sin(io.ticks / 5000) * ((graph_width - 160) / 2)) + ((graph_width - 160) / 2)
    yo = 1
    screen.font = small_font
    rect = shapes.rounded_rectangle(0, 0, size, size, 2)
    for y in range(0, 7):
      for x in range(0, 53):
        screen.brush = random.choice(User.levels)
        pos = (x * (size + 2) - xo, y * (size + 2) + 1)
        if pos[0] + size < 0 or pos[0] > 160:
          # skip tiles that aren't in view
          continue
        rect.transform = Matrix().translate(*pos)
        screen.draw(rect)
    random.seed(old_seed)

    # draw handle
    screen.font = large_font
    handle = self.handle

    # use the handle area to show loading progress if not everything is ready
    if not self.handle or not self.image or not self.contribs:
      if not self.handle:
        handle = "fetching user data..."
      elif not self.contribs:
        handle = "fetching contribs..."
      else:
        handle = "fetching avatar..."

    w, _ = screen.measure_text(handle)
    screen.brush = white
    screen.text(handle, 80 - (w / 2), 2)

    # draw name
    screen.font = small_font
    screen.brush = phosphor
    name = placeholder_if_none(self.name)
    w, _ = screen.measure_text(name)
    screen.text(name, 80 - (w / 2), 16)

    # draw statistics
    self.draw_stat("followers", None, 88, 33)
    self.draw_stat("contribs", None, 88, 62)
    self.draw_stat("repos", None, 88, 91)

    # draw avatar imagee
    if not self.avatar:
      # create a spinning loading animation while we wait for the avatar to load
      screen.brush = phosphor
      squircle = shapes.squircle(0, 0, 10, 5)
      screen.brush = brushes.color(211, 250, 55, 50)
      for i in range(0, 4):
        mul = math.sin(io.ticks / 1000) * 14000
        squircle.transform = Matrix().translate(42, 75).rotate((io.ticks + i * mul) / 40).scale(1 + i / 1.3)
        screen.draw(squircle)
    else:
      screen.blit(self.avatar, 5, 37)

user = User()
user.handle = None
user.name = None

def update():
  screen.brush = brushes.color(0, 0, 0)
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  user.draw()