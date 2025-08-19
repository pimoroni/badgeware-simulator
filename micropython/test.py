
from picovector import PicoVector

v = PicoVector(264, 176)

regular_polygon = v.regular_polygon(160, 120, 50, 5)
squircle = v.squircle(160, 120, 50, 5)
circle = v.circle(160, 120, 50)
star = v.star(160, 120, 24, 40, 50)
pie = v.pie(160, 120, 0, 270, 80)

def update(ticks):
    v.loop()
    v.draw(squircle)
    v.draw(regular_polygon)
    v.draw(circle)
    v.draw(star)
    v.draw(pie)
    #print(ticks)
    return True
