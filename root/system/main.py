# This file is copied from /system/main.py to /main.py on first run
import gc
import sys
import os

SKIP_CINEMATIC = True
APP_STARTUP = "/system/apps/startup"
APP_MENU = "/system/apps/menu"
app = None

def launch(file):
    global app
    if app is not None:
        getattr(app, "on_exit", lambda: None)()
        del app
        # Strip out any paths relating to "/system/apps"
        while sys.path[0].startswith("/system/apps"):
            sys.path.pop(0)
        # Hack: If we don't "unimport" modules then an app will used a cached version
        # eg: Mona Pet's "import ui" will get the menu's "ui"
        for module in ["ui", "icon"]:
            if module in sys.modules:
                del sys.modules[module]
    gc.collect()
    # Fix up the paths so the app can find its modules and assets
    sys.path.insert(0, file)
    os.chdir(file)
    app = __import__(file)
    getattr(app, "init", lambda: None)()


if SKIP_CINEMATIC:
    launch(APP_MENU)
else:
    launch(APP_STARTUP)


def update():
    if (result := app.update()) is not None:
        if app.__name__ == APP_MENU:
            launch(result)
        elif app.__name__ == APP_STARTUP:
            launch(APP_MENU)
    return True
