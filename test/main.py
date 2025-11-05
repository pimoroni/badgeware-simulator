import os, sys, gc
from lib import *

gc.threshold(10000)
sys.path.append("assets")

# sets up the sys path and current working directory for the app to be launched
# then imports the app and returns it
def run_app(name):
  os.chdir(name)
  sys.path.append(name)
  module = __import__(name)
  return module

app = run_app("performance")

_last_free_mem_debug = None
def update():
  global _last_free_mem_debug
  if not _last_free_mem_debug or time.time() - _last_free_mem_debug > 1:
    print(free("[info] free memory"))
    _last_free_mem_debug = time.time()
  return app.update()
