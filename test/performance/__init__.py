import json
import math
from lib import *

font = Font.load("assets/MonaSans-Medium-Low.af")



def vector_fonts():
  time.sleep(0.1)




_samples = []
_sample_count = 100

def update(ticks):
  screen.antialias(2);

  # clear the screen
  screen.brush(brushes.color(30, 50, 70))
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  # run test and measure time taken
  start = time.ticks_us()
  vector_fonts()
  end = time.ticks_us()

  # add sample to rolling samples
  global _samples, _sample_count
  _samples.append(end - start)
  if len(_samples) > _sample_count:
    _samples = _samples[-_sample_count:]

  # draw average FPS
  fps = round(1000000 / (sum(_samples) / float(len(_samples))))
  screen.font(font)
  width, height = screen.measure_text(f"{fps} FPS", 16)
  screen.brush(brushes.color(0, 0, 0))
  screen.draw(shapes.rectangle(0, 0, width + 4, height))
  screen.brush(brushes.color(255, 255, 255))  
  screen.text(f"{fps} FPS", 2, -3, 16)

  
  # #print("set font")
  # screen.font(vector_font)

  # screen.brush(brushes.color(30, 50, 70))
  # screen.draw(shapes.rectangle(0, 0, 160, 120))
  # screen.brush(brushes.color(255, 255, 255))
  # size = math.sin(ticks / 1000) * 30 + 40
  # screen.text(f"This", 50, 50, size)

  # return True
  #time.sleep(.5)
  # card = round(ticks / 5000)
  # draw_event_card(schedule[card % len(schedule)])
  
  # screen.font(font)


  # global _last_ticks
  # fps = round(1000 / (ticks - _last_ticks))
  # screen.brush(brushes.color(0, 0, 0))
  # screen.draw(shapes.rectangle(0, 0, 80, 24))
  # screen.brush(brushes.color(255, 255, 255))
  # screen.text(f"{fps}FPS", 0, 0, 20)
  # _last_ticks = ticks

  #time.sleep(0.5)

  return True