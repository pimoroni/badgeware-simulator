import math
from lib import *
import ui
from mona import Mona

mona = Mona(82) # create mona!

# Max values for stats. Value is the number of seconds to go from 100% to 0%
MAX_HUNGER = 1200
MAX_HAPPINESS = 1800
MAX_CLEANLINESS = 2400

# Stat increase values are 30% of the MAX
FEED_VALUE = 0.3 * MAX_HUNGER
PLAY_VALUE = 0.3 * MAX_HAPPINESS
CLEAN_VALUE = 0.3 * MAX_CLEANLINESS

dead = False
hunger = MAX_HUNGER
happiness = MAX_HAPPINESS
cleanliness = MAX_CLEANLINESS
last_update = 0


def reset_mona():
  global dead, happiness, hunger, cleanliness, last_update

  dead = False
  hunger = MAX_HUNGER
  happiness = MAX_HAPPINESS
  cleanliness = MAX_CLEANLINESS
  last_update = 0
  mona.set_mood("default")


def game_update():
  global dead, happiness, hunger, cleanliness, last_update

  if not dead:
    mona.happy = (happiness / MAX_HAPPINESS) * 100
    mona.hunger = (hunger / MAX_HUNGER) * 100
    mona.clean = (cleanliness / MAX_CLEANLINESS) * 100

    # Update the stats once a second
    if (io.ticks / 1000) - (last_update / 1000) > 1:
      hunger -= 1
      happiness -= 1
      cleanliness -= 1
      last_update = io.ticks

    if io.BUTTON_A in io.pressed:
      if happiness < MAX_HAPPINESS:
        mona.set_mood("heart")
        happiness += PLAY_VALUE

    if io.BUTTON_B in io.pressed:
      if hunger < MAX_HUNGER:
        mona.set_mood("eating")
        hunger += FEED_VALUE

    if io.BUTTON_C in io.pressed:
      if cleanliness < MAX_CLEANLINESS:
        mona.set_mood("dance")
        cleanliness += CLEAN_VALUE

    if mona.time_since_last_position_change() > 5:
      mona.move_to_random()

    # clamp the values
    hunger = max(0, min(hunger, MAX_HUNGER))
    happiness = max(0, min(happiness, MAX_HAPPINESS))
    cleanliness = max(0, min(cleanliness, MAX_CLEANLINESS))
    #print(mona.hunger, mona.happy, mona.clean)

    # If any of the stats are <= 30% then play the notify animation
    if min(mona.hunger, mona.happy, mona.clean) <= 30:
      mona.set_mood("notify")

    # end the game if any of the stats reach zero
    if 0 in (mona.hunger, mona.happy, mona.clean):
      dead = True

  else:
      mona.set_mood("dead")
      if io.BUTTON_B in io.pressed:
        reset_mona()

  # end of game logic here

def update():
  # update the game state based on user input and timed events
  game_update()

  # update monas state (position)
  mona.update()

  # draw the background scene
  ui.background(mona)

  # draw our little friend
  mona.draw()

  # draw the user interface elements
  if not dead:
    ui.draw_stat_bars(mona)
    ui.draw_buttons()
  else:
    ui.draw_button(55, 102, brushes.color(30, 40, 50, 100), "B", "Reset")

  ui.draw_header()

  import debug
  debug.update()

  return True
