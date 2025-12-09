mode(HIRES)

screen.font = PixelFont.load("/system/assets/fonts/sins.ppf")

image = image.load("/system/assets/mona-sprites/mona-heart.png").window(0, 0, 24, 24)

import math

def magic_sprite(src, pos, scale=1, angle=0):
  w, h = src.width, src.height
  t = Matrix().translate(*pos).scale(scale, scale).rotate(angle).translate(-w / 2, -h / 2)
  imgbrush = brush.image(src, t)
  pen(imgbrush)
  rect = shapes.rectangle(0, 0, w, h)
  rect.transform = t
  rect.draw()

def update():
  pen(200, 255, 200)
  screen.clear()

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

  # cx = 80 + math.sin(io.ticks / 500) * 20
  # cy = 60 + math.sin(io.ticks / 250) * 20

  # t = Matrix().translate(cx, cy).scale(2, 2).rotate(io.ticks / 100).translate(12, 12)
  # imgbrush = brush.image(image, t)
  scale = (math.sin(io.ticks / 1000) + 1.0) * 5 + 2
  angle = math.cos(io.ticks / 500) * 150
  magic_sprite(image, (160, 120), scale, angle)

  r1 = rect(10, 10, 20, 20)
  r2 = rect(15, 15, 20, 20)

  #print(r1.intersects(r2))
  r3 = r1.intersection(r2)
  #print(r3.x, r3.y, r3.w, r3.h)

  p = point(12, 12)
  print(r1.contains(p))

  # screen.rectangle(rect(10, 20, 30, 40))
  # screen.rectangle(10, 20, 30, 40)
  # screen.rectangle(point(10, 20), point(30, 40))


  # pen(r, g, b, a)
  # pen(color)
  # pen(brush.color(r, g, b, a))
  # pen(brush.color(color))



  pen(255, 255, 255)

  x1 = int(math.sin(io.ticks / 500) * 20 + 0)
  y1 = int(math.sin(io.ticks / 400) * 30 + 0)
  x2 = int(math.sin(io.ticks / 300) * 20 + 150)
  y2 = int(math.sin(io.ticks / 200) * 30 + 120)
  screen.line(x1, y1, x2, y2)


  for y in range(0, 30):
    for x in range(0, 30):
      c = screen.get(x, y)
      c.lighten(200)
      pen(c.r, c.g, c.b)
      screen.put(x + 100, y + 100)


  r1s = 50
  r1x = (math.sin(io.ticks / 100) * 20) + 160 - r1s / 2
  r1y = (math.cos(io.ticks / 100) * 20) + 160 - r1s / 2
  r1 = rect(r1x, r1y, r1s, r1s)

  pen(255, 0, 0)
  screen.rectangle(r1)

  r2s = 50
  r2x = (math.sin(io.ticks / 200) * 40) + 160 - r1s / 2
  r2y = (math.cos(io.ticks / 200) * 40) + 160 - r1s / 2
  r2 = rect(r2x, r2y, r2s, r2s)

  pen(0, 0, 255)
  screen.rectangle(r2)

  r3 = r1.intersection(r2)
  pen(0, 255, 0)
  screen.rectangle(r3)

  print(r3.l, r3.t, r3.r, r3.b)

  # for y in range(-80, 240, 60):
  #   for x in range(-80, 320, 60):
  #     pen(brush.color(20, 40, 60, 100))
  #     shapes.circle(cx + x, cy + y, 30).draw()
  #     pen(imgbrush)
  #     shapes.circle(cx + x, cy + y, 30).draw()

