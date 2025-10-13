import time
import math
from lib import *

# load user interface sprites
icons = SpriteSheet(f"assets/icons.png", 10, 1)

# load in the font - font sheet generated from
# https://qwerasd205.github.io/PixelCode/
#pixel_code = BitmapFont("assets/pixelcode-font.6x12.png", 6, 12)
monasans = Font.load("assets/MonaSans-Medium-Low.af")
screen.font = monasans

# brushes to match monas stats
stats_brushes = {
  "happy": brushes.color(141, 39, 135),
  "hunger": brushes.color(53, 141, 39),
  "clean": brushes.color(39, 106, 171),
  "warning": brushes.color(255, 0, 0, 200)
}

# icons to match monas stats
stats_icons = {
  "happy": icons.sprite(0, 0),
  "hunger": icons.sprite(1, 0),
  "clean": icons.sprite(2, 0)
}

# ui outline (contrast) colour
outline_brush = brushes.color(20, 30, 40, 150)

# draw the background scenery
def background(mona):
  floor_y, mona_x = mona.position()[1] - 5, mona.position()[0]

  screen.antialias = Image.OFF

  # fill the wall background
  screen.brush = brushes.color(30, 50, 70)
  screen.draw(shapes.rectangle(0, 0, 160, floor_y))

  # animate the wallpaper
  screen.brush = brushes.color(30, 40, 20)
  mx = (mona_x - 80) / 2
  for y in range(0, 8):
    for x in range(0, 19):
      if (x + y) % 2 == 0:
        xo = math.sin(io.ticks / 1000) * 2
        yo = math.cos(io.ticks / 1000) * 2
        screen.draw(shapes.rectangle(x * 10 - mx, y * 10 - 3, xo + 4, yo + 4))

  # draw the picture frame
  px = 140 - mx
  screen.brush = brushes.color(80, 90, 100, 100)
  screen.draw(shapes.line(px + 2, 20 + 2, px + 20, 15, 1))
  screen.draw(shapes.line(px + 35 + 2, 20 + 2, px + 20, 15, 1))
  screen.brush = brushes.color(30, 40, 50, 100)
  screen.draw(shapes.rectangle(px + 1, 20 + 1, 38, 28))
  screen.brush = brushes.color(50, 40, 30, 255)
  screen.draw(shapes.rectangle(px, 20, 38, 28))
  screen.brush = brushes.color(120, 130, 140, 255)
  screen.draw(shapes.rectangle(px + 2, 20 + 2, 38 - 4, 28 - 4))
  portrait = mona._animations["heart"].frame(7)
  #print(portrait.has_palette)
  portrait.alpha = 180

  screen.blit(portrait, px + 8, 20)

  # draw the skirting board
  screen.brush = brushes.color(80, 90, 100, 150)
  screen.draw(shapes.rectangle(0, floor_y - 5, 160, 5))
  screen.draw(shapes.rectangle(0, floor_y - 4, 160, 1))

  # draw the outlet
  outlet = icons.sprite(3, 0)
  screen.blit(outlet, px - 90, floor_y - 18)

  # draw the floor
  floor = screen.window(0, floor_y, 160, 120) # clip drawing to floor area

  # draw background fill
  floor.brush = brushes.color(30, 40, 20)
  floor.draw(shapes.rectangle(0, 0, 160, 120 - floor_y))

  # draw floorboards
  floor.brush = brushes.color(100, 200, 100, 15)
  for i in range(0, 300, 10):
    x1 = i - ((mona_x - i) * 1.5)
    x2 = i - ((mona_x - i) * 2)
    line = shapes.line(x1, 5, x2, 19, 2)
    floor.draw(line)

  screen.antialias = Image.X4

# draw the title banner
def draw_header():
  screen.brush = outline_brush
  screen.draw(shapes.rounded_rectangle(30, -5, 160 - 60, 24, 3))
  screen.brush = brushes.color(255, 255, 255)
  w, _ = screen.measure_text("monagotchi", 18)
  screen.text("monagotchi", 80 - (w / 2), -4, 18)

def draw_buttons():
  draw_button(  4, 102, stats_brushes["happy"], "A", "play")
  draw_button( 55, 102, stats_brushes["hunger"], "B", "feed")
  draw_button(106, 102, stats_brushes["clean"], "C", "clean")

# draw a user action button with button name and label
def draw_button(x, y, brush, button, label):
  button_width = 50

  # draw the button outline
  screen.brush = outline_brush
  screen.draw(shapes.rounded_rectangle(x, y, button_width, 15, 6))

  # draw the button fill
  screen.brush = brushes.color(60, 80, 100)
  screen.draw(shapes.rounded_rectangle(x + 1, y + 1, button_width - 2, 15 - 2, 4))
  screen.brush = brushes.color(0, 0, 0, 100)
  screen.text(label, x + 17, y - 2, 14)
  screen.brush = brushes.color(255, 255, 255)
  screen.text(label, x + 16, y - 3, 14)

  #pixel_code.text(screen, x + 17, y + 1, label)

  # draw the button action key
  screen.brush = brush
  screen.draw(shapes.rounded_rectangle(x + 1, y + 1, 13, 13, 4))
  screen.brush = brushes.color(255, 255, 255)
  screen.text(button, x + 3, y - 2, 14)

# draw a statistics bar with icon and fill level
def draw_bar(name, x, y, amount):
  bar_width = 40

  # draw the bar background
  screen.brush = outline_brush
  screen.draw(shapes.rounded_rectangle(x + 7, y, bar_width, 8, 3))

  #calculate how wide the bar "fill" is and clamp it to at least 3 pixels
  fill_width = max(((bar_width - 2) / 100) * amount, 6)

  # if bar level is low then alternate fill with red to show a warning
  screen.brush = stats_brushes[name]
  if amount <= 30:
    ticks = time.ticks_ms()
    blink = round(ticks / 250) % 2 == 0
    if blink:
      screen.brush = stats_brushes["warning"]
  screen.draw(shapes.rounded_rectangle(x + 7 + 1, y + 1, fill_width, 6, 3))

  screen.blit(stats_icons[name], x, y - 3)

# draw monas statistics bars
def draw_stat_bars(mona):
  draw_bar("happy",  2, 41, mona.happy)
  draw_bar("hunger", 2, 58, mona.hunger)
  draw_bar("clean",  2, 75, mona.clean)
