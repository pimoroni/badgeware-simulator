mode(HIRES)

screen.font = PixelFont.load("/system/assets/fonts/sins.ppf")

image = Image.load("/system/assets/mona-sprites/mona-heart.png").window(0, 0, 24, 24)

import math

def update():
  pen(brush.color(200, 255, 200))
  screen.clear()
  """
  pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 100), (
    0b00000000,
    0b01111110,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b01111110,
    0b00000000))
  pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 255), 11)
  pen(pattern)
  screen.rectangle(0, 0, screen.width, screen.height)

  pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), (
    0b00000000,
    0b01111110,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b01111110,
    0b00000000))
  pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), 11)

  pen(pattern)


  shapes.circle(160 + math.sin(io.ticks / 500) * 30, 120 + math.sin(io.ticks / 1000) * 30, 80).draw()
  # """

  cx = 80 + math.sin(io.ticks / 500) * 20
  cy = 60 + math.sin(io.ticks / 250) * 20

  t = Matrix().translate(cx, cy).scale(2, 2).rotate(io.ticks / 100).translate(12, 12)
  imgbrush = brush.image(image, t)



  for y in range(-80, 240, 60):
    for x in range(-80, 320, 60):
      pen(brush.color(20, 40, 60, 100))
      shapes.circle(cx + x, cy + y, 30).draw()
      pen(imgbrush)
      shapes.circle(cx + x, cy + y, 30).draw()

  #for _ in range(255):
  #  screen.rectangle(20, 20, 280, 200)

  # pen(brush.color(255, 0, 0))
  # screen.rectangle(0, 0, 24 * 1, 24 * 1)
  # screen.scale_blit(image, 0, 0, 24 * 1, 24 * 1)

  pen(brush.color(255, 0, 0))
  screen.text("this is a test", 0, 0)
  return True