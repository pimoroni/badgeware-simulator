# This file is copied from /system/main.py to /main.py on first run
import gc
import sys
import os
import micropython
import simulator
import debug

HEADLESS = simulator.headless
SKIP_CINEMATIC = simulator.hot_reload
APP_STARTUP = "/system/apps/startup"
APP_MENU = "/system/apps/menu"
app = None


simulator.show_alloc_count = False        # Show number of MPAllocator allocs per frame
simulator.show_individual_allocs = False  # Show each alloc/dealloc, size and location

if HEADLESS:
    print("main.py: Headless mode detected!")

"""
# RAM & GC Testing

gc.threshold(10_000)

from badgeware import screen, brushes, shapes

print("main_window...")
main_window = screen.window(0, 0, 160, 120)

print("main_window.brush...")
main_window.brush = brushes.color(255, 0, 0)

print("pentagon...")
pentagon = shapes.regular_polygon(80, 60, 50, 5)

def update():
    print(gc.mem_free())
    screen.window(0, 0, 1, 1)
    main_window.brush = brushes.color(255, 0, 0)
    main_window.clear()
    main_window.brush = brushes.color(0, 255, 0)
    main_window.draw(pentagon)
"""


def launch(file):
    global app
    if app is not None:
        print(f"main.py: Tearing down {app.__name__} {sys.modules}")
        getattr(app, "on_exit", lambda: None)()
        #old_name = app.__name__
        del app
        # Strip out any paths relating to "/system/apps"
        while sys.path[0].startswith("/system/apps"):
            sys.path.pop(0)
        # Hack: If we don't "unimport" modules then an app will used a cached version
        # eg: Mona Pet's "import ui" will get the menu's "ui"
        #for module in ["ui", "icon", old_name, "pcf85063a", "powman", "st7789"]:
        #    if module in sys.modules:
        #        del sys.modules[module]
        for module in sys.modules.keys():
            del sys.modules[module]
    # Fix up the paths so the app can find its modules and assets
    sys.path.insert(0, file)
    os.chdir(file)
    gc.collect()
    print(micropython.mem_info())
    app = __import__(file)
    print(f"main.py: Launched {app.__name__}")
    getattr(app, "init", lambda: None)()


if SKIP_CINEMATIC:
    launch(APP_MENU)
else:
    launch(APP_STARTUP)

def update():
    with debug:
        if (result := app.update()) is not None:
            if app.__name__ == APP_MENU:
                launch(result)
            elif app.__name__ == APP_STARTUP:
                launch(APP_MENU)
    return True

# """