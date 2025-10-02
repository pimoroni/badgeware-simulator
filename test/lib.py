# we need to call this in our "pre-setup code", the user shouldn't have to do it
# it's required to setup the global 'screen' object
from picovector import PicoVector, brushes, shapes, Image 
PicoVector.init()

class SpriteSheet:
  def __init__(self, file, sprite_width, sprite_height):
    self.image = Image.load(file)
    self.sw = sprite_width
    self.sh = sprite_height

    columns = self.image.width / self.sw
    rows = self.image.height / self.sh

    self.sprites = []
    for x in range(0, columns):
      column = []      
      for y in range(0, rows):
        column.append(self.image.window(self.sw * x, self.sh * y, self.sw, self.sh))
      self.sprites.append(column)

  def sprite(self, x, y):
    return self.sprites[x][y]
  
class AnimatedSprite:  
  def __init__(self, spritesheet, x, y, count, horizontal=True):
    self.spritesheet = spritesheet
    self.frames = []    
    for _ in range(0, count):
      self.frames.append((x, y))
      if horizontal:
        x += 1
      else:
        y += 1 

  def frame(self, frame_index = 0):
    frame_index %= len(self.frames)
    return self.spritesheet.sprite(self.frames[frame_index][0], self.frames[frame_index][1])
