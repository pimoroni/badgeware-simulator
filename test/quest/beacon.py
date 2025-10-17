# from aye_arr.nec import NECReceiver
# from aye_arr.nec.remotes.descriptor import RemoteDescriptor

class RemoteDescriptor:
  pass

# nec remote descriptor
class GithubUniverseBeacon(RemoteDescriptor):
  NAME = "GithubUniverseBeacon"

  ADDRESS = 0x45

  BUTTON_CODES = {
    "QUEST1": 0x11,
    "QUEST2": 0x22,
    "QUEST3": 0x33,
    "QUEST4": 0x44,
    "QUEST5": 0x55,
    "QUEST6": 0x66,
    "QUEST7": 0x77,
    "QUEST8": 0x88,
    "QUEST9": 0x99
  }

  def __init__(self):
      super().__init__()