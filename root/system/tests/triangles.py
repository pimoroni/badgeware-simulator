
def update():

  for i in range(100):
    p = point(bw.rnd(-50, 370), bw.rnd(-50, 290))
    p1 = point(p.x + bw.rnd(-50, 50), p.y + bw.rnd(-50, 50))
    p2 = point(p.x + bw.rnd(-50, 50), p.y + bw.rnd(-50, 50))
    p3 = point(p.x + bw.rnd(-50, 50), p.y + bw.rnd(-50, 50))

    r = bw.rnd(5, 20)
    pen(bw.rnd(255), bw.rnd(255), bw.rnd(255))
    screen.triangle(p1, p2, p3)

