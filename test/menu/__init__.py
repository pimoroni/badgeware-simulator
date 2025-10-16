import math
from lib import *

mona = SpriteSheet(f"../assets/mona-sprites/mona-default.png", 11, 1)
screen.font = PixelFont.load("../assets/fonts/loser.ppf")
screen.antialias = Image.X2

def draw_icon(pos, is_active, icon, text):

  screen.brush = brushes.color(40, 255, 60, 255 if is_active else 50)
  screen.draw(shapes.squircle(*pos, 24, 3))

  screen.brush = brushes.color(20, 40, 60)
  screen.draw(shapes.squircle(*pos, 22, 3))


  squircle = shapes.squircle(0, 0, 18, 3)
  if is_active:
    width = (math.sin(io.ticks / 100))
    sprite_width = math.sin(io.ticks / 100) * 24
    sprite_offset = abs(sprite_width) / 2
  else:
    width = 1
    sprite_width = 28
    sprite_offset = 14
  squircle.transform = Matrix().translate(*pos).scale(width, 1)
  screen.brush = brushes.color(40, 255, 60, 255)
  squircle.transform = squircle.transform.translate(-1, -1)
  screen.draw(squircle)
  squircle.transform = squircle.transform.translate(2, 2)
  screen.brush = brushes.color(120, 140, 160, 150)
  screen.draw(squircle)

  screen.scale_blit(mona.sprite(1, 0), pos[0] - sprite_offset, pos[1] - 14, sprite_width, 24)


active = 0
def update():
  global active
  screen.brush = brushes.color(20, 40, 60)
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  active = int(io.ticks / 1000) % 6
  for x in range(0, 3):
    for y in range(0, 2):
      is_active = (y * 3 + x) == active
      draw_icon((x * 52 + 28, y * 52 + 40), is_active, "dunno", "monagotchi")

  screen.brush = brushes.color(255, 255, 255)
  screen.text("MonaOS v1.03", 2, 0)

  screen.brush = brushes.color(20, 40, 60, 250)
  screen.draw(shapes.rectangle(40, 100, 80, 14))
  screen.brush = brushes.color(255, 255, 255)
  screen.text("monagotchi", 46, 100)