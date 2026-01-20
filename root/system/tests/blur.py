import math, random

def update():
  pen(color.rgb(150,190, 160))

  random.seed(1)

  for i in range(0, 20):
    x = random.uniform(-5, 5)
    y = random.uniform(-5, 5)
    s = random.uniform(0.5, 2)
    star = shape.star(x, y, 5, s / 2, s)
    star.transform = mat3().translate(160, 120).scale(30).rotate(io.ticks / 10)
    screen.shape(star)


  b = math.sin(io.ticks / 500) * 5 + 5
  screen.blur(b)

  screen.text(f"blur radius: {b:.2f}", 100, 200)