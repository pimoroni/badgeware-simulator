mode(HIRES)

screen.font = PixelFont.load("/system/assets/fonts/sins.ppf")

import math

def update():
  pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 100), (
    0b00000000,
    0b01111110,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b01111110,
    0b00000000))
  pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 255), 11)
  pen(pattern)
  screen.rectangle(0, 0, screen.width, screen.height)

  pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), (
    0b00000000,
    0b01111110,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b01111110,
    0b00000000))
  pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), 11)

  pen(pattern)
  
  screen.antialias = Image.X4
  shapes.circle(160 + math.sin(io.ticks / 500) * 30, 120 + math.sin(io.ticks / 1000) * 30, 80).draw()

  return True
