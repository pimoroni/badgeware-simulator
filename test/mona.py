from lib import *
import time, random, math

# this class defines our little friend, modify it to change their behaviour!
#
# the ui will automatically update to reflect mona's state

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
    self.speed = 0.5

  def draw(self):
    # break out x and y into a shorter hand variables
    x, y = self.position

    # select sprite for current animation frame
    ticks = time.ticks_ms()
    image = self.animations[self.mood].frame(round(ticks / 100))
    width, height = image.width * 2, image.height * 2    

    # draw monas shadow
    screen.brush(brushes.color(0, 0, 0, 20))
    screen.draw(shapes.rectangle(x - (width / 2) + 5, y , width - 10, 2))
    screen.draw(shapes.rectangle(x - (width / 2) + 5 + 2, y - 2, width - 10 - 4, 4))

    # invert mona if they are walking left
    width *= self.direction
    
    # is mona floating?
    floating = math.sin(ticks / 250) * 5 + 5 if self.mood == "dead" else 0

    # offset sprite
    x -= (width / 2)
    y -= height + floating

    # draw mona
    alpha = 150 if self.mood == "dead" else 255
    image.alpha(alpha)
    screen.scale_blit(image, x, y, width, height)    
    
    # draw monas reflection
    image.alpha(int(alpha * 0.2))
    screen.scale_blit(image, x, self.position[1] - 2 + 22 + (floating / 2), width, -20)
    image.alpha(255)

  # set a new target position for mona to move to
  def move_to(self, target):
    self.target = target
    self.position_changed_at = time.time()

  # select a random position for mona to move to
  def move_to_random(self):
    self.move_to(random.randint(90, 130))

  # return the number of seconds since mona moved
  def time_since_last_position_change(self):
    return time.time() - self.position_changed_at

  # change monas mood
  def set_mood(self, mood):
    self.mood = mood
    self.mood_changed_at = time.time()

  # update monas position
  def update(self):    
    # break out x and y into a shorter hand variables
    x, y = self.position    

    # if mona isn't at their target position then move towards it
    if x != self.target:      
      self.direction = 1 if x > self.target else -1
      self.position = (x - (self.speed * self.direction), y)

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