from picovector import algorithm

mode(HIRES)

screen.font = pixel_font.load("/system/assets/fonts/ark.ppf")
screen.antialias = screen.X2
image = image.load("/system/assets/mona-sprites/mona-heart.png").window(0, 0, 24, 24)
sprites = SpriteSheet("/system/assets/mona-sprites/mona-heart.png", 14, 1)
import math

def update():
  global i
  pen(20, 40, 60)
  screen.clear()

  i = round(io.ticks / 200)
  i %= 10

  message = f"""[pen:255,0,0]Lorem [pen:255,255,0]ipsum [circle:] [pen:0,255,0]dolor [pen:0,255,255]sit[custom:{i}][pen:0,0,255]amet, [circle:] consectetur adipiscing elit, [pen:0,0,255]sed do eiusmod [circle:] tempor incididunt ut labore et dolore magna aliqua.

Ut [circle:] enim [custom:{i}][custom:{i}][custom:{i}][custom:{i}] ad minim veniam, [pen:255,0,0]quis nostrud exercitation [custom:{i}] ullamco laboris nisi ut aliquip ex ea commodo consequat.

[custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}][custom:{i}]

Duis aute irure dolor [circle:] in reprehenderit in [custom:{i}] voluptate velit esse [pen:0,255,0]cillum dolore eu fugiat nulla pariatur.

Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."""

  pen(0, 255, 0)

  x = math.sin(io.ticks / 400) * 40 + 50
  y = math.sin(io.ticks / 600) * 40 + 50
  width = 320 - x + math.sin(io.ticks / 800) * 40 - 50
  height = 240 - y + math.sin(io.ticks / 1000) * 40 - 50
  tokens = tokenise(screen, message)
  bounds = rect(x, y, width, height)
  measure(screen, tokens, bounds, line_spacing=1.2, word_spacing=1)
  import time

  pen(60, 80, 100, 100)
  screen.line(bounds.x, bounds.y, bounds.x + bounds.w, bounds.y)
  screen.line(bounds.x, bounds.y, bounds.x, bounds.y + bounds.h)
  screen.line(bounds.x, bounds.y + bounds.h, bounds.x + bounds.w, bounds.y + bounds.h)
  screen.line(bounds.x + bounds.w, bounds.y, bounds.x + bounds.w, bounds.y + bounds.h)

  #result = wrap_and_measure(screen, text, 280)
  #print(result)
  # c = point(0, 0)
  # for r in result:
  #   text, width = r
  #   screen.text(text, c.x, c.y)

  #   c.y += screen.font.height

  #dda()


WORD = 1
SPACE = 2
LINE_BREAK = 3


def pen_command(image, parameters, cursor, measure):
  if measure:
    return 0

  r = int(parameters[0])
  g = int(parameters[1])
  b = int(parameters[2])
  pen(r, g, b)

def custom_command(image, parameters, cursor, measure):
  if measure:
    return 24
  idx = int(parameters[0])
  image.blit(sprites.sprite(idx, 0), cursor.x, cursor.y - 10)


def circle_command(image, parameters, cursor, measure):
  if measure:
    return 12

  image.shape(shape.circle(cursor.x + 6, cursor.y + 7, 6))


command_map = {
  "pen": pen_command,
  "custom": custom_command,
  "circle": circle_command,
}



def tokenise(image, text):
  tokens = []

  for line in text.splitlines():
    start, end = 0, 0
    i = 0
    while end < len(line):
      # check for a command
      if line.find("[", start) == start:
        end = line.find("]", start)
        # look ahead to see if this is an escape code
        command = line[start + 1:end]
        code, parameters = command.split(":")
        parameters = parameters.split(",")

        if code in command_map:
          w = command_map[code](None, parameters, None, True)
          tokens.append((command_map[code], w, tuple(parameters)))

        start = end + 1
        continue

      i += 1

      # search for the next space
      end = line.find(" ", start)
      if end == -1: end = len(line)

      command_start = line.find("[", start)
      if command_start != -1 and command_start < end:
        end = command_start

      # measure the text up to the space
      if end > start:
        width, _ = image.measure_text(line[start:end])
        tokens.append((WORD, width, line[start:end]))

      start = end
      if end < len(line) and line[end] == " ":
        tokens.append((SPACE,))
        start += 1


    tokens.append((LINE_BREAK,))

  return tokens

def measure(image, text, bounds, line_spacing=1, word_spacing=1):

  if isinstance(text, list):
    tokens = text
  else:
    tokens = tokenise(image, text)

  window = image.window(bounds)
  window.font = image.font
  c = point()
  b = rect()
  for token in tokens:
    if token[0] == WORD:
      if c.x + token[1] > bounds.w:
        c.x = 0
        c.y += window.font.height * line_spacing
      window.pen = image.pen # nasty hack while global brush isn't set properly
      window.text(token[2], c.x, c.y)
      c.x += token[1]
    elif token[0] == SPACE:
      c.x += (window.font.height / 3) * word_spacing
    elif token[0] == LINE_BREAK:
      c.x = 0
      c.y += window.font.height * line_spacing
    else:
      if c.x + token[1] > bounds.w:
        c.x = 0
        c.y += window.font.height * line_spacing

      token[0](window, token[2], c, False)
      c.x += token[1]

    b.w = max(b.w, c.x)
    b.h = max(b.h, c.y)

  return b

  result = 0
  # result = []
  # for line in text.splitlines():
  #   # if max_width is specified then perform word wrapping
  #   if max_width:
  #     # setup a start and end cursor to traverse the text
  #     start, end = 0, 0
  #     last_width = 0
  #     i = 0
  #     while True:
  #       i += 1
  #       # search for the next space
  #       end = line.find(" ", end)
  #       if end == -1:
  #         end = len(line)

  #       # measure the text up to the space
  #       width, _ = image.measure_text(line[start:end])
  #       if width >= max_width:
  #         # line exceeded max length
  #         new_end = line.rfind(" ", start, end)
  #         if new_end == -1:
  #           result.append((line[start:end], last_width))
  #           start = end + 1
  #         else:
  #           result.append((line[start:new_end], last_width))
  #           start = new_end + 1
  #       elif end == len(line):
  #         # reached the end of the string
  #         result.append((line[start:end], width))
  #         break

  #       # step past the last space
  #       end += 1
  #       last_width = width
  #   else:
  #     # no wrapping needed, just return the original line with its width
  #     width, _ = image.measure_text(line)
  #     result.append((line, width))

  return result



