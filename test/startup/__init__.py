import json
import math
from lib import *

# animation settings
animation_duration = 3
fade_duration = 2
frame_count = 159
hold_frame = 113

# render the specified frame from the animation
current_frame = None
current_frame_filename = None
def show_frame(i, alpha=255):
  # check if this frame needs loading
  global current_frame, current_frame_filename
  filename = f"frames/intro_{i:05d}.png"
  if current_frame_filename != filename:
    screen.load_into(filename)

  #current_frame.alpha = int(alpha)

  # render the frame
  #screen.blit(current_frame, 0, 0)
  current_frame_filename = filename

button_pressed_at = None
def update():
  global button_pressed_at

  time = io.ticks / 1000 # execution time in seconds

  # screen.brush = brushes.color(0, 0, 0)
  # screen.draw(shapes.rectangle(0, 0, 160, 120))

  frame, alpha = hold_frame, 255

  # determine which phase of the animation we're in (animation, hold, or fadeout)
  if time < animation_duration:
    # calculate which frame we're on and display it
    frame = round((time / animation_duration) * hold_frame)
  else:
    # if the startup animation has completed then check if the user has pressed a button
    if io.pressed:
      button_pressed_at = time

  if button_pressed_at:
    time_since_pressed = time - button_pressed_at
    if time_since_pressed < fade_duration:
      # calculate which frame we're on and display it
      frame = round((time_since_pressed / fade_duration) * (frame_count - hold_frame)) + hold_frame
      alpha = 255 - ((time_since_pressed / fade_duration) * 255)
    else:

      # this is where we would return control to the menu
      return

  show_frame(frame, alpha)

  return True