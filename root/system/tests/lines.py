
def update():
  for i in range(100):
    p1 = point(bw.rnd(-50, 370), bw.rnd(-50, 290))
    p2 = point(bw.rnd(-50, 370), bw.rnd(-50, 290))
    pen(bw.rnd(255), bw.rnd(255), bw.rnd(255))
    screen.line(p1, p2)