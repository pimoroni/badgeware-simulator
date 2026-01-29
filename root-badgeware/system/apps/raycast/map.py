class MapTile:
  def __init__(self):
    self.solid = False
    self.texture_id = 0
    pass

class Map:
  def __init__(self, width, height):
    self.width = width
    self.height = height
    self.tiles = []
    for _ in range(width):
      column = []
      for _ in range(height):
        column.append(MapTile())
      self.tiles.append(column)

  # return the MapTile object at supplied position
  def get_tile(self, x, y):
    if x < 0 or x >= self.width: return None
    if y < 0 or y >= self.height: return None
    return self.tiles[int(x)][int(y)]

  # converts map tile data into a compact representation used by the dda
  # algorithm
  def build_dda_flags(self):
    flags = bytearray(self.width * self.height)

    for y in range(self.height):
        for x in range(self.width):
            flags[y * self.width + x] = 128 if self.get_tile(x, y).solid else 0

    return flags
