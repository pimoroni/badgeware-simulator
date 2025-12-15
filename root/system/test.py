from picovector import algorithm

mode(HIRES)
ark = pixel_font.load(f"/system/assets/fonts/sins.ppf")

from system.tests import tests

selected = 0

def update():
  global selected

  pen(20, 40, 60)
  screen.clear()

  names = list(tests.keys())
  name = names[selected]
  tests[name].update()

  i = 0

  if io.BUTTON_DOWN in io.pressed:
    selected += 1

  if io.BUTTON_UP in io.pressed:
    selected -= 1

  pen(255, 255, 255)
  title = "Badgeware API examples"
  w, h = screen.measure_text(title)
  screen.text(title, 160 - w / 2, 5)

  selected %= len(names)
  screen.font = ark
  for name in names:
    yoff = 120 - 6 - selected * 12
    pen(20, 40, 60, 150)
    w, h = screen.measure_text(name)
    screen.rectangle(3, i * 12 + 5 + yoff, w + 4, h)
    pen(255, 255, 255, 255 if i == selected else 150)
    screen.text(name, 5, i * 12 + 5 + yoff)
    i += 1