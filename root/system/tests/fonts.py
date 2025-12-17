import time

fonts = ["ark", "desert", "torch", "sins", "teatime", "hungry", "kobold", "lookout", "loser", "winds", "match", "corset", "nope", "unfair", "saga", "memo", "outflank", "salty", "smart", "awesome", "compass", "yolk", "vest", "holotype", "yesterday", "absolute", "fear", "troll", "bacteria", "curse", "ziplock", "futile", "manticore", "more", "ignore"]
font = None
last_font_change = time.time()
font_index = 0
def change_font():
  global font_index, last_font_change, font
  font_index += 1
  font_index %= len(fonts)
  font = pixel_font.load(f"/system/assets/fonts/{fonts[font_index]}.ppf")
  last_font_change = time.time()

def update():

  if not font or time.time() > (last_font_change + 2):
    change_font()

  screen.clear(color.rgb(20, 40, 60))

  message = f"""Upon the mast I gleam and grin,
A sentinel of bone and sin.
Wind and thunder, night and hull—
None fear the sea like a pirate skull.

Once I roared with breath and flame,
Now legend is my only name.
But still I guard the plundered gold,
Grinning wide, forever bold."""


  pen(200, 220, 240)
  name = f"{fonts[font_index]}:"
  w, h = screen.measure_text(name)
  screen.text(name, 160 - (w / 2), 40)


  screen.font = font
  y = 60
  for line in message.splitlines():
    w, h = screen.measure_text(line)
    pen(0, 10, 10, 100)
    screen.rectangle(160 - (w / 2), y, w, h)
    pen(100, 255, 100, 150)
    screen.text(line, 160 - (w / 2), y)
    y += h
