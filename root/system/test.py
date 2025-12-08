#mode(LORES | PALETTED)

screen.font = PixelFont.load("/system/assets/fonts/sins.ppf")

# red = color(255, 0, 0)
# red = from_okclh(0, 100, 100)
# green = color(0, 255, 0)
# red.alpha =
# red.blend(blue, 50)

green = color.rgb(0, 255, 0)

def update():



  print(green.r, green.g)

  green.g += 1

  # green = red.blend(blue, 10)

  # brush(green)

  # brush(pattern(col1 | (,,,), col2 | (,,,), [p1, p2, p3]))

  # spritesheet.brush()

  # green = alpha(green, 10)



  # color(red)
  # blur(10)

  # xor_brush = xor(color(0, 255, 0))

  # brush(xor_brush)



  # clear()

  # brush(solid(color(0, 0, 255)))

  # text("Hello World", (io.ticks/20)%100, 0)

  return True
