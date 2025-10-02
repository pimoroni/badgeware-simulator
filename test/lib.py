# we need to call this in our "pre-setup code", the user shouldn't have to do it
# it's required to setup the global 'screen' object
from picovector import PicoVector, brushes, shapes, Image 
PicoVector.init()

class SpriteSheet:
  def __init__(self, file, columns, rows):
    self.image = Image.load(file)
    self.sw = int(self.image.width / columns)
    self.sh = int(self.image.height / rows)

    self.sprites = []
    for x in range(0, columns):
      column = []      
      for y in range(0, rows):
        column.append(self.image.window(self.sw * x, self.sh * y, self.sw, self.sh))
      self.sprites.append(column)

  def sprite(self, x, y):
    return self.sprites[x][y]
  
  def animation(self, x=0, y=0, count=None, horizontal=True):
    if not count:
      count = int(self.image.width / self.sw)
    return AnimatedSprite(self, x, y, count, horizontal)
  
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

class Font:
  def __init__(self, file, char_width, char_height):
    self.image = Image.load(file)
    self.cw = char_width
    self.ch = char_height

    columns = self.image.width / self.cw
    rows = self.image.height / self.ch

    self.chars = []
    for y in range(0, rows):
      for x in range(0, columns):
        self.chars.append(self.image.window(self.cw * x, self.ch * y, self.cw, self.ch))
  
  def text(self, image, x, y, text):    
    cx, cy = x, y # caret pos
    for char in text:
      char_idx = ord(char)
      if char_idx == 10:
        cx = x
        cy += self.ch
      elif char_idx == 32:
        cx += self.cw / 2
      elif char_idx < len(self.chars):        
        image.blit(self.chars[char_idx], cx, cy)
        cx += self.cw