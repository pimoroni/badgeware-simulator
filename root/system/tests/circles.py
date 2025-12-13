import math, random

def update():
  screen.clear(color.rgb(20, 40, 60))

  random.seed(0)

  for i in range(250):
    x = math.sin(i + io.ticks / 100) * 40
    y = math.cos(i + io.ticks / 100) * 40

    p = point(x + bw.rnd(220) + 50, y + bw.rnd(140) + 50)
    r = bw.rnd(5, 20)
    pen(bw.rnd(255), bw.rnd(255), bw.rnd(255))
    screen.circle(p, r)
