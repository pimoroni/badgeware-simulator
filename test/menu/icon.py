import math
from lib import *

bold = [
  brushes.color(211, 250, 55),
  brushes.color(48, 148, 255),
  brushes.color(95, 237, 131),
  brushes.color(225, 46, 251),
  brushes.color(216, 189, 14),
  brushes.color(255, 128, 210)
]


fade = 1.8
faded = [
  brushes.color(211 / fade, 250 / fade, 55 / fade),
  brushes.color(48 / fade, 148 / fade, 255 / fade),
  brushes.color(95 / fade, 237 / fade, 131 / fade),
  brushes.color(225 / fade, 46 / fade, 251 / fade),
  brushes.color(216 / fade, 189 / fade, 14 / fade),
  brushes.color(255 / fade, 128 / fade, 210 / fade)
]


class Icon:


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
      c = round(math.cos(frame / duration) * 3) / 3
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
    if self.active:
      screen.brush = bold[self.index]
    else:
      screen.brush = faded[self.index]
    squircle.transform = squircle.transform.translate(-1, -1)
    screen.draw(squircle)
    squircle.transform = squircle.transform.translate(2, 2)
    screen.brush = brushes.color(0, 0, 0, 50)
    screen.draw(squircle)

    if sprite_width > 0:
      self.icon.alpha = 255 if self.active else 100
      screen.scale_blit(self.icon, self.pos[0] - sprite_offset - 1, self.pos[1] - 13, sprite_width, 24)

    # if not self.active:
    #   screen.brush = brushes.color(35, 41, 37, 125)
    #   screen.draw(shapes.rectangle(self.pos[0] - 24, self.pos[1] - 24, 48, 48))
