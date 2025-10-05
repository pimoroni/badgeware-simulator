import time
from lib import *

# load user interface sprites
icons = SpriteSheet(f"test/sprites/icons.png", 10, 1)

# load in the font - font sheet generated from 
# https://qwerasd205.github.io/PixelCode/
pixel_code = Font("test/pixelcode-font.6x12.png", 6, 12)

# brushes to match monas stats
stats_brushes = {
  "happy": brushes.color(239, 66, 229, 150),
  "hunger": brushes.color(90, 239, 66, 150),
  "clean": brushes.color(66, 180, 239, 150),
  "warning": brushes.color(255, 0, 0, 200)
}

# icons to match monas stats
stats_icons = {
  "happy": icons.sprite(0, 0),
  "hunger": icons.sprite(1, 0),
  "clean": icons.sprite(2, 0)
}

# ui outline (contrast) colour
outline = brushes.color(20, 30, 40, 150)

# draw the title banner
def draw_header():
  screen.brush(outline)
  screen.draw(shapes.rounded_rectangle(40, 1, 160 - 80, 15, 3))
  #screen.draw(shapes.rectangle(0, 0, 160, 14))
  pixel_code.text(screen, 52, 2, "monagotchi")
 
def draw_buttons():
  draw_button(  1, 102, stats_brushes["happy"], "A", "play")
  draw_button( 54, 102, stats_brushes["hunger"], "B", "feed")
  draw_button(107, 102, stats_brushes["clean"], "C", "clean")

def draw_button(x, y, brush, button, label):  
  button_width = 50
  
  # draw the button shadow
  screen.brush(outline)
  screen.draw(shapes.rounded_rectangle(x + 2, y + 2, button_width, 15, 6))

  # draw the button outline
  screen.brush(outline)
  screen.draw(shapes.rounded_rectangle(x, y, button_width, 15, 6))

  # draw the button fill  
  screen.brush(brushes.color(60, 80, 100))
  screen.draw(shapes.rounded_rectangle(x + 1, y + 1, button_width - 2, 15 - 2, 6))
  pixel_code.text(screen, x + 17, y + 1, label)

  # draw the button action key
  screen.brush(brush)
  screen.draw(shapes.rounded_rectangle(x + 1, y + 1, 13, 13, 6))
  pixel_code.text(screen, x + 5, y + 1, button)
  

def draw_bar(name, x, y, amount):  
  bar_width = 40

  # draw the bar background
  screen.brush(outline)    
  screen.draw(shapes.rounded_rectangle(x + 11, y, bar_width, 10, 3))

  #calculate how wide the bar "fill" is and clamp it to at least 3 pixels
  fill_width = max(((bar_width - 2) / 100) * amount, 6)

  # if bar level is low then alternate fill with red to show a warning
  screen.brush(stats_brushes[name])
  if amount < 25:
    ticks = time.ticks_ms()
    blink = round(ticks / 250) % 2 == 0
    if blink:
      screen.brush(stats_brushes["warning"])
  screen.draw(shapes.rounded_rectangle(x + 11 + 1, y + 1, fill_width, 8, 3))
  
  screen.blit(stats_icons[name], x, y + 1)

  
def draw_stat_bars(mona): 
  draw_bar("happy",  2, 33, mona.happy)
  draw_bar("hunger", 2, 50, mona.hunger)
  draw_bar("clean",  2, 67, mona.clean)


# helper functions
def rect_deflate(rect):
  return (rect[0] + 1, rect[1] + 1, rect[2] - 1, rect[3] - 1)
