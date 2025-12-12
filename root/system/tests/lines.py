import random, math

def update():
  #pen(20, 40, 60)
  screen.clear(color.rgb(20, 40, 60))

  random.seed(0)

  for i in range(100):
    x = math.sin(i + io.ticks / 100) * 40
    y = math.cos(i + io.ticks / 100) * 40
    p1 = point(x + bw.rnd(-50, 370), y + bw.rnd(-50, 290))
    p2 = point(x + bw.rnd(-50, 370), y + bw.rnd(-50, 290))
    pen(bw.rnd(255), bw.rnd(255), bw.rnd(255))
    screen.line(p1, p2)