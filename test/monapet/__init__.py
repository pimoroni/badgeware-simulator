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
        mona.do_action("heart")
        happiness += PLAY_VALUE

    if io.BUTTON_B in io.pressed:
      if hunger < MAX_HUNGER:
        mona.do_action("eating")
        hunger += FEED_VALUE

    if io.BUTTON_C in io.pressed:
      if cleanliness < MAX_CLEANLINESS:
        mona.do_action("dance")
        cleanliness += CLEAN_VALUE

    if mona.time_since_last_position_change() > 5:
      mona.move_to_random()

    if mona.time_since_last_mood_change() > 8:
      mona.random_idle()

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
    ui.draw_bar("happy",  2, 41, mona.happy)
    ui.draw_bar("hunger", 2, 58, mona.hunger)
    ui.draw_bar("clean",  2, 75, mona.clean)

    ui.draw_button(  4, 100, "play", mona.current_action() == "heart")
    ui.draw_button( 55, 100, "feed", mona.current_action() == "eating")
    ui.draw_button(106, 100, "clean", mona.current_action() == "dance")
  else:
    ui.draw_button(55, 102, brushes.color(30, 40, 50, 100), "B", "Reset")

  ui.draw_header()

  return True
