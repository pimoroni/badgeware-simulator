import math

def update():
  pen(20, 40, 60)
  screen.clear()

  r1s = 80
  r1x = (math.sin(io.ticks / 100) * 20) + 160 - r1s / 2
  r1y = (math.cos(io.ticks / 100) * 20) + 120 - r1s / 2
  r1 = rect(r1x, r1y, r1s, r1s)

  pen(255, 100, 100)
  screen.rectangle(r1)

  r2s = 80
  r2x = (math.sin(io.ticks / 200) * 40) + 160 - r1s / 2
  r2y = (math.cos(io.ticks / 200) * 40) + 120 - r1s / 2
  r2 = rect(r2x, r2y, r2s, r2s)

  pen(100, 100, 255)
  screen.rectangle(r2)

  r3 = r1.intersection(r2)
  pen(100, 255, 100)
  screen.rectangle(r3)
