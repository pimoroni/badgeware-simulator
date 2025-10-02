import math, time
import gc
from lib import *

pixel_code = Font("test/pixelcode-font.6x12.png", 6, 12)

totoro = Image.load("test/totoro.png")

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
mona_dance = SpriteSheet(f"test/sprites/mona-dance.gif.png", 6, 1)
mona_code = SpriteSheet(f"test/sprites/mona-code-2.gif.png", 4, 1)
mona_dead = SpriteSheet(f"test/sprites/mona-dead.gif.png", 7, 1)
mona_default = SpriteSheet(f"test/sprites/mona-default.gif.png", 11, 1)
mona_eating = SpriteSheet(f"test/sprites/mona-eating.gif.png", 12, 1)
mona_heart = SpriteSheet(f"test/sprites/mona-heart.gif.png", 14, 1)
mona_notify = SpriteSheet(f"test/sprites/mona-notify.gif.png", 11, 1)
free("sprites loaded")
monas = {
  "dance":   AnimatedSprite(mona_dance, 0, 0, 6),
  "code":    AnimatedSprite(mona_code, 0, 0,  4),
  "dead":   AnimatedSprite(mona_dead, 0, 0,  7),
  "default": AnimatedSprite(mona_default, 0, 0, 11),
  "eating":  AnimatedSprite(mona_eating, 0, 0, 12),
  "heart":   AnimatedSprite(mona_heart, 0, 0,  14),
  "notify":  AnimatedSprite(mona_notify, 0, 0, 11)
}
free("animations defined")

#regular_polygon = shapes.regular_polygon(60, 60, r1, 5)

# circle = v.circle(240, 60, r1)
# squircle = v.squircle(150, 60, r1, 5)
# star = v.star(60, 150, 24, r2, r1)
# pie = v.pie(150, 150, 0, 270, r1)

brush_grid_1 = brushes.color(20, 40, 60, 255)
brush_grid_2 = brushes.color(60, 40, 20, 255)

def update(ticks):
  #print(totoro.width, totoro.height)
  #print(test.width, test.height)

  free = round(gc.mem_free() / 1024)
  #print(f"{ticks} ({free}kb free)")
  #v.loop()

  #v.brush(brush_grid_1)
  screen.brush(brush_grid_1)
  screen.draw(shapes.rectangle(0, 0, 160, 120))
  
  # #v.brush(brush_grid_2)
  # screen.brush(brush_grid_2)


  # start = time.time()
  # for y in range(0, 12):
  #   for x in range(0, 16):
  #     if (x + y) % 2 == 0:
  #       screen.draw(shapes.rectangle(x * 10, y * 10, x * 10 + 10, y * 10 + 10))
  # end = time.time()
  # delta = round((end - start) * 1000)
  # #print("grid took", delta, "ms")
      
  x = (math.sin(ticks / 1000) * 50) - 50 + 80
  y = (math.cos(ticks / 1000) * 50) - 50 + 60
  #screen.blit(mona.sprite(1, 1), x, y)
  

  frame = round(ticks / 100)

  i = 0
  for type in monas:
    i = i + 1
    yo = math.sin((ticks / 250) + (i / 1)) * 20
    xo = math.sin((ticks / 500) + (i / 2)) * 5
    screen.blit(monas[type].frame(frame), 0 + i * 18 + xo, 50 + yo)

  pixel_code.text(screen, 10, 10, "this is a message\nit should wrap to another\nline if it encounters a\nnew line character.")



  pixel_code.text(screen, 2, 2, "monagotchi")
  # screen.blit(eating_mona.frame(frame), 10, 30)
  # screen.blit(heart_mona.frame(frame), 30, 50)
  # screen.blit(code_mona.frame(frame), 50, 30)
  # # screen.blit(dance_mona.frame(frame), 70, 50)
  # screen.blit(default_mona.frame(frame), 90, 80)
  # screen.blit(ghost_mona.frame(frame), 110, 50)
  # screen.blit(notify_mona.frame(frame), 130, 30)

  
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