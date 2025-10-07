import math
from lib import *
import ui
from mona import Mona

mona = Mona(82) # create mona!

def game_update(ticks):
  # implement the game logic here, this is just some dummy nonsense to fake it
  mona.happy = (math.sin(ticks / 3000) * 50) + 50
  mona.hunger = (math.sin(ticks / 1000) * 50) + 50
  mona.clean = (math.cos(ticks / 1500) * 50) + 50

  # if is_pressed(BUTTON_A):
  #   print("A")

  if mona.time_since_last_mood_change() > 2:
    mona.random_mood()

  if mona.time_since_last_position_change() > 3:    
    mona.move_to_random()
  # end of game logic here

def update(ticks):
  # update the game state based on user input and timed events
  game_update(ticks)

  # update monas state (position)
  mona.update()
  
  # draw the background scene
  ui.background(ticks, mona)
  
  # draw our little friend
  mona.draw()
  
  # draw the user interface elements
  ui.draw_stat_bars(mona)  
  ui.draw_buttons()  
  ui.draw_header()

  return True
