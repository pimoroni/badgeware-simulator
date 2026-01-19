import badgeware

app = __import__("/system/main")

def update():
    if not badgeware._fatal_error:
        screen.pen = badgeware.BG
        screen.clear()
        screen.pen = badgeware.FG
    io.poll()
    app.update()
