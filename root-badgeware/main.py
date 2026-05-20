import badgeware
import micropython

app = __import__("/system/main")

def update():
    if not badgeware._fatal_error:
        badge.clear()
    badge.poll()
    app.update()