def dda():
  grid = 20

  p = point(
    math.sin(io.ticks / 1000) * 2,
    math.cos(io.ticks/ 2000) * 2
  )
  v = point(
    math.cos(io.ticks / 3000) * 100,
    math.sin(io.ticks/ 5000) * 100
  )

  intersections = algorithm.dda(p, v, 10)

  p.x = (p.x * grid) + 160
  p.y = (p.y * grid) + 120
  v.x = (v.x * grid)
  v.y = (v.y * grid)

  pen(40, 60, 80)
  for y in range(0, 240 / grid):
    screen.line(0, y * grid, 319, y * grid)

  for x in range(0, 320 / grid):
    screen.line(x * grid, 0, x * grid, 239)

  t = point(
    p.x + v.x,
    p.y + v.y
  )
  pen(100, 120, 140)
  screen.line(p, t)

  pen(255, 255, 255)
  screen.shape(shape.circle(p, 2))

  pen(0, 255, 0)
  screen.shape(shape.circle(t, 2))

  for intersection in intersections:
    ip, ig, offset, edge, distance = intersection
    ip.x = ip.x * grid + 160
    ip.y = ip.y * grid + 120
    pen(0, 255, 0)
    screen.shape(shape.circle(ip, 2))

def magic_sprite(src, pos, scale=1, angle=0):
  w, h = src.width, src.height
  t = mat3().translate(*pos).scale(scale, scale).rotate(angle).translate(-w / 2, -h)
  imgbrush = brush.image(src, t)
  pen(imgbrush)
  rect = shape.rectangle(0, 0, w, h)
  rect.transform = t
  screen.shape(rect)

def image_brush():
  rectangle_intersection()
  t = mat3().rotate(io.ticks / 100)

  imgbrush = brush.image(image, t)
  for y in range(-80, 240, 60):
    for x in range(-80, 320, 60):
      pen(20, 40, 60, 100)
      screen.shape(shape.circle(x, y, 30))
      pen(imgbrush)
      screen.shape(shape.circle(x, y, 30))

def custom_shape():
  pen(255, 0, 255)
  s = shape.custom([point(10, 10), point(20, 10), point(20, 20), point(10, 20)], [point(15, 15), point(25, 15), point(25, 25), point(15, 25)])
  s.transform = mat3().translate(160, 120).scale(5).rotate(io.ticks / 50)
  screen.shape(s)

def rectangle_intersection():
  r1s = 50
  r1x = (math.sin(io.ticks / 100) * 20) + 160 - r1s / 2
  r1y = (math.cos(io.ticks / 100) * 20) + 160 - r1s / 2
  r1 = rect(r1x, r1y, r1s, r1s)

  pen(255, 0, 0)
  screen.rectangle(r1)

  r2s = 50
  r2x = (math.sin(io.ticks / 200) * 40) + 160 - r1s / 2
  r2y = (math.cos(io.ticks / 200) * 40) + 160 - r1s / 2
  r2 = rect(r2x, r2y, r2s, r2s)

  pen(0, 0, 255)
  screen.rectangle(r2)

  r3 = r1.intersection(r2)
  pen(0, 255, 0)
  screen.rectangle(r3)

def line_clipping():

  pen(255, 255, 255)

  # line clipping to window
  p1 = point(
    int(math.sin(io.ticks / 500) * 20 + 0),
    int(math.sin(io.ticks / 400) * 30 + 0)
  )

  p2 = point(
    int(math.sin(io.ticks / 300) * 20 + 150),
    int(math.sin(io.ticks / 200) * 30 + 120)
  )

  w = screen.window(30, 30, 80, 80)
  w.line(p1, p2)

  # line clipping to rect
  p1 = point(
    int(math.sin(io.ticks / 500) * 20 + 0) + 100,
    int(math.sin(io.ticks / 400) * 30 + 0)
  )

  p2 = point(
    int(math.sin(io.ticks / 300) * 20 + 150) + 100,
    int(math.sin(io.ticks / 200) * 30 + 120)
  )

  algorithm.clip_line(p1, p2, rect(130, 30, 80, 80))
  screen.line(p1, p2)


def window_blit():
  w = screen.window(20, 20, 80, 80)
  screen.blit(w, 180, 100)

def transformed_sprite():
  scale = (math.sin(io.ticks / 1000) + 1.0) * 5 + 2
  angle = math.cos(io.ticks / 500) * 150
  magic_sprite(image, (160, 120), scale, angle)

def patterns():

  pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 100), (
    0b00000000,
    0b01111110,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b01111110,
    0b00000000))
  pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 255), 11)
  pen(pattern)
  screen.rectangle(0, 0, screen.width, screen.height)

  pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), (
    0b00000000,
    0b01111110,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b01111110,
    0b00000000))
  pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), 11)

  pen(pattern)

  screen.shape(shape.circle(160 + math.sin(io.ticks / 500) * 30, 120 + math.sin(io.ticks / 1000) * 30, 80))