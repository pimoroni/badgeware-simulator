import math
import random
from lib import *

sprites = SpriteSheet(f"assets/sprites.png", 7, 2)
background = Image.load(f"assets/background.png")
grass = Image.load(f"assets/grass.png")
cloud = Image.load(f"assets/cloud.png")
large_font = PixelFont.load("../assets/fonts/ignore.ppf")
small_font = PixelFont.load("../assets/fonts/nope.ppf")

class GameState:
  INTRO = 1
  PLAYING = 2
  GAME_OVER = 3

class Obstacle:
  obstacles = []
  next_spawn_time = None

  def spawn():
    Obstacle.obstacles.append(Obstacle())
    Obstacle.next_spawn_time = io.ticks + 1000

  def __init__(self):
    self.x = screen.width
    self.gap_height = 50
    self.gap_y = random.randint(5, screen.height - self.gap_height - 15)

  def update(self):
    self.x -= 1

  def draw(self):
    screen.scale_blit(sprites.sprite(6, 0), self.x, self.gap_y - 72, 24, 24)
    screen.scale_blit(sprites.sprite(6, 0), self.x, self.gap_y - 48, 24, 24)
    screen.scale_blit(sprites.sprite(6, 1), self.x, self.gap_y - 24, 24, 24)

    screen.scale_blit(sprites.sprite(6, 1), self.x, self.gap_y + self.gap_height, 24, -24)
    screen.scale_blit(sprites.sprite(6, 0), self.x, self.gap_y + self.gap_height + 24, 24, -24)
    screen.scale_blit(sprites.sprite(6, 0), self.x, self.gap_y + self.gap_height + 48, 24, -24)

def intro():
  global state

  screen.font = large_font
  screen.brush = brushes.color(20, 40, 60, 100)
  screen.text("FLAPPY MONA", 16, 31)
  screen.brush = brushes.color(255, 255, 255)
  screen.text("FLAPPY MONA", 15, 30)

  screen.font = small_font
  on = int(io.ticks / 500) % 2
  if on == 0:
    screen.brush = brushes.color(255, 255, 255)
    screen.text("Press A to start", 30, 70)

  if io.BUTTON_A in io.pressed:
    state = GameState.PLAYING
    Obstacle.next_spawn_time = io.ticks + 3000

def play():
  if io.BUTTON_A in io.pressed:
    pass # do a jump

  # update player and check for collision

  # update background

  # create new obstacles
  if Obstacle.next_spawn_time and io.ticks > Obstacle.next_spawn_time:
    Obstacle.spawn()

  # update obstacles
  for obstacle in Obstacle.obstacles:
    obstacle.update()
    obstacle.draw()
    #print("draw")

background_offset = 0
def draw_background():
  global background_offset
  background_offset += 1

  # draw the distance background
  for i in range(0, 3):
    bo = ((-background_offset / 3) % background.width) - screen.width
    screen.blit(background, bo + (background.width * i), 120 - background.height)

    # draw the cloud background
    bo = ((-background_offset / 3) % (cloud.width * 2)) - screen.width
    screen.blit(cloud, bo + (cloud.width * 2 * i), 20)

  for i in range(0, 3):
    # draw the grass layer
    bo = ((-background_offset / 1.5) % (grass.width)) - screen.width
    screen.blit(grass, bo + (grass.width * i), 120 - grass.height)


def game_over():
  pass


state = GameState.INTRO


def update():


  screen.brush = brushes.color(73, 219, 255)
  screen.draw(shapes.rectangle(0, 0, 160, 120))
  screen.blit(cloud, 0, 0)
  time.sleep(1)
  return True
  screen.brush = brushes.color(73, 219, 255)
  screen.draw(shapes.rectangle(0, 0, 160, 120))

  draw_background()

  if state == GameState.INTRO:
    intro()

  if state == GameState.PLAYING:
    play()

  if state == GameState.GAME_OVER:
    game_over()

  return True