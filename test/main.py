
from picovector import PicoVector

WIDTH, HEIGHT = 320, 240    # Tufty 2350
# WIDTH, HEIGHT = 264, 176  # Badger 2350
# WIDTH, HEIGHT = 39, 26    # Blinky 2350

v = PicoVector(WIDTH, HEIGHT)

cx = WIDTH / 2
cy = HEIGHT / 2
r1 = HEIGHT / 3
r2 = HEIGHT / 4

regular_polygon = v.regular_polygon(cx, cy, r1, 5)
squircle = v.squircle(cx, cy, r1, 5)
circle = v.circle(cx, cy, r1)
star = v.star(cx, cy, 24, r2, r1)
pie = v.pie(cx, cy, 0, 270, r1)

def update(ticks):
    v.loop()
    v.draw(squircle)
    v.draw(regular_polygon)
    v.draw(circle)
    v.draw(star)
    v.draw(pie)
    # print(ticks)
    return True
