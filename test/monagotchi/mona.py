from lib import *
import time, random, math

# this class defines our little friend, modify it to change their behaviour!
#
# - move mona to a random location
# - change mona's mood
# - alter mona's stats (happiness, hunger, cleanliness)
# - change mona's appearance
#
# the ui will automatically update to reflect mona's state

class Mona:
  _moods = []
  _animations = {}

  def __init__(self, y):
    self._happy = 50
    self._hunger = 80
    self._clean = 40
    self._mood = None
    self._animation = None
    self._mood_changed_at = time.time()
    self._position_changed_at = time.time()
    self._position = (80, y + 2)
    self._direction = 1
    self._target = 80
    self._speed = 0.5
    self.set_mood("default")

  def draw(self):
    # break out x and y into a shorter hand variables
    x, y = self._position

    # select sprite for current animation frame
    ticks = time.ticks_ms()
    image = Mona._animations[self._mood].frame(round(ticks / 100))
    width, height = image.width * 2, image.height * 2

    # draw monas shadow
    screen.brush = brushes.color(0, 0, 0, 20)
    screen.draw(shapes.rectangle(x - (width / 2) + 5, y , width - 10, 2))
    screen.draw(shapes.rectangle(x - (width / 2) + 5 + 2, y - 2, width - 10 - 4, 4))

    # invert mona if they are walking left
    width *= self._direction

    # is mona floating?
    floating = math.sin(ticks / 250) * 5 + 5 if self._mood == "dead" else 0

    # offset sprite
    x -= (width / 2)
    y -= height + floating

    # draw mona
    alpha = 150 if self._mood == "dead" else 255
    image.alpha = alpha
    screen.scale_blit(image, x, y, width, height)

    # draw monas reflection
    image.alpha = int(alpha * 0.2)
    screen.scale_blit(image, x, self._position[1] - 2 + 22 + (floating / 2) + 1, width, -20)
    image.alpha = 255

  # set a new target position for mona to move to
  def move_to(self, target):
    self._target = target
    self._position_changed_at = time.time()

  # select a random position for mona to move to
  def move_to_random(self):
    self.move_to(random.randint(90, 130))

  # return the number of seconds since mona moved
  def time_since_last_position_change(self):
    return time.time() - self._position_changed_at

  # return monas current position
  def position(self):
    return self._position

  # change monas mood
  def set_mood(self, mood):
    if mood != self._mood:
      # load mood animation
      sprites = SpriteSheet(f"assets/mona-{mood}.gif.png", animations[mood], 1)
      self._animation = sprites.animation()

    self._mood = mood
    self._mood_changed_at = time.time()

  # increase or decrease monas statistics
  def happy(self, amount):
    self._happy = clamp(self._happy + amount, 0, 100)

  def clean(self, amount):
    self._clean = clamp(self._clean + amount, 0, 100)

  def hunger(self, amount):
    self._hunger = clamp(self._hunger + amount, 0, 100)

  # update monas position
  def update(self):
    # break out x and y into a shorter hand variables
    x, y = self._position

    # if mona isn't at their target position then move towards it
    if x != self._target:
      self._direction = 1 if x > self._target else -1
      self._position = (x - (self._speed * self._direction), y)

  # select a random mood for mona
  def random_mood(self):
    self.set_mood(random.choice(Mona._moods))

  # return the number of seconds since monas mood changed
  def time_since_last_mood_change(self):
    return time.time() - self._mood_changed_at

# define monas animations and the number of frames
animations = {
  "dance": 6,
  "code": 4,
  "dead": 7,
  "default": 11,
  "eating": 12,
  "heart": 14,
  "notify": 11
}

# load the spritesheets for monas animations
print("load spritesheets")
for name, frame_count in animations.items():
  sprites = SpriteSheet(f"assets/mona-{name}.gif.png", frame_count, 1)
  Mona._animations[name] = sprites.animation()
print("done")

Mona._moods = list(Mona._animations.keys())