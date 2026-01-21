import math

pattern = (
  0b00000000,
  0b01111110,
  0b01000010,
  0b01011010,
  0b01011010,
  0b01000010,
  0b01111110,
  0b00000000
)

def update():
  screen.pen = brush.pattern(color.lime, color.transparent, pattern)
  pos = (80 + math.cos(io.ticks / 500) * 30, 60 + math.sin(io.ticks / 1000) * 30)
  screen.shape(shape.circle(*pos, 30))

  screen.pen = brush.pattern(color.cyan, color.transparent, 11)
  pos = (80 + math.sin(io.ticks / 250) * 60, 60 + math.cos(io.ticks / 500) * 60)
  screen.shape(shape.circle(*pos, 30))

  screen.pen =brush.pattern(color.orange, color.transparent, 8)
  pos = (80 + math.cos(io.ticks / 250) * 60, 60 + math.sin(io.ticks / 500) * 60)
  screen.shape(shape.circle(*pos, 30))