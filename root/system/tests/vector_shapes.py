import math

screen.antialias = image.X4

stroke = 0.25

i = 0.5
f = 100
t = 180

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

def update():
  screen.clear(color.rgb(20, 40, 60))




  for y in range(4):
    for x in range(4):
      i = y * 4 + x

      scale = ((math.sin((io.ticks + i * 2000) / 1000) + 1) * 3) + 5

      if i < len(shapes):
        pen(color.oklch(220, 128, i * 20, 150))

        shapes[i].transform = mat3().translate(x * 36 + 25, y * 26 + 20).rotate(io.ticks / 100).scale(scale)
        screen.shape(shapes[i])
