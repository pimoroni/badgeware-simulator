import math, time

from picovector import PicoVector

WIDTH, HEIGHT = 320, 240    # Tufty 2350
# WIDTH, HEIGHT = 264, 176  # Badger 2350
# WIDTH, HEIGHT = 39, 26    # Blinky 2350

v = PicoVector(WIDTH, HEIGHT)

cx = WIDTH / 2
cy = HEIGHT / 2
r1 = HEIGHT / 6
r2 = HEIGHT / 6

regular_polygon = v.regular_polygon(60, 60, r1, 5)

circle = v.circle(240, 60, r1)
squircle = v.squircle(150, 60, r1, 5)
star = v.star(60, 150, 24, r2, r1)
pie = v.pie(150, 150, 0, 270, r1)


def update(ticks):
  print(ticks)
  v.loop()

  brush = v.color_brush(0, 0, 0, 255)
  v.clear()  
  
  s = ((math.sin(ticks / 500) + math.cos(ticks / 500)) + 2.1) * 5

  
  brushes = [
    v.color_brush(0, 0, 0, 255),
    v.brighten_brush(100),
    v.xor_brush(255, 255, 255)
  ]

  for y in range(0, 3):
    yo = y * 80 + 40
    for x in range(0, 4):
      xo = x * 80 + 40

      brush_idx = x + y * 3

      if brush_idx < len(brushes):
        v.brush(brushes[brush_idx])

        print(xo, yo, brush_idx)
        steps = 5
        for i in range(0, steps):
          angle = (360 / steps) * i
          angle += ticks / 20
          radians = angle * (math.pi / 180)
          lx = math.sin(radians) * 10
          ly = math.cos(radians) * 10
          squircle = v.squircle(xo + lx, yo + ly, s, 5)
          v.draw(squircle)


  time.sleep(0.1)

  
#  squircle = v.squircle(160 - x, 120 - y, s, 5)
#  v.draw(squircle)


#  v.draw(regular_polygon)
#  v.draw(circle)  
  #v.draw(pie)
##  v.draw(star)
  #print(ticks)
  return True
