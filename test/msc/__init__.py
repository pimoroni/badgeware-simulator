from lib import *
from disk_mode import DiskMode

ui = DiskMode()

def update():
  # set transfer state here
  ui.transferring = transferring = int((io.ticks) / 1000) % 2

  # draw the ui
  ui.draw()
