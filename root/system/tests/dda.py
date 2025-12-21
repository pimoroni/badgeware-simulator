from picovector import algorithm
import math

def update():
  screen.clear(color.rgb(20, 40, 60))

  grid = 20

  p = point(
    math.sin(io.ticks / 3000) * 2,
    math.cos(io.ticks/ 4000) * 2
  )
  v = point(
    math.cos(io.ticks / 5000) * 100,
    math.sin(io.ticks/ 6000) * 100
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
    ip, ig, edge, offset, distance = intersection

    print(ig.x, ig.y, edge)

    ip.x = ip.x * grid + 160
    ip.y = ip.y * grid + 120
    pen(0, 255, 0)
    screen.circle(ip, 2)

    ig.x = ig.x * grid + 160
    ig.y = ig.y * grid + 120
    pen(0, 255, 0, 100)
    screen.rectangle(ig.x, ig.y, grid, grid)


    if edge == 0:
      pen(255, 255, 255)
      screen.line(ig.x, ig.y, ig.x + grid, ig.y)

    if edge == 1:
      pen(255, 255, 255)
      screen.line(ig.x + grid, ig.y, ig.x + grid, ig.y + grid)

    if edge == 2:
      pen(255, 255, 255)
      screen.line(ig.x, ig.y + grid, ig.x + grid, ig.y + grid)

    if edge == 3:
      pen(255, 255, 255)
      screen.line(ig.x, ig.y, ig.x, ig.y + grid)
