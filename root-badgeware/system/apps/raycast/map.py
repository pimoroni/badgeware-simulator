class Map:
  def __init__(self, width, height):
    self.width = width
    self.height = height

    self.flags = bytearray(self.width * self.height)
    self.textures = bytearray(self.width * self.height)

  def set_tile(self, x, y, flags, texture):
    self.flags[y * self.width + x] = flags
    self.textures[y * self.width + x] = texture

  def get_tile(self, x, y):
    return self.flags[y * self.width + x], self.textures[y * self.width + x]

  def is_solid(self, x, y):
    return self.flags[int(y) * self.width + int(x)] & 0b10000000