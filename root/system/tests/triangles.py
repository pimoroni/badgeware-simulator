import math, random

def update():
  random.seed(0)
  for i in range(1000):
    x = math.sin(i + io.ticks / 100) * 40
    y = math.cos(i + io.ticks / 100) * 40

    p = point(x + bw.rnd(220) + 50, y + bw.rnd(140) + 50)
    p1 = point(p.x + bw.rnd(-30, 30), p.y + bw.rnd(-30, 30))
    p2 = point(p.x + bw.rnd(-30, 30), p.y + bw.rnd(-30, 30))
    p3 = point(p.x + bw.rnd(-30, 30), p.y + bw.rnd(-30, 30))

    r = bw.rnd(5, 20)
    pen(bw.rnd(255), bw.rnd(255), bw.rnd(255))
    screen.triangle(p1, p2, p3)

