import math, time, random, gc
from lib import *

from mona import Mona

FLOOR_POSITION = 75

mona = Mona(FLOOR_POSITION)

pixel_code = Font("test/pixelcode-font.6x12.png", 6, 12)


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


icons = SpriteSheet(f"test/sprites/icons.png", 10, 1)



#regular_polygon = shapes.regular_polygon(60, 60, r1, 5)

# circle = v.circle(240, 60, r1)
# squircle = v.squircle(150, 60, r1, 5)
# star = v.star(60, 150, 24, r2, r1)
# pie = v.pie(150, 150, 0, 270, r1)


brush_red = brushes.color(255, 0, 0, 100)

brush_grid_1 = brushes.color(30, 50, 70)
brush_grid_2 = brushes.color(30, 40, 20)

outline = brushes.color(20, 30, 40, 150)


bar_width = 50
bar_top = 110
bar_height = 10

def clamp(min_value, max_value, value):
  return min(max_value, max(min_value, value))

def rect_deflate(rect):
  return (rect[0] + 1, rect[1] + 1, rect[2] - 1, rect[3] - 1)

def draw_background(ticks):
  screen.brush(brush_grid_1)
  screen.draw(shapes.rectangle(0, 0, 160, 120))
   
  screen.brush(brush_grid_2)
  start = time.time()
  for y in range(0, 12):
    for x in range(0, 17):
      if (x + y) % 2 == 0:
        xo = math.sin(ticks / 1000) * 2
        yo = math.cos(ticks / 1000) * 2
        screen.draw(shapes.rectangle(x * 10 + xo + 2, y * 10 + yo + 2, x * 10 + 10 - 2, y * 10 + 10 - 2))
  end = time.time()

  screen.brush(brush_grid_2)
  screen.draw(shapes.rectangle(0, FLOOR_POSITION, 160, 120))

  
brush_happy = brushes.color(236, 108, 185)
brush_hunger = brushes.color(119, 182, 138)
brush_clean = brushes.color(139, 156, 201)
def draw_bar(icon, brush, rect, amount):
  screen.brush(outline)
  screen.draw(shapes.rectangle(*rect))
  rect = rect_deflate(rect)  
  screen.brush(brush)
  width = int(((rect[2] - rect[0]) / 100) * amount)
  screen.draw(shapes.rectangle(rect[0], rect[1], rect[0] + width, rect[3]))
  screen.blit(icons.sprite(icon, 0), rect[0] - 6, rect[1] - 4)

def draw_action(icon, name, pos):
  screen.blit(icons.sprite(icon, 0), pos[0] - 3, pos[1] + 3)
  pixel_code.text(screen, pos[0] + 9, pos[1] - 1, name)
  

def update(ticks):
  mona.update()
  
  draw_background(ticks)

  mona.draw()

  draw_bar(0, brush_happy, (10, 100, 50, 105), mona.happy)
  draw_bar(1, brush_hunger, (60, 100, 100, 105), mona.hunger)
  draw_bar(2, brush_clean, (110, 100, 150, 105), mona.clean)
  
  draw_action(3, "play", (10, 105))
  draw_action(4, "feed", (60, 105))
  draw_action(5, "clean", (110, 105))

  screen.brush(outline)
  screen.draw(shapes.rectangle(0, 0, 160, 15))
  pixel_code.text(screen, 52, 0, "monagotchi")
  if mona.time_since_last_mood_change() > 2:
    mona.random_mood()

  if mona.time_since_last_position_change() > 3:
    print("here")
    mona.move_to_random()

  return True
