import random
from lib import *
from user import User

phosphor = color.rgb(211, 250, 55, 150)
white = color.rgb(235, 245, 255)
faded = color.rgb(235, 245, 255, 100)
small_font = PixelFont.load("/system/assets/fonts/ark.ppf")
large_font = PixelFont.load("/system/assets/fonts/absolute.ppf")

# brush that degine the color used for each contribution level in the graph
level_brush = [
    color.rgb(  2,  15,  8),
    color.rgb(  2,  29,  11),
    color.rgb( 12,  54,  23),
    color.rgb( 23,  80,  33),
    color.rgb( 43, 105,  50),
]


def placeholder_if_none(text):
  if text: return text
  old_seed = random.seed()
  random.seed(int(io.ticks / 100))
  chars = "!\"£$%^&*()_+-={}[]:@~;'#<>?,./\\|"
  text = ""
  for _ in range(20):
      text += random.choice(chars)
  random.seed(old_seed)
  return text

def name_and_handle():
  # draw handle
  screen.font = large_font

  if User.handle:
    w, _ = screen.measure_text(User.handle)
    screen.pen = white
    screen.text(User.handle, 80 - (w / 2), 2)

  # draw name
  screen.font = small_font
  screen.pen = phosphor
  name = placeholder_if_none(User.name)
  w, _ = screen.measure_text(name)
  screen.text(name, 80 - (w / 2), 16)


def background():
  # clear the background
  screen.pen = color.rgb(0, 0, 0)
  screen.clear()

  # draw contribution graph background
  size = 15 # graph cell size
  graph_width = 53 * (size + 2) # overall width of graph

  # calculate a moving offset for drawing the graph background
  xo = int(-sin(io.ticks / 5000) * ((graph_width - 160) / 2)) + ((graph_width - 160) / 2)

  rect = shapes.rounded_rectangle(0, 0, size, size, 2)
  screen.pen = level_brush[1]
  for y in range(7):
    for x in range(53):
      # calculate offset for this graph cell on screen
      pos = (x * (size + 2) - xo, y * (size + 2) + 1)
      if pos[0] + size < 0 or pos[0] > 160: # skip tiles that aren't in view
        continue

      # if contribution level data is loaded then set graph cell fill color
      if User.levels:
        level = User.levels[x][y]
        screen.pen = level_brush[level]

      # transform the rect to the correct location on screen and draw
      rect.transform = Matrix().translate(*pos)
      screen.shape(rect)

# draw users statistics
def statistics():
  def fake_number():
    return random.randint(10000, 99999)

  def draw_statistic(title, value, x, y):
    screen.pen = white if value else faded
    screen.font = large_font
    screen.text(str(value) if value is not None else str(fake_number()), x, y)
    screen.font = small_font
    screen.pen = phosphor
    screen.text(title, x - 1, y + 13)

  draw_statistic("followers", User.followers, 88, 33)
  draw_statistic("contribs", User.contributions, 88, 62)
  draw_statistic("repos", User.repositories, 88, 91)

def avatar():
  # draw avatar imagee
  if not User.avatar:
    # create a spinning loading animation while we wait for the avatar to load
    screen.pen = phosphor
    squircle = shapes.squircle(0, 0, 10, 5)
    screen.pen = color.rgb(211, 250, 55, 50)
    for i in range(4):
      mul = sin(io.ticks / 1000) * 14000
      squircle.transform = Matrix().translate(42, 75).rotate(
        (io.ticks + i * mul) / 40).scale(1 + i / 1.3)
      screen.shape(squircle)
  else:
    screen.blit(User.avatar, 5, 37)

def no_secrets_error():
  screen.font = large_font
  screen.pen = white
  center_text("Missing Details!", 5)

  screen.text("1:", 10, 23)
  screen.text("2:", 10, 55)
  screen.text("3:", 10, 87)

  screen.pen = phosphor
  screen.font = small_font
  wrap_text("""Put your badge into\ndisk mode (tap\nRESET twice)""", 30, 24)
  wrap_text("""Edit 'secrets.py' to\nset WiFi details and\nGitHub username.""", 30, 56)
  wrap_text("""Reload to see your\nsweet sweet stats!""", 30, 88)


# tell the user that the connection failed :-(
def connection_error():
  screen.font = large_font
  screen.pen = white
  center_text("Connection Failed!", 5)

  screen.text("1:", 10, 63)
  screen.text("2:", 10, 95)

  screen.pen = phosphor
  screen.font = small_font
  wrap_text("""Could not connect\nto the WiFi network.\n\n:-(""", 16, 20)
  wrap_text("""Edit 'secrets.py' to\nset WiFi details and\nGitHub username.""", 30, 65)
  wrap_text("""Reload to see your\nsweet sweet stats!""", 30, 96)
