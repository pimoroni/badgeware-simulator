import math, time, random, gc
from lib import *
import ui
from mona import Mona

FLOOR_POSITION = 80

mona = Mona(FLOOR_POSITION)



_lf = None
def free(message=""):
  global _lf
  f = int(gc.mem_free() / 1024)
  print(f"> free memory {f}kb [{message}]", end="")
  if _lf:
    delta = f - _lf
    sign = "-" if delta < 0 else "+"
    print(f" {sign}{abs(delta)}kb", end="")
  print("")
  _lf = f




#regular_polygon = shapes.regular_polygon(60, 60, r1, 5)

# circle = v.circle(240, 60, r1)
# squircle = v.squircle(150, 60, r1, 5)
# star = v.star(60, 150, 24, r2, r1)
# pie = v.pie(150, 150, 0, 270, r1)


brush_red = brushes.color(255, 0, 0, 100)
brush_green = brushes.color(0, 255, 0, 100)

brush_grid_1 = brushes.color(30, 50, 70)
brush_grid_2 = brushes.color(30, 40, 20)

outline = brushes.color(20, 30, 40, 150)


bar_width = 50
bar_top = 110
bar_height = 10

def clamp(min_value, max_value, value):
  return min(max_value, max(min_value, value))

def draw_background(ticks):
  screen.brush(brush_grid_1)
  screen.draw(shapes.rectangle(0, 0, 160, 120))
   
  screen.brush(brush_grid_2)
  start = time.time()
  for y in range(-1, 12):
    for x in range(-5, 20):
      if (x + y) % 2 == 0:
        xo = math.sin(ticks / 1000) * 2
        yo = math.cos(ticks / 1000) * 2
        mx = (mona.position[0] - 80) / 2
        screen.draw(shapes.rectangle(x * 10 - mx, y * 10, xo + 4, yo + 4))

  end = time.time()

  screen.brush(brush_grid_2)
  screen.draw(shapes.rectangle(0, FLOOR_POSITION, 160, 120 - FLOOR_POSITION))

  # draw floor texture
  floor = screen.window(0, FLOOR_POSITION, 160, 120)
  floor.brush(brushes.color(100, 200, 100, 15))
  for i in range(0, 30):
    #x1 = i * 10
    io = i * 10 
    x1 = io - (mona.position[0] - io) * 1.5
    x2 = io - (mona.position[0] - io) * 2
    line = shapes.line(x1, 5, x2, 19).stroke(2)    
    floor.draw(line)

  


def update(ticks):
  mona.happy = (math.sin(ticks / 3000) * 50) + 50
  mona.hunger = (math.sin(ticks / 1000) * 50) + 50
  mona.clean = (math.cos(ticks / 1500) * 50) + 50
                 
  screen.brush(brushes.color(0, 0, 0, 255))
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  screen.brush(brush_red)
  screen.draw(shapes.rectangle(10, 10, 10, 1))
  screen.draw(shapes.rectangle(10, 10, 1, 10))

  p = ticks / 1000


  # x1 = math.sin(p) * 10 + 20 
  # y1 = math.cos(p / 4) * 10 + 20 
  # x2 = math.cos(p / 2) * 10 + 100 
  # y2 = math.sin(p / 3) * 10 + 100 
  # r = math.sin(p) * 10 + 12
  # screen.draw(shapes.rounded_rectangle(x1, y1, x2, y2, r))

  # screen.brush(brush_green)
  # screen.draw(shapes.rounded_rectangle(50, 50, 90, 100, 8))
  # #time.sleep(2)


  # screen.draw(shapes.rectangle(20, 20, 90, 21))

  # return 
  mona.update()
  
  draw_background(ticks)
  
  mona.draw()
  
  ui.draw_stat_bars(mona)
  
  ui.draw_buttons()  

  ui.draw_header()

  if mona.time_since_last_mood_change() > 2:
    mona.random_mood()

  if mona.time_since_last_position_change() > 3:    
    mona.move_to_random()

  return True
