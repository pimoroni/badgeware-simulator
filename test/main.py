import os, sys
from lib import *

# sets up the sys path and current working directory for the app to be launched
# then imports the app and returns it
def run_app(name):
  file_path = __file__.rsplit("/", 1)[0] + "/" + name
  os.chdir(file_path)
  sys.path.append(file_path)
  return __import__(name)

app = run_app("startup")

def update():    
  return app.update(io.ticks)
