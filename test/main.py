import math
from lib import io
import ui
from mona import Mona

mona = Mona(82) # create mona!

def game_update():
  # implement the game logic here, this is just some dummy nonsense to fake it
  mona.happy = (math.sin(io.ticks / 3000) * 50) + 50
  mona.hunger = (math.sin(io.ticks / 1000) * 50) + 50
  mona.clean = (math.cos(io.ticks / 1500) * 50) + 50

  if io.BUTTON_A in io.pressed: # Left
    print("A")

  if io.BUTTON_A in io.changed: # Left
    state = "pressed" if io.BUTTON_A in io.pressed else "released"
    print(f"A Changed! {state}")

  if io.BUTTON_B in io.pressed: # Down
    print("B")

  if io.BUTTON_C in io.pressed: # Right
    print("C")

  if io.BUTTON_UP in io.pressed: # Right shift
    print("Up")

  if io.BUTTON_DOWN in io.pressed: # Up
    print("Down")

  if io.BUTTON_HOME in io.pressed: # H - okay I ran out of keys that wouldn't conflict the repl
    print("Home")

  if mona.time_since_last_mood_change() > 2:
    mona.random_mood()

  if mona.time_since_last_position_change() > 3:    
    mona.move_to_random()
  # end of game logic here

def update():
  # update the game state based on user input and timed events
  game_update()

  # update monas state (position)
  mona.update()
  
  # draw the background scene
  ui.background(io.ticks, mona)

  # draw our little friend
  mona.draw()
  
  # draw the user interface elements
  ui.draw_stat_bars(mona)  
  ui.draw_buttons()  
  ui.draw_header()

  return True