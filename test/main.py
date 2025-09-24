import math

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

  brush = v.color_brush(20, 40, 60, 255)
  v.clear()

  brush = v.color_brush(255, 255, 100, 100)
  
  x = math.sin(ticks / 1000) * 20
  y = math.cos(ticks / 1000) * 20

  squircle = v.squircle(x + 160, y + 120, r1, 5)

  v.draw(squircle)

#  v.draw(regular_polygon)
#  v.draw(circle)  
  #v.draw(pie)
##  v.draw(star)
  #print(ticks)
  return True
