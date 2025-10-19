import random
from lib import *

background = brushes.color(35, 41, 37)
phosphor = brushes.color(211, 250, 55, 150)
white = brushes.color(235, 245, 255)
faded = brushes.color(235, 245, 255, 100)
small_font = PixelFont.load("../assets/fonts/ark.ppf")
large_font = PixelFont.load("../assets/fonts/absolute.ppf")

class DiskMode():
  def __init__(self):
    self.stars = []
    self.transferring = False
    for i in range(0, 500):
      self.stars.append((random.randint(-80, 80), random.randint(-60, 60), 0))

  def update(self):
    speed = 500 if self.transferring else 1000
    for i in range(0, len(self.stars)):
      star = self.stars[i]
      dx = star[0] * (io.ticks_delta / speed)
      dy = star[1] * (io.ticks_delta / speed)
      age = star[2] + 1
      star = (star[0] + dx, star[1] + dy, age)

      if star[0] < -80 or star[1] < -60 or star[0] > 80 or star[1] > 60:
        self.stars[i] = (random.randint(-80, 80), random.randint(-60, 60), 0)
      else:
        self.stars[i] = star

  def draw(self):
    screen.brush = background
    screen.draw(shapes.rectangle(0, 0, 160, 120))

    self.update()

    rect = shapes.rectangle(0, 0, 1, 1)
    for i in range(0, len(self.stars)):
      star = self.stars[i]
      age = min(1, star[2] / 50)

      brightness = 50
      if self.transferring:
        brightness = 200

      if int(star[0]) != 0 and int(star[1]) != 0:
        screen.brush = brushes.color(255, 255, 255, age * brightness)
        rect.transform = Matrix().translate(star[0], star[1]).translate(80, 60)
        screen.draw(rect)

    screen.font = large_font
    screen.brush = white
    center_text("USB Disk Mode", 5)

    screen.text("1:", 10, 23)
    screen.text("2:", 10, 45)
    screen.text("3:", 10, 67)

    screen.brush = phosphor
    screen.font = small_font
    wrap_text("""Your badge is now\nmounted as a disk""", 30, 24)

    wrap_text("""Copy code onto\nit to experiment!""", 30, 46)

    wrap_text("""Eject the disk to\nreboot your badge""", 30, 68)

    screen.font = small_font
    if self.transferring:
      screen.brush = white
      center_text("Transferring data!", 102)
    else:
      screen.brush = faded
      center_text("Waiting for data", 102)

def center_text(text, y):
  w, h = screen.measure_text(text)
  screen.text(text, 80 - (w / 2), y)

def wrap_text(text, x, y):
  lines = text.splitlines()
  for line in lines:
    _, h = screen.measure_text(line)
    screen.text(line, x, y)
    y += h * 0.8
