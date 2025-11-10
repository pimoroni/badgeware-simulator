from badgeware import *
from . import fetch
from . import wifi
from math import *

def system_tick():
  fetch.tick()
  wifi.tick()

def clamp(v, vmin, vmax):
  return max(vmin, min(v, vmax))

def file_exists(path):
  try:
    os.stat(path)
    return True
  except OSError:
    return False

def is_dir(path):
  try:
    flags = os.stat(path)
    return flags[0] & 0x4000 # is a directory
  except:
    return False

def center_text(text, y):
  w, h = screen.measure_text(text)
  screen.text(text, 80 - (w / 2), y)


def wrap_text(text, x, y):
  lines = text.splitlines()
  for line in lines:
    _, h = screen.measure_text(line)
    screen.text(line, x, y)
    y += h * 0.8