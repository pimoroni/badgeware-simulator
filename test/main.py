import math, time
import gc
from lib import *

# this class defines our little friend, modify it to change their behaviour!
class Mona:
  def __init__(self):
    self.happy = 50
    self.hunger = 80
    self.clean = 40

mona = Mona()

pixel_code = Font("test/pixelcode-font.6x12.png", 6, 12)

spritesheets = [
  "mona-dance.gif.png",
  "mona-code-2.gif.png",
  "mona-dead.gif.png",
  "mona-default.gif.png",
  "mona-eating.gif.png",
  "mona-heart.gif.png",
  "mona-love.gif.png",
  "mona-notify.gif.png",
]

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


free("before sprites")
icons = SpriteSheet(f"test/sprites/icons.png", 10, 1)
mona_dance = SpriteSheet(f"test/sprites/mona-dance.gif.png", 6, 1)
mona_code = SpriteSheet(f"test/sprites/mona-code-2.gif.png", 4, 1)
mona_dead = SpriteSheet(f"test/sprites/mona-dead.gif.png", 7, 1)
mona_default = SpriteSheet(f"test/sprites/mona-default.gif.png", 11, 1)
mona_eating = SpriteSheet(f"test/sprites/mona-eating.gif.png", 12, 1)
mona_heart = SpriteSheet(f"test/sprites/mona-heart.gif.png", 14, 1)
mona_notify = SpriteSheet(f"test/sprites/mona-notify.gif.png", 11, 1)
free("sprites loaded")
monas = {
  "dance":   mona_dance.animation(),
  "code":    mona_code.animation(),
  "dead":    mona_dead.animation(),
  "default": mona_default.animation(),
  "eating":  mona_eating.animation(),
  "heart":   mona_heart.animation(),
  "notify":  mona_notify.animation()
}
free("animations defined")

#regular_polygon = shapes.regular_polygon(60, 60, r1, 5)

# circle = v.circle(240, 60, r1)
# squircle = v.squircle(150, 60, r1, 5)
# star = v.star(60, 150, 24, r2, r1)
# pie = v.pie(150, 150, 0, 270, r1)

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
  screen.blit(icons.sprite(icon, 0), rect[0] - 5, rect[1] - 4)

def draw_action(icon, name, pos):
  screen.blit(icons.sprite(icon, 0), pos[0] - 3, pos[1] + 3)
  pixel_code.text(screen, pos[0] + 9, pos[1] - 1, name)

def draw_mona(name, frame, pos):
  image = monas[name].frame(frame) 
  #screen.blit(monas[name].frame(frame), pos[0] - (image.width / 2), 60 - (image.height / 2))
  width, height = image.width * 2, image.height * 2
  screen.scale_blit(monas[name].frame(frame), pos[0] - (width / 2), pos[1] - (height / 2), width, height)

def update(ticks):
  #print("grid took", delta, "ms")
  draw_background(ticks)
  frame = round(ticks / 100)

  # i = 0
  # for type in monas:
  #   i = i + 1 
  #   yo = math.sin((ticks / 250) + (i / 1)) * 20
  #   xo = math.sin((ticks / 500) + (i / 2)) * 5
  #   screen.blit(monas[type].frame(frame), 0 + i * 18 + xo, 50 + yo)

  draw_mona("default", frame, (80, 60))

  #pixel_code.text(screen, 10, 10, "this is a message\nit should wrap to another\nline if it encounters a\nnew line character.")

  draw_bar(0, brush_happy, (10, 100, 50, 105), mona.happy)
  draw_bar(1, brush_hunger, (60, 100, 100, 105), mona.hunger)
  draw_bar(2, brush_clean, (110, 100, 150, 105), mona.clean)
  
  draw_action(3, "play", (10, 105))
  draw_action(4, "feed", (60, 105))
  draw_action(5, "clean", (110, 105))

  screen.brush(outline)
  screen.draw(shapes.rectangle(0, 0, 160, 15))

  pixel_code.text(screen, 52, 0, "monagotchi")

  
  # b = [
  #   [brushes.color(200, 100, 100, 100)],
  #   [brushes.brighten(20)],
  #   [brushes.xor(255, 255, 255)],
  #   [brushes.blur(1), brushes.color(20, 40, 60, 100)]
  # ]

  # s = ((math.sin(ticks / 500) + math.cos(ticks / 500)) + 2.1) * 5

  # for y in range(0, 3):
  #   yo = y * 40 + 20
  #   for x in range(0, 4):
  #     xo = x * 40 + 20

  #     brush_idx = x + y * 4

  #     if brush_idx < len(b):
  #       for b2 in b[brush_idx]:
  #         screen.brush(b2)

  #         #print(xo, yo, brush_idx)
  #         steps = 5
  #         start = time.time()
  #         for i in range(0, steps):
  #           angle = (360 / steps) * i
  #           angle += ticks / 20
  #           radians = angle * (math.pi / 180)
  #           lx = math.sin(radians) * 10
  #           ly = math.cos(radians) * 10
  #           squircle = shapes.squircle(xo + lx, yo + ly, s, 5)

  #           #squircle = v.rectangle(xo + lx - s, yo + ly - s, xo + lx + s, yo + ly + s)

  #           screen.draw(squircle)
  #         end = time.time()
  #         delta = round((end - start) * 1000)
  #         #print("brush", brush_idx, "took", delta, "ms")

  
  #time.sleep(0.1)

  
#  squircle = v.squircle(160 - x, 120 - y, s, 5)
#  v.draw(squircle)


#  v.draw(regular_polygon)
#  v.draw(circle)  
  #v.draw(pie)
##  v.draw(star)
  #print(ticks)
  return True
# 