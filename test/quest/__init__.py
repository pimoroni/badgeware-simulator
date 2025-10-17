import math
import random
from lib import *
from beacon import GithubUniverseBeacon
import ui

class Quest:
  def __init__(self, name, code, description):
    self.name = name
    self.description = description
    self.code = code

quests = [
  Quest("QUEST1", 0x11, "Hack Your Badge"),
  Quest("QUEST2", 0x22, "The Thinking Machine"),
  Quest("QUEST3", 0x33, "Open Source Zone"),
  Quest("QUEST4", 0x44, "GitHub Learn"),
  Quest("QUEST5", 0x55, "The Makerspace"),
  Quest("QUEST6", 0x66, "Demos & Donuts"),
  Quest("QUEST7", 0x77, "Octocat Generator"),
  Quest("QUEST8", 0x88, "Stars Lounge"),
  Quest("QUEST9", 0x99, "GitHub Next")
]

# setup handled ir button codes
for quest in quests:
  GithubUniverseBeacon.BUTTON_CODES[quest.name] = quest.code

# do this!
# receiver = NECReceiver(21, 0, 0)
# receiver.bind(self.remote)
# receiver.start()

def update():
  # clear the screen
  screen.brush = brushes.color(35, 41, 37)
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  #receiver.decode()

  ui.draw_status()

  ui.draw_tiles()