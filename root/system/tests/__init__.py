import os
import sys

tests = {}
for file in os.listdir(__path__):
  file = file.rsplit(".", 1)[0]
  if not file.startswith("__"):
    tests[file] = __import__(__path__ + "/" + file)

setattr(sys.modules[__name__], "tests", tests)