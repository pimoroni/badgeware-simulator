import math

skull = image.load("/system/assets/skull.png")
screen.font = pixel_font.load("/system/assets/fonts/compass.ppf")

def update():
  print(dir(color))
  pen(color.black)
  screen.clear()

  # b = screen.raw

  # for i in range(0, 320*240*4):
  #   b[i] = i
