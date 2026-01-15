import math

def update():
  screen.clear(color.rgb(20, 40, 60))

  pen(0, 255, 255, 50)
  s = shape.custom([vec2(10, 10), vec2(20, 10), vec2(20, 20), vec2(10, 20)], [vec2(15, 15), vec2(25, 15), vec2(25, 25), vec2(15, 25)])

  for i in range(0, 18):
    s.transform = mat3().translate(160, 120).scale(math.sin(io.ticks / 500 + i) * 4).rotate(io.ticks / 50 + i * 20)
    screen.shape(s)
