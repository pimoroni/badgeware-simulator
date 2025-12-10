from picovector import algorithm

mode(HIRES)

screen.font = pixel_font.load("/system/assets/fonts/sins.ppf")

image = image.load("/system/assets/mona-sprites/mona-heart.png").window(0, 0, 24, 24)

import math

def update():
  pen(20, 40, 60)
  screen.clear()

  dda()


def dda():
  grid = 20

  p = point(
    math.sin(io.ticks / 1000) * 2,
    math.cos(io.ticks/ 2000) * 2
  )
  v = point(
    math.cos(io.ticks / 3000) * 100,
    math.sin(io.ticks/ 5000) * 100
  )

  intersections = algorithm.dda(p, v, 10)

  p.x = (p.x * grid) + 160
  p.y = (p.y * grid) + 120
  v.x = (v.x * grid)
  v.y = (v.y * grid)

  pen(40, 60, 80)
  for y in range(0, 240 / grid):
    screen.line(0, y * grid, 319, y * grid)

  for x in range(0, 320 / grid):
    screen.line(x * grid, 0, x * grid, 239)

  t = point(
    p.x + v.x,
    p.y + v.y
  )
  pen(100, 120, 140)
  screen.line(p, t)

  pen(255, 255, 255)
  screen.shape(shape.circle(p, 2))

  pen(0, 255, 0)
  screen.shape(shape.circle(t, 2))

  for intersection in intersections:
    ip, ig, offset, edge, distance = intersection
    ip.x = ip.x * grid + 160
    ip.y = ip.y * grid + 120
    pen(0, 255, 0)
    screen.shape(shape.circle(ip, 2))

def magic_sprite(src, pos, scale=1, angle=0):
  w, h = src.width, src.height
  t = mat3().translate(*pos).scale(scale, scale).rotate(angle).translate(-w / 2, -h)
  imgbrush = brush.image(src, t)
  pen(imgbrush)
  rect = shape.rectangle(0, 0, w, h)
  rect.transform = t
  screen.shape(rect)

def image_brush():
  rectangle_intersection()
  t = mat3().rotate(io.ticks / 100)

  imgbrush = brush.image(image, t)
  for y in range(-80, 240, 60):
    for x in range(-80, 320, 60):
      pen(20, 40, 60, 100)
      screen.shape(shape.circle(x, y, 30))
      pen(imgbrush)
      screen.shape(shape.circle(x, y, 30))

def custom_shape():
  pen(255, 0, 255)
  s = shape.custom([point(10, 10), point(20, 10), point(20, 20), point(10, 20)], [point(15, 15), point(25, 15), point(25, 25), point(15, 25)])
  s.transform = mat3().translate(160, 120).scale(5).rotate(io.ticks / 50)
  screen.shape(s)

def rectangle_intersection():
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

def line_clipping():

  pen(255, 255, 255)

  # line clipping to window
  p1 = point(
    int(math.sin(io.ticks / 500) * 20 + 0),
    int(math.sin(io.ticks / 400) * 30 + 0)
  )

  p2 = point(
    int(math.sin(io.ticks / 300) * 20 + 150),
    int(math.sin(io.ticks / 200) * 30 + 120)
  )

  w = screen.window(30, 30, 80, 80)
  w.line(p1, p2)

  # line clipping to rect
  p1 = point(
    int(math.sin(io.ticks / 500) * 20 + 0) + 100,
    int(math.sin(io.ticks / 400) * 30 + 0)
  )

  p2 = point(
    int(math.sin(io.ticks / 300) * 20 + 150) + 100,
    int(math.sin(io.ticks / 200) * 30 + 120)
  )

  algorithm.clip_line(p1, p2, rect(130, 30, 80, 80))
  screen.line(p1, p2)


def window_blit():
  w = screen.window(20, 20, 80, 80)
  screen.blit(w, 180, 100)

def transformed_sprite():
  scale = (math.sin(io.ticks / 1000) + 1.0) * 5 + 2
  angle = math.cos(io.ticks / 500) * 150
  magic_sprite(image, (160, 120), scale, angle)

def patterns():

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

  screen.shape(shape.circle(160 + math.sin(io.ticks / 500) * 30, 120 + math.sin(io.ticks / 1000) * 30, 80))