import math

def update():
  pen(20, 40, 60)
  screen.clear()

  pen(0, 255, 255, 50)
  s = shape.custom([point(10, 10), point(20, 10), point(20, 20), point(10, 20)], [point(15, 15), point(25, 15), point(25, 25), point(15, 25)])

  for i in range(0, 18):
    s.transform = mat3().translate(160, 120).scale(math.sin(io.ticks / 500 + i) * 4).rotate(io.ticks / 50 + i * 20)
    screen.shape(s)
