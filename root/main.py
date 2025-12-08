import badgeware

app = __import__("/system/test")

screen.font = badgeware.DEFAULT_FONT

def update():
    badgeware.update_display_mode()
    screen.brush = badgeware.BG
    screen.clear()
    screen.brush = badgeware.FG
    io.poll()
    app.update()
