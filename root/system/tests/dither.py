import math, random

def update():
  pen(color.rgb(150,190, 160))

  random.seed(1)

  for i in range(0, 20):
    pen(color.rgb(i * 10,  i * 10 , i * 10))
    x = random.uniform(-5, 5)
    y = random.uniform(-5, 5)
    s = random.uniform(0.5, 2)
    star = shape.star(x, y, 5, s / 2, s)
    star.transform = mat3().translate(160, 120).scale(30).rotate(io.ticks / 10)
    screen.shape(star)

  screen.dither()
