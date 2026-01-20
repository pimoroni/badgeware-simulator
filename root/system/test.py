from picovector import algorithm

mode(LORES)
sins = pixel_font.load(f"/system/assets/fonts/sins.ppf")
from system.tests import tests

selected = 0

def update():
  global selected

  pen(20, 40, 60)
  screen.clear()

  names = list(tests.keys())
  names = sorted(names)
  name = names[selected]
  screen.font = sins
  module = __import__(tests[name])
  module.update()

  i = 0

  if io.BUTTON_DOWN in io.pressed:
    selected += 1

  if io.BUTTON_UP in io.pressed:
    selected -= 1

  selected %= len(names)
  screen.font = sins




  # render 5 items above the current item, and 1 below, fade out from current
  for i in range(-3, 2):
    item = selected + i
    item %= len(names)
    name = names[item]

    y = 102 + (i * 10)
    alpha = (3 - abs(i)) * 20 + 20
    if item == selected:
      pen(20, 40, 60, 200)
      w, h = screen.measure_text(name)
      screen.rectangle(3, y + 2, w + 4, h - 2)

      pen(255, 255, 255, 255)
      screen.text(name, 5, y)
    else:
      pen(255, 255, 255, alpha)
      screen.text(name, 5, y)
