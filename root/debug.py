import simulator
from picovector import debug, brushes, PixelFont


DEBUG_FONT = PixelFont.load("/system/assets/fonts/ark.ppf")
DEBUG_BG = brushes.color(10, 10, 10)
DEBUG_FG = brushes.color(255, 255, 255)


def update():
    debug.brush = DEBUG_BG
    debug.clear()
    debug.font = DEBUG_FONT
    debug.brush = DEBUG_FG
    debug.text("Hello Debug!", 10, 0)
