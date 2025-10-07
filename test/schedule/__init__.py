import json
import math
from lib import *

# load in the font - font sheet generated from 
# https://qwerasd205.github.io/PixelCode/
pixel_code = BitmapFont("assets/pixelcode-font.6x12.png", 6, 12)

vector_font = Font.load("assets/marker-high.af")



schedule = []
with open("assets/sessions.json") as schedule_file:
  schedule = json.load(schedule_file)

for event in schedule:
  print(event["title"])

class Event():
  def __init__(self, data):
    self._data = data
  
  def title(self):
    return self._data["title"]
  
  def track(self):
    return self._data["track"].split(" ")[0].upper() or None

  def where(self):
    return self._data["room"]

  def when(self):
    days = {"2025-10-28": "Tues", "2025-10-29": "Weds"}
    return f"{days[self._data["date"]]}    {self._data["starts"]} - {self._data["ends"]}"

  def presenter(self):
    return self._data["name"] or None

def centre_text(x, y, w, text, padding=0, background=None):
  if type(padding) == int or type(padding) == float:
    padding = (padding, padding, padding, padding)

  mw = w - padding[1] - padding[3]
  tw, h = pixel_code.measure(text, max_width=mw)

  if background:
    screen.brush(background)
    screen.draw(shapes.rectangle(x, y, w, h + padding[0] + padding[2]))
  
  pixel_code.text(screen, 80 - (tw / 2), y + padding[0], text, max_width=mw)
  return h + padding[0] + padding[2]

def draw_event_card(data):  
  event = Event(data)

  screen.brush(brushes.color(30, 70, 50))
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  caret_y = 0
  caret_y += centre_text(0, caret_y, 160, event.when(), padding=(1, 0, 4, 0), background=brushes.color(20, 40, 60, 150))
  caret_y += centre_text(0, caret_y, 160, event.where(), padding=(1, 10, 4, 10), background=brushes.color(20, 40, 60, 150))
  #centre_text(12, event.where())

  _, h = pixel_code.text(screen, 5, caret_y, event.title(), max_width=150)
  caret_y += h + 5
  


  if event.presenter():
    pixel_code.text(screen, 5, caret_y, "- " + event.presenter(), max_width=150)
  
  if event.track():
    w, _ = pixel_code.measure(event.track())
    w += 4
    h = 12
    screen.brush(brushes.color(230, 70, 50))
    screen.draw(shapes.rounded_rectangle(160 - w - 4, 120 - h - 4, w + 8, h, 3))
    pixel_code.text(screen, 160 - w, 120 - h - 4, event.track())

  #pixel_code.text(screen, 2, 82, event["topic"])

  # w = pixel_code.measure(event["type"]) + 4
  # h = 13
  # screen.brush(brushes.color(230, 70, 50))
  # screen.draw(shapes.rectangle(160 - w, 120 - h - 4, w, h))
  # pixel_code.text(screen, 160 - w + 2, 120 - h - 4, event["type"])

def update(ticks):
  card = round(ticks / 1000)
  draw_event_card(schedule[card % len(schedule)])
  return True