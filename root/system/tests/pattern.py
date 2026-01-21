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
  custom_pattern = brush.pattern(color.rgb(0, 255, 0, 255), color.rgb(0, 0, 255, 255), pattern)
  pen(custom_pattern)
  screen.shape(shape.circle(80 + math.cos(io.ticks / 500) * 30, 60 + math.sin(io.ticks / 1000) * 30, 30))

  built_in_pattern = brush.pattern(color.cyan, color.black, 11)
  pen(built_in_pattern)
  screen.shape(shape.circle(80 + math.sin(io.ticks / 250) * 60, 60 + math.cos(io.ticks / 500) * 60, 30))

  built_in_pattern = brush.pattern(color.orange, color.black, 8)
  pen(built_in_pattern)
  screen.shape(shape.circle(80 + math.cos(io.ticks / 250) * 60, 60 + math.sin(io.ticks / 500) * 60, 30))