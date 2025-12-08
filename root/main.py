import badgeware
import debug

app = __import__("/system/test")

def update():
    screen.brush = badgeware.BG
    screen.clear()
    screen.brush = badgeware.FG
    io.poll()
    with debug:
        app.update()
