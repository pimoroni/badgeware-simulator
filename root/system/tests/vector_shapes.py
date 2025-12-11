import math

screen.antialias = image.X4

def update():
  pen(20, 40, 60)
  screen.clear()

  i = math.sin(io.ticks / 2000) * 0.2 + 0.8
  f = math.sin(io.ticks / 1000) * 150
  t = math.sin(io.ticks / 500) * 150

  shapes = [
    shape.rectangle(-1, -1, 2, 2),
    shape.circle(0, 0, 1),
    shape.star(0, 0, 5, i, 1),
    shape.squircle(0, 0, 1),
    shape.pie(0, 0, 1, f, t),
    shape.arc(0, 0, i, 1, f, t),
    shape.regular_polygon(0, 0, 1, 3),
    shape.line(-0.75, -0.75, 0.75, 0.75, 0.5),
  ]

  stroke = ((math.sin(io.ticks / 1000) + 1) * 0.05) + 0.1
  shapes += [s.stroke(stroke) for s in shapes]

  for y in range(4):
    for x in range(4):
      i = y * 4 + x

      if i < len(shapes):
        pen(color.oklch(220, 128, i * 20, 150))

        shapes[i].transform = mat3().translate(x * 60 + 100, y * 60 + 30).rotate(io.ticks / 100).scale(20)
        screen.shape(shapes[i])
