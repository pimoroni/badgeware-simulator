def update():
    hires()
    screen.font = PixelFont.load("/system/assets/fonts/sins.ppf")
    screen.brush = brushes.color(255, 0, 0)
    screen.clear()
    screen.brush = brushes.color(0, 0, 255)
    screen.text("Hello World", 0, 0)
    return True
