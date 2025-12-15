import math

def update():
  screen.clear(color.rgb(20, 40, 60))

  custom_pattern = brush.pattern(color.rgb(255, 100, 100, 100), color.rgb(0, 0, 0, 0), (
    0b00000000,
    0b01111110,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b01111110,
    0b00000000))
  pen(custom_pattern)
  screen.shape(shape.circle(160 + math.cos(io.ticks / 500) * 30, 120 + math.sin(io.ticks / 1000) * 30, 60))

  built_in_pattern = brush.pattern(color.rgb(100, 255, 100, 100), color.rgb(0, 0, 0, 0), 11)
  pen(built_in_pattern)
  screen.shape(shape.circle(160 + math.sin(io.ticks / 250) * 60, 120 + math.cos(io.ticks / 500) * 60, 60))

  built_in_pattern = brush.pattern(color.rgb(100, 100, 255, 100), color.rgb(0, 0, 0, 0), 8)
  pen(built_in_pattern)
  screen.shape(shape.circle(160 + math.cos(io.ticks / 250) * 60, 120 + math.sin(io.ticks / 500) * 60, 60))