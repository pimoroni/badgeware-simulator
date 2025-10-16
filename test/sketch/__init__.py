import math
from lib import *

screen.antialias = Image.X2
canvas_area = (10, 15, 140, 85)
canvas = Image(0, 0, canvas_area[2], canvas_area[3])

font = PixelFont.load("../assets/fonts/vest.ppf")
cursor = (canvas_area[2] / 2, canvas_area[3] / 2)
mona = SpriteSheet(f"../assets/mona-sprites/mona-dance.png", 6, 1).animation()

left_dial_angle = 0
right_dial_angle = 0
def draw_dial(angle, left=True):
  radius = 12

  pos = (5, 115)
  if left == False:
    pos = (155, 115)

  screen.brush = brushes.color(0, 0, 0, 40)
  screen.draw(shapes.circle(pos[0] + (2 if left else -2), pos[1], radius + 3))

  screen.brush = brushes.color(150, 160, 170)
  screen.draw(shapes.circle(pos[0] + (2 if left else -2), pos[1], radius))

  screen.brush = brushes.color(220, 220, 230)
  screen.draw(shapes.circle(*pos, radius))

  screen.brush = brushes.color(180, 180, 210)
  ticks = 20
  for i in range(0, ticks):
    deg = angle + (i * 360 / ticks)
    r = deg * (math.pi / 180.0)

    ox = pos[0] + math.sin(r) * radius
    oy = pos[1] + math.cos(r) * radius

    ix = pos[0] + math.sin(r) * (radius - 2)
    iy = pos[1] + math.cos(r) * (radius - 2)

    screen.draw(shapes.line(ix, iy, ox, oy, 1.5))

def draw_cursor():
  cx = int(cursor[0] + canvas_area[0])
  cy = int(cursor[1] + canvas_area[1])
  # draw the current cursor
  i = (math.sin(io.ticks / 250) * 127) + 127
  screen.brush = brushes.xor(i, i, i)
  screen.draw(shapes.rectangle(cx + 2, cy, 2, 1))
  screen.draw(shapes.rectangle(cx - 3, cy, 2, 1))
  screen.draw(shapes.rectangle(cx, cy + 2, 1, 2))
  screen.draw(shapes.rectangle(cx, cy - 3, 1, 2))

last_cursor = None
last_cursor_move = None
def update():
  global cursor, last_cursor, last_cursor_move
  global left_dial_angle, right_dial_angle

  # update the cursor position based on user input
  if not last_cursor_move or (io.ticks - last_cursor_move) > 20:
    if io.BUTTON_A in io.held:
      cursor = (cursor[0] - 1, cursor[1])
      left_dial_angle += 5
    if io.BUTTON_C in io.held:
      cursor = (cursor[0] + 1, cursor[1])
      left_dial_angle -= 5
    if io.BUTTON_UP in io.held:
      cursor = (cursor[0], cursor[1] - 1)
      right_dial_angle -= 5
    if io.BUTTON_DOWN in io.held:
      cursor = (cursor[0], cursor[1] + 1)
      right_dial_angle += 5
    last_cursor_move = io.ticks

  if cursor != last_cursor:
    # clamp cursor to canvas bounds
    cursor = (
      min(canvas_area[2], max(0, cursor[0])),
      min(canvas_area[3] - 1, max(0, cursor[1]))
    )

    # if clear button is pressed then clear the canvas


    canvas.brush = brushes.color(105, 105, 105)
    canvas.draw(shapes.rectangle(int(cursor[0]), int(cursor[1]), 1, 1))

  last_cursor = cursor


  screen.brush = brushes.color(170, 45, 40)
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  screen.font = font
  w, _ = screen.measure_text("monasketch")
  screen.brush = brushes.color(240, 210, 160)
  screen.text("monasketch", 80 - (w / 2) - 1, -1)
  screen.brush = brushes.color(190, 140, 80, 100)
  screen.text("monasketch", 80 - (w / 2), 0)

  # draw the canvas background and screen shadows
  screen.brush = brushes.color(210, 210, 210)
  screen.draw(shapes.rounded_rectangle(*canvas_area, 6))
  screen.brush = brushes.color(180, 180, 180)
  screen.draw(shapes.rounded_rectangle(canvas_area[0] + 3, canvas_area[1], canvas_area[2] - 5, 2, 2))
  screen.draw(shapes.rounded_rectangle(canvas_area[0], canvas_area[1] + 3, 2, canvas_area[3] - 5, 2))

  screen.brush = brushes.color(255, 255, 255, 100)
  screen.draw(shapes.rectangle(canvas_area[0] - 3, canvas_area[1] + 5, 1, canvas_area[3] - 10, 2))
  screen.draw(shapes.rectangle(canvas_area[0] + canvas_area[2] + 2, canvas_area[1] + 5, 1, canvas_area[3] - 10, 2))

  screen.brush = brushes.color(255, 255, 255, 50)
  screen.draw(shapes.line(70, 50, 50, 80, 2))

  draw_dial(left_dial_angle, True)
  draw_dial(right_dial_angle, False)

  screen.blit(canvas, canvas_area[0], canvas_area[1])
  draw_cursor()

  frame = int(io.ticks / 150)
  screen.blit(mona.frame(frame), 10, 76)

  return True