
def update():
  for i in range(100):
    p = point(bw.rnd(-50, 370), bw.rnd(-50, 290))
    r = bw.rnd(5, 20)
    pen(bw.rnd(255), bw.rnd(255), bw.rnd(255))
    screen.circle(p, r)
