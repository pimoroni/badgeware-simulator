import math

sprites = SpriteSheet("/system/assets/mona-sprites/mona-heart.png", 14, 1)

def update():
  pen(20, 40, 60)
  screen.clear()

  t = mat3().translate(-12, -12).rotate(io.ticks / 100).translate(160, 120).scale(math.sin(io.ticks / 1000) * 4)
  imgbrush = brush.image(sprites.sprite(2, 0), t)

  pen(imgbrush)
  screen.shape(shape.circle(160, 120, 100))
