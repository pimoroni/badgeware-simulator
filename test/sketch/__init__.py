import math
from lib import *
import ui

canvas = Image(0, 0, ui.canvas_area[2], ui.canvas_area[3])
cursor = (ui.canvas_area[2] / 2, ui.canvas_area[3] / 2)
mona_position = (10, 76)
mona_target = (10, 76)
mona_direction = 1

last_cursor_move = None
def update_cursor():
  global cursor, last_cursor_move
  global left_dial_angle, right_dial_angle

  # update the cursor position based on user input and shift the dial animation
  if not last_cursor_move or (io.ticks - last_cursor_move) > 20:
    if io.BUTTON_A in io.held:
      cursor = (cursor[0] - 1, cursor[1])
    if io.BUTTON_C in io.held:
      cursor = (cursor[0] + 1, cursor[1])
    if io.BUTTON_UP in io.held:
      cursor = (cursor[0], cursor[1] - 1)
    if io.BUTTON_DOWN in io.held:
      cursor = (cursor[0], cursor[1] + 1)
    last_cursor_move = io.ticks

  # clamp cursor to canvas bounds
  cursor = (
    min(ui.canvas_area[2], max(0, cursor[0])),
    min(ui.canvas_area[3] - 1, max(0, cursor[1]))
  )

  # set the dial angles relative to the cursor position so they animate as
  # the cursor moves
  left_dial_angle = -cursor[0] * 3
  right_dial_angle = cursor[1] * 3

def update_mona():
  global mona_position
  if mona_position[0] < mona_target[0]:
    mona_position = (mona_position[0] + 1, mona_position[1])
  if mona_position[0] > mona_target[0]:
    mona_position = (mona_position[0] - 1, mona_position[1])

def update():
  global mona_target, mona_direction

  update_cursor()
  update_mona()

  # draw to the canvas at the cursor position
  canvas.brush = brushes.color(105, 105, 105)
  canvas.draw(shapes.rectangle(int(cursor[0]), int(cursor[1]), 1, 1))

  ui.draw_background()

  if cursor[0] < 30:
    mona_target = (120, 76)
    mona_direction = 1
  if cursor[0] > ui.canvas_area[2] - 30:
    mona_target = (10, 76)
    mona_direction = -1

  ui.draw_dial(left_dial_angle, (5, 115))
  ui.draw_dial(right_dial_angle, (155, 115))

  screen.blit(canvas, ui.canvas_area[0], ui.canvas_area[1])
  ui.draw_cursor(cursor)

  ui.draw_mona(mona_position, mona_direction)

  return True