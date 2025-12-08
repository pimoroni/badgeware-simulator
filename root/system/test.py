#mode(LORES | PALETTED)

screen.font = PixelFont.load("/system/assets/fonts/sins.ppf")

# red = color(255, 0, 0)
# red = from_okclh(0, 100, 100)
# green = color(0, 255, 0)
# red.alpha =
# red.blend(blue, 50)



def update():

  red = color.rgb(255, 0, 0, 100)

  for y in range(120):
    for x in range(160):
      if y < 60:
        col = color.hsv(int(360 * (x / 160)), 255 - y, 155)
      else:
        col = color.oklch(155 , 155, int(360 * (x / 160)))

      if x % 2 == 0:
        col.blend(red)
      screen.brush = brush.color(col.r, col.g, col.b)

      screen.rectangle(x, y, 1, 1)


  # color(red)
  # blur(10)

  # xor_brush = xor(color(0, 255, 0))

  # brush(xor_brush)



  # clear()

  # brush(solid(color(0, 0, 255)))

  # text("Hello World", (io.ticks/20)%100, 0)

  return True
