import math

screen.antialias = image.X4

def update():
  pen(20, 40, 60)
  screen.clear()

  i = math.sin(io.ticks / 2000) * 0.2 + 0.5
  f = math.sin(io.ticks / 1000) * 150
  t = f + (math.sin(io.ticks / 500) + 1.0) * 50 + 100

  stroke = ((math.sin(io.ticks / 1000) + 1) * 0.05) + 0.1

  shapes = [
    shape.rectangle(-1, -1, 2, 2),
    shape.rectangle(-1, -1, 2, 2).stroke(stroke),
    shape.circle(0, 0, 1),
    shape.circle(0, 0, 1).stroke(stroke),
    shape.star(0, 0, 5, i, 1),
    shape.star(0, 0, 5, i, 1).stroke(stroke),
    shape.squircle(0, 0, 1),
    shape.squircle(0, 0, 1).stroke(stroke),
    shape.pie(0, 0, 1, f, t),
    shape.pie(0, 0, 1, f, t).stroke(stroke),
    shape.arc(0, 0, i, 1, f, t),
    shape.arc(0, 0, i, 1, f, t).stroke(stroke),
    shape.regular_polygon(0, 0, 1, 3),
    shape.regular_polygon(0, 0, 1, 3).stroke(stroke),
    shape.line(-0.75, -0.75, 0.75, 0.75, 0.5),
    shape.line(-0.75, -0.75, 0.75, 0.75, 0.5).stroke(stroke),
  ]

  scale = ((math.sin(io.ticks / 1000) + 1) * 10) + 20

  for y in range(4):
    for x in range(4):
      i = y * 4 + x

      if i < len(shapes):
        pen(color.oklch(220, 128, i * 20, 150))

        shapes[i].transform = mat3().translate(x * 60 + 100, y * 60 + 30).rotate(io.ticks / 100).scale(scale)
        screen.shape(shapes[i])
