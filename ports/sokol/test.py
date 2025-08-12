import math
from picovector import PicoVector

v = PicoVector(bytearray())

regular_polygon = v.regular_polygon(160, 120, 50, 5)
squircle = v.squircle(160, 120, 50, 5)
circle = v.circle(160, 120, 50)
star = v.star(160, 120, 24, 40, 50)
pie = v.pie(160, 120, 0, 270, 80)

def hsv_to_rgb(h, s, v):  # noqa: RET503
    if s == 0.0:
        return v, v, v
    i = int(h * 6.0)
    f = (h * 6.0) - i
    p = v * (1.0 - s)
    q = v * (1.0 - s * f)
    t = v * (1.0 - s * (1.0 - f))
    i = i % 6
    if i == 0:
        return v, t, p
    if i == 1:
        return q, v, p
    if i == 2:
        return p, v, t
    if i == 3:
        return p, q, v
    if i == 4:
        return t, p, v
    if i == 5:
        return v, p, q


def update(ticks):
    v.loop()
    v.draw(squircle)
    v.draw(regular_polygon)
    v.draw(circle)
    v.draw(star)
    v.draw(pie)
    #print(ticks)
    return hsv_to_rgb((math.sin(ticks / 1000) + 1) / 2.0, 1.0, 1.0)