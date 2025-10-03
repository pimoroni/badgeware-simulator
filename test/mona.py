from lib import *
import time, random, math

# this class defines our little friend, modify it to change their behaviour!
class Mona:
  moods = []
  animations = {}

  def __init__(self, y):    
    self.happy = 50
    self.hunger = 80
    self.clean = 40
    self.mood = "default"
    self.mood_changed_at = time.time()
    self.position_changed_at = time.time()
    self.position = (80, y + 2)
    self.direction = 1
    self.target = 80

  def draw(self):
    x, y = self.position

    # select sprite for current animation frame
    ticks = time.ticks_ms()
    image = self.animations[self.mood].frame(round(ticks / 100))
    width, height = image.width * 2, image.height * 2    

    # draw monas shadow
    screen.brush(brushes.color(0, 0, 0, 20))
    screen.draw(shapes.rectangle(x - (width / 2) + 5, y , x + (width / 2) - 5, y + 2))
    screen.draw(shapes.rectangle(x - (width / 2) + 5 + 2, y - 2, x + (width / 2) - 5 - 2, y + 2 + 2))

    # invert mona if they are walking left
    width *= self.direction
    
    # is mona floating?
    float = math.sin(ticks / 250) * 5 + 5 if self.mood == "dead" else 0

    # offset sprite
    x -= (width / 2)
    y -= height + float

    # draw mona
    alpha = 150 if self.mood == "dead" else 255
    image.alpha(alpha)
    screen.scale_blit(image, x, y, width, height)    
    
    # draw monas reflection
    image.alpha(int(alpha * 0.2))
    screen.scale_blit(image, x, self.position[1] - 2 + 22 + (float / 2), width, -20)
    image.alpha(255)

  # set a new target position for mona to move to
  def move_to(self, target):
    self.target = target
    self.position_changed_at = time.time()

  # select a random position for mona to move to
  def move_to_random(self):
    self.move_to(random.randint(40, 120))

  # return the number of seconds since mona moved
  def time_since_last_position_change(self):
    return time.time() - self.position_changed_at

  # change monas mood
  def set_mood(self, mood):
    self.mood = mood
    self.mood_changed_at = time.time()

  # update monas position and stats
  def update(self):
    self.hunger += 0.1
    self.clean -= 0.1
    if self.hunger > 100:
      self.hunger = 0
    if self.clean < 0:
      self.clean = 100
    if self.position[0] != self.target:
      if self.position[0] > self.target:
        self.position = (self.position[0] - 0.25, self.position[1])
        self.direction = 1
      else:
        self.position = (self.position[0] + 0.25, self.position[1])
        self.direction = -1

  # select a random mood for mona
  def random_mood(self):
    self.set_mood(random.choice(Mona.moods))

  # return the number of seconds since monas mood changed
  def time_since_last_mood_change(self):
    return time.time() - self.mood_changed_at
      


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
for name, frame_count in animations.items():
  sprites = SpriteSheet(f"test/sprites/mona-{name}.gif.png", frame_count, 1)
  Mona.animations[name] = sprites.animation()

Mona.moods = list(Mona.animations.keys())
