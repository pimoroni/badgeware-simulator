mipmap_levels = 3

# allocate a texture atlas allowing up to 256 textures with multiple mipmap levels
atlas = []
for i in range(256):
  atlas.append([None] * mipmap_levels)

def a(p):
  return (p >> 24) & 0xff

def b(p):
  return (p >> 16) & 0xff

def g(p):
  return (p >> 8) & 0xff

def r(p):
  return (p >> 0) & 0xff

def load_texture(index, src):
  texture = image.load(src)
  atlas[index][0] = texture

  # generate mipmaps
  for i in range(1, mipmap_levels):
    mmw = int(texture.width / 2)
    mmh = int(texture.height / 2)
    mipmap = image(mmw, mmh)

    #mipmap.blit(texture, rect(0, 0, texture.width, texture.height), rect(0, 0, mmw, mmh))
    for y in range(mmh):
      for x in range(mmw):
        c0 = texture.get(x * 2 + 0, y * 2 + 0)
        c1 = texture.get(x * 2 + 1, y * 2 + 0)
        c2 = texture.get(x * 2 + 1, y * 2 + 1)
        c3 = texture.get(x * 2 + 0, y * 2 + 1)

        mmr = (r(c0.p) + r(c1.p) + r(c2.p) + r(c3.p)) / 4
        mmg = (g(c0.p) + g(c1.p) + g(c2.p) + g(c3.p)) / 4
        mmb = (b(c0.p) + b(c1.p) + b(c2.p) + b(c3.p)) / 4
        mma = (a(c0.p) + a(c1.p) + a(c2.p) + a(c3.p)) / 4

        mipmap.pen = color.rgb(mmr, mmg, mmb, mma)
        mipmap.put(x, y)

    atlas[index][i] = mipmap

    texture = mipmap
