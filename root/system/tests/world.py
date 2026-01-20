import math, json, gc

coastlines = []

def load_coastlines():
  print(gc.mem_free())
  with open("/system/assets/world.geo.json", "r") as f:
    data = json.loads(f.read())
    for country in data:
      for polygon in country["polygons"]:
        path = [vec2(p[0], -p[1]) for p in polygon]
        coastlines.append(shape.custom(path))

    print(gc.mem_free())

load_coastlines()

def update():
  screen.antialias = image.OFF
  screen.clear(color.rgb(20, 40, 60))

  i =  0
  pen(color.rgb(50, 90,60))
  for coastline in coastlines:
    i = i + 1
    x = math.sin(io.ticks / 1000) * 80
    y = math.cos(io.ticks / 700) * 60
    s = math.sin(io.ticks / 1000) * 1 + 2

    coastline.transform = mat3().translate(80 + x, 60 + y).scale(s, s)
    screen.shape(coastline)
