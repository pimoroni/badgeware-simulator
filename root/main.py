import badgeware
import debug

app = __import__("/system/test")

def update():
    screen.pen = badgeware.BG
    screen.clear()
    screen.pen = badgeware.FG
    io.poll()
    with debug:
        app.update()
