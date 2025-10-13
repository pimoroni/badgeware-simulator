# we need to call this in our "pre-setup code", the user shouldn't have to do it
# it's required to setup the global 'screen' object
from picovector import PicoVector, brushes, shapes, Image, screen, io, Font, Matrix
import time

# print("io imported")
#print(io.ticks)

# BUTTON_A    = 16
# BUTTON_B    = 99 # can't find it...
# BUTTON_C    =  4
# BUTTON_UP   =  1
# BUTTON_DOWN =  8

# def is_pressed(button):
#   return BUTTONS & button


# takes a text string (that may include newline characters) and performs word
# wrapping. returns a line of lines and their widths as a result.
def wrap_and_measure(image, text, size, max_width):
  result = []

  for line in text.splitlines():
    # if max_width is specified then perform word wrapping
    if max_width:
      # setup a start and end cursor to traverse the text
      start, end = 0, 0
      while True:
        # search for the next space
        end = line.find(" ", end)
        if end == -1:
          end = len(line)

        # measure the text up to the space
        width, _ = image.measure_text(line[start:end], size)
        if width > max_width:
          # line exceeded max length
          end = line.rfind(" ", start, end)
          result.append((line[start:end], width))
          start = end + 1
        elif end == len(line):
          # reached the end of the string
          result.append((line[start:end], width))
          break

        # step past the last space
        end += 1
    else:
      # no wrapping needed, just return the original line with its width
      width, _ = image.measure_text(line, size)
      result.append((line, width))

  return result

def clamp(v, vmin, vmax):
  return max(vmin, min(v, vmax))

class SpriteSheet:
  def __init__(self, file, columns, rows):
    self.image = Image.load(file)
    self.sw = int(self.image.width / columns)
    self.sh = int(self.image.height / rows)

    self.sprites = []
    for x in range(0, columns):
      column = []
      for y in range(0, rows):
        sprite = self.image.window(self.sw * x, self.sh * y, self.sw, self.sh)
        column.append(sprite)
      self.sprites.append(column)

  def sprite(self, x, y):
    return self.sprites[x][y]

  def animation(self, x=0, y=0, count=None, horizontal=True):
    if not count:
      count = int(self.image.width / self.sw)
    return AnimatedSprite(self, x, y, count, horizontal)

class AnimatedSprite:
  def __init__(self, spritesheet, x, y, count, horizontal=True):
    self.spritesheet = spritesheet
    self.frames = []
    for _ in range(0, count):
      self.frames.append((x, y))
      if horizontal:
        x += 1
      else:
        y += 1

  def frame(self, frame_index = 0):
    frame_index %= len(self.frames)
    return self.spritesheet.sprite(self.frames[frame_index][0], self.frames[frame_index][1])

class BitmapFont:
  def __init__(self, file, char_width, char_height):
    self.image = Image.load(file)
    self.cw = char_width
    self.ch = char_height

    columns = self.image.width / self.cw
    rows = self.image.height / self.ch

    self.chars = []
    for y in range(0, rows):
      for x in range(0, columns):
        self.chars.append(self.image.window(self.cw * x, self.ch * y, self.cw, self.ch))

  def text(self, image, x, y, text, max_width=None, only_measure=False):
    cx, cy = 0, 0 # caret pos
    maxx, maxy = 0, 0

    lines = text.splitlines()
    for line in lines:
      words = line.split(" ")
      for word in words:
        # work out length of word in pixels
        wl = len(word) * self.cw

        # move to next line if exceeds max width
        if max_width and cx + wl > max_width:
          cx = 0
          cy += self.ch - 2

        # render characters in word
        for char in word:
          char_idx = ord(char)
          if not only_measure and char_idx < len(self.chars):
            image.blit(self.chars[char_idx], cx + x, cy + y)
          cx += self.cw

          if max_width and cx > max_width:
            cx = 0
            cy += self.ch - 2

        # once the word has been rendered update our min and max cursor values
        maxx = max(maxx, cx)
        maxy = max(maxy, cy + self.ch - 2)

        cx += self.cw / 3

      cx = 0
      cy += self.ch - 2

    return maxx, maxy

  def measure(self, text, max_width=None):
    return self.text(None, 0, 0, text, max_width=max_width, only_measure=True)

class Particle:
  def __init__(self, position, motion, user=None):
    self.position = position
    self.motion = motion
    self.user = user
    self.created_at = time.ticks_ms()

  def age(self):
    return (time.ticks_ms() - self.created_at) / 1000

class ParticleGenerator:
  def __init__(self, gravity, max_age = 2):
    self.gravity = gravity
    self.max_age = max_age
    self.last_tick_ms = time.ticks_ms()
    self.particles = []

  def spawn(self, position, motion, user=None):
    self.particles.append(Particle(position, motion, user))

  def youngest(self):
    return self.particles[-1] if len(self.particles) > 0 else None

  # update all particle locations and age out particles that have expired
  def tick(self):
    # expire aged particles
    self.particles = [particle for particle in self.particles if particle.age() < self.max_age]

    # update particles
    dt = (time.ticks_ms() - self.last_tick_ms) / 1000
    for particle in self.particles:
      particle.position = (
        particle.position[0] + (particle.motion[0] * dt),
        particle.position[1] + (particle.motion[1] * dt)
      )

      # apply "gravity" force to motion vectors
      particle.motion = (
        (particle.motion[0] + self.gravity[0] * dt),
        (particle.motion[1] + self.gravity[1] * dt)
      )

    self.last_tick_ms = time.ticks_ms()


# show the current free memory including the delta since last time the
# function was called, optionally include a custom message
_lf = None
def free(message=""):
  global _lf
  import gc
  gc.collect() # collect any free memory before reporting
  f = int(gc.mem_free() / 1024)
  print(f"{message}: {f}kb", end="")
  if _lf:
    delta = f - _lf
    sign = "-" if delta < 0 else "+"
    print(f" ({sign}{abs(delta)}kb)", end="")
  print("")
  _lf = f