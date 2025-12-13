from picovector import algorithm
import math

def update():
  screen.clear(color.rgb(20, 40, 60))

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
