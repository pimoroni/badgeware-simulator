# show the current free memory including the delta since last time the
# function was called, optionally include a custom message
_lf = None
def free(message=""):
  global _lf
  f = int(gc.mem_free() / 1024)
  print(f"> free memory {f}kb [{message}]", end="")
  if _lf:
    delta = f - _lf
    sign = "-" if delta < 0 else "+"
    print(f" {sign}{abs(delta)}kb", end="")
  print("")
  _lf = f