import gc, sys

sins = pixel_font.load(f"/system/assets/fonts/sins.ppf")
from system.tests import tests
names = sorted(list(tests.keys()))

selected = None
menu_index = 0
test = None

def load_test(index):
  global selected, test

  # unload previously running test
  if test:
    del sys.modules["//system/tests/" + names[selected]]

  gc.collect()

  selected = index
  selected %= len(names)

  name = names[selected]
  test = __import__(tests[name])

  print(f"loaded example {name} ({round(gc.mem_free() / 1000)}KB free)")

load_test(9)

def update():
  global selected, menu_index

  if io.BUTTON_DOWN in io.pressed:
    load_test(selected + 1)

  if io.BUTTON_UP in io.pressed:
    load_test(selected - 1)

  # make sure a font is loaded by default in case the example wishes to use it
  screen.font = sins

  # clear the framebuffer
  screen.pen = color.rgb(20, 40, 60)
  screen.clear()

  # call example update function
  test.update()

  # restore font for our use in case test overrode it
  screen.font = sins

  if menu_index < selected:
    menu_index += (selected - menu_index) / 20
  if menu_index > selected:
    menu_index -= (menu_index - selected) / 20

  # render 5 items above the current item, and 1 below, fade out from current
  for i in range(0, len(names)):
    name = names[i]

    y = 102 + (i * 10) - menu_index * 10
    alpha = abs(y) / 3
    if i == selected:
      screen.pen = color.rgb(20, 40, 60, 255)
      w, h = screen.measure_text(name)
      screen.rectangle(3, y + 2, w + 4, h - 2)

      screen.pen = color.rgb(255, 255, 255, 255)
      screen.text(name, 5, y)
    else:
      screen.pen = color.rgb(20, 40, 60, alpha)
      w, h = screen.measure_text(name)
      screen.rectangle(3, y + 2, w + 4, h - 2)

      screen.pen = color.rgb(255, 255, 255, alpha)
      screen.text(name, 5, y)
