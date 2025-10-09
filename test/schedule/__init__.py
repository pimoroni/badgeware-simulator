import json
import math
from lib import *

# load in the font - font sheet generated from 
# https://qwerasd205.github.io/PixelCode/
pixel_code = BitmapFont("assets/pixelcode-font.6x12.png", 6, 12)

vector_font = Font.load("assets/MonaSans-Medium-Low.af")

schedule = []
with open("assets/sessions.json") as schedule_file:
  schedule = json.load(schedule_file)

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
    days = {"2025-10-28": "Tuesday", "2025-10-29": "Wednesday"}
    return f"{days[self._data["date"]]} {self._data["starts"]} - {self._data["ends"]}"

  def presenter(self):
    return self._data["name"] or None



def text(image, x, y, text, size, max_width=None, only_measure=False):    
  lines = [] 
  longest = 0 
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
        longest = max(longest, width)
        if width > max_width: 
          # line exceeded max length
          end = line.rfind(" ", start, end)
          lines.append(line[start:end])        
          start = end + 1
        elif end == len(line): 
          # reached the end of the string
          lines.append(line[start:end])
          break
        
        # step past the last space
        end += 1
    else:
      lines.append(line)    
 
    cy = 0
    for line in lines:            
      screen.text(line, x, cy + y, size)
      cy += size - 2

  return longest, cy

def centre_text(x, y, w, text, padding=0, background=None):
  if type(padding) == int or type(padding) == float:
    padding = (padding, padding, padding, padding)

  size = 12

  mw = w - padding[1] - padding[3]

  tw, h = screen.measure_text(text, size)

  #tw, h = pixel_code.measure(text, max_width=mw)

  if background:
    screen.brush(background)
    screen.draw(shapes.rectangle(x, y, w, h + padding[0] + padding[2]))
  
  #pixel_code.text(screen, 80 - (tw / 2), y + padding[0], text, max_width=mw)
  
  screen.brush(brushes.color(255, 255, 255))
  screen.text(text, 80 - (tw / 2), y + size + padding[0], size)

  return h + padding[0] + padding[2]

def draw_event_card(data):  
  event = Event(data)

  screen.brush(brushes.color(30, 70, 50))
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  
  #print("set font")
  screen.font(vector_font)
  #print("draw text")
  #size = math.sin(io.ticks / 1000) * 20 + 30
  

  #print("done")
  caret_y = 0
  caret_y += centre_text(0, caret_y, 160, event.when(), padding=(1, 0, 4, 0), background=brushes.color(20, 40, 60, 150))
  caret_y += centre_text(0, caret_y, 160, event.where(), padding=(1, 10, 4, 10), background=brushes.color(20, 40, 60, 150))
  #centre_text(12, event.where())

  #def text(image, x, y, text, size, max_width=None, only_measure=False):    
  text(screen, 5, caret_y + 20, event.title(), 20, max_width=150)
  #caret_y += centre_text(0, caret_y, 160, event.title(), padding=(1, 10, 4, 10), background=brushes.color(20, 40, 60, 150))

  # _, h = pixel_code.text(screen, 5, caret_y, event.title(), max_width=150)
  #caret_y += h + 5
  


  #if event.presenter():
  #  pixel_code.text(screen, 5, caret_y, "- " + event.presenter(), max_width=150)
  
  # if event.track():
  #   w, _ = pixel_code.measure(event.track())
  #   w += 4
  #   h = 12
  #   screen.brush(brushes.color(230, 70, 50))
  #   screen.draw(shapes.rounded_rectangle(160 - w - 4, 120 - h - 4, w + 8, h, 3))
  #   pixel_code.text(screen, 160 - w, 120 - h - 4, event.track())

  #pixel_code.text(screen, 2, 82, event["topic"])

  # w = pixel_code.measure(event["type"]) + 4
  # h = 13
  # screen.brush(brushes.color(230, 70, 50))
  # screen.draw(shapes.rectangle(160 - w, 120 - h - 4, w, h))
  # pixel_code.text(screen, 160 - w + 2, 120 - h - 4, event["type"])

_last_ticks = 0
def update(ticks):


  screen.antialias(4);
  
  # #print("set font")
  # screen.font(vector_font)

  # screen.brush(brushes.color(30, 50, 70))
  # screen.draw(shapes.rectangle(0, 0, 160, 120))
  # screen.brush(brushes.color(255, 255, 255))
  # size = math.sin(ticks / 1000) * 30 + 40
  # screen.text(f"This is a test", 50, 10, size)


  #time.sleep(.5)
  card = round(ticks / 5000)
  draw_event_card(schedule[card % len(schedule)])
  
  global _last_ticks
  fps = round(1000 / (ticks - _last_ticks))
  screen.brush(brushes.color(0, 0, 0))
  screen.draw(shapes.rectangle(0, 0, 80, 24))
  screen.brush(brushes.color(255, 255, 255))
  screen.text(f"{fps}FPS", 5, 18, 20)
  _last_ticks = ticks

  #time.sleep(0.5)

  return True