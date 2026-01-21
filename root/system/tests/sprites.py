import math, random

skull = image.load("/system/assets/skull.png")

def update():
  screen.clear(color.rgb(20, 40, 60))

  random.seed(0)
  for i in range(30):
    s = (math.sin(io.ticks / 500) * 1) + 2

    skull.alpha = int((math.sin((io.ticks + i * 30) / 500) + 1) * 127)

    x = math.sin(i + io.ticks / 1000) * 40
    y = math.cos(i + io.ticks / 1000) * 40

    pos = vec2(x + bw.rnd(-20, 180), y + bw.rnd(-20, 140))

    dr = rect(
      pos.x, pos.y, 32 * s, 24 * s
    )
    screen.blit(skull, dr)
    # pos.x += 20
    #screen.blit(skull, pos)

