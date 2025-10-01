import math, time
import gc

# we need to call this in our "pre-setup code", the user shouldn't have to do it
# it's required to setup the global 'screen' object
from picovector import PicoVector, brushes, shapes, Image 
PicoVector.init()

# load an image asset from the filesystem
totoro = Image.load("test/totoro.png")

test = Image(50, 50)

#regular_polygon = shapes.regular_polygon(60, 60, r1, 5)

# circle = v.circle(240, 60, r1)
# squircle = v.squircle(150, 60, r1, 5)
# star = v.star(60, 150, 24, r2, r1)
# pie = v.pie(150, 150, 0, 270, r1)

brush_grid_1 = brushes.color(20, 40, 60, 255)
brush_grid_2 = brushes.color(60, 40, 20, 255)

def update(ticks):
  #print(totoro.width, totoro.height)
  #print(test.width, test.height)

  free = round(gc.mem_free() / 1024)
  #print(f"{ticks} ({free}kb free)")
  #v.loop()

  #v.brush(brush_grid_1)
  screen.brush(brush_grid_1)
  screen.clear()
  
  #v.brush(brush_grid_2)
  screen.brush(brush_grid_2)


  start = time.time()
  for y in range(0, 12):
    for x in range(0, 16):
      if (x + y) % 2 == 0:
        screen.draw(shapes.rectangle(x * 10, y * 10, x * 10 + 10, y * 10 + 10))
  end = time.time()
  delta = round((end - start) * 1000)
  #print("grid took", delta, "ms")
      

  screen.blit(totoro, 50, 0)
  
  b = [
    [brushes.color(200, 100, 100, 100)],
    [brushes.brighten(20)],
    [brushes.xor(255, 255, 255)],
    [brushes.blur(1), brushes.color(20, 40, 60, 100)]
  ]

  s = ((math.sin(ticks / 500) + math.cos(ticks / 500)) + 2.1) * 5

  for y in range(0, 3):
    yo = y * 40 + 20
    for x in range(0, 4):
      xo = x * 40 + 20

      brush_idx = x + y * 4

      if brush_idx < len(b):
        for b2 in b[brush_idx]:
          screen.brush(b2)

          #print(xo, yo, brush_idx)
          steps = 5
          start = time.time()
          for i in range(0, steps):
            angle = (360 / steps) * i
            angle += ticks / 20
            radians = angle * (math.pi / 180)
            lx = math.sin(radians) * 10
            ly = math.cos(radians) * 10
            squircle = shapes.squircle(xo + lx, yo + ly, s, 5)

            #squircle = v.rectangle(xo + lx - s, yo + ly - s, xo + lx + s, yo + ly + s)

            screen.draw(squircle)
          end = time.time()
          delta = round((end - start) * 1000)
          #print("brush", brush_idx, "took", delta, "ms")

  
  #time.sleep(0.1)

  
#  squircle = v.squircle(160 - x, 120 - y, s, 5)
#  v.draw(squircle)


#  v.draw(regular_polygon)
#  v.draw(circle)  
  #v.draw(pie)
##  v.draw(star)
  #print(ticks)
  return True
# 