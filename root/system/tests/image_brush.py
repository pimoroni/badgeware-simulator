import math

skull = image.load("/system/assets/skull.png")

def update():
  pen(20, 40, 60)
  screen.clear()

  t = mat3().translate(-12, -12).rotate(io.ticks / 100).translate(160, 120).scale(math.sin(io.ticks / 1000) * 4)
  imgbrush = brush.image(skull, t)

  pen(imgbrush)
  screen.shape(shape.circle(160, 120, 100))
