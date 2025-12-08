import sys
import os

sys.path.insert(0, "/system/apps/quest")
os.chdir("/system/apps/quest")
import gc

import micropython
import math
import time
import random
from badgeware import State, run
from picovector import dda
from badgeware import SpriteSheet

background = Image.load("assets/background.png")
screen.font = PixelFont.load("/system/assets/fonts/nope.ppf")


perfs = {}
def perf_clear():
    global perfs
    perfs = {}

def perf_start(name):
    global perfs
    if name not in perfs:
        perfs[name] = {"samples": []}
    perfs[name]["samples"].append(time.ticks_us())

def perf_end(name):
    global perfs
    perfs[name]["samples"][-1] = time.ticks_us() - perfs[name]["samples"][-1]

def perf_dump():
  y = 0
  for name in perfs:
    total = 0
    count = len(perfs[name]["samples"])
    for sample in perfs[name]["samples"]:
        total += sample
    avg = round(total / count)

    total = round(total / 1000)
    output = f"{name}: {count}x {total}ms"
    w, h = screen.measure_text(output)
    screen.brush = brushes.color(20, 30, 40, 128)
    screen.rectangle(5, y + 5, int(w), int(h))
    screen.brush = brushes.color(220, 230, 240)
    screen.text(output, 5, y + 5)

    y += 12


class VecXY:
    x = 0
    y = 0

class Map:
    layout = []

class MapDef:
    texture = 0
    walkable = True
    rayEndPoint = False
    halfHeight = False
    doubleHeight = True

class Monster:
    x = 1
    y = 1
    fov = math.pi / 4
    angle = math.pi / 2
    speed = 2.5

TEXTURE_SIZE = 64

tilemap = SpriteSheet(f"assets/tilemap.png", 1, 10)

#maps are flipped vertically from how they are seen here, as y+ is down. Player 0 angle faces down on map as below, up on flipped map

gamemap = [ [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1,-1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1] ]

mapwidth = len(gamemap[0])
mapheight = len(gamemap)

mapDefs = []

# map definitions to be moved into separate map file.

# 0 - Empty air
mapdef0 = MapDef()
mapdef0.texture = 0
mapdef0.walkable = True
mapdef0.rayEndPoint = False
mapdef0.halfHeight = False
mapdef0.doubleHeight = False
mapDefs.append(mapdef0)

# 1 - Wall A
mapdef1 = MapDef()
mapdef1.texture = 1
mapdef1.walkable = False
mapdef1.rayEndPoint = True
mapdef1.halfHeight = False
mapdef1.doubleHeight = False
mapDefs.append(mapdef1)

# 2 - Wall B
mapdef2 = MapDef()
mapdef2.texture = 2
mapdef2.walkable = False
mapdef2.rayEndPoint = False
mapdef2.halfHeight = False
mapdef2.doubleHeight = False
mapDefs.append(mapdef2)

# 3 - Walkable decoration (i.e. Wolfenstein light fitting)
mapdef3 = MapDef()
mapdef3.texture = 3
mapdef3.walkable = True
mapdef3.rayEndPoint = False
mapdef3.halfHeight = False
mapdef3.doubleHeight = False
mapDefs.append(mapdef3)

# 4 - Non Walkable Decoration (i.e. fence)
mapdef4 = MapDef()
mapdef4.texture = 4
mapdef4.walkable = False
mapdef4.rayEndPoint = False
mapdef4.halfHeight = False
mapdef4.doubleHeight = False
mapDefs.append(mapdef4)

# 5 - Double Height Wall
mapdef5 = MapDef()
mapdef5.texture = 5
mapdef5.walkable = False
mapdef5.rayEndPoint = True
mapdef5.halfHeight = False
mapdef5.doubleHeight = True
mapDefs.append(mapdef5)

player = Monster()

#search the map for the player start pos
for i in range(len(gamemap)):
    for j in range(len(gamemap[i])):
        if gamemap[i][j] == -1:
            player.x = i + 0.5
            player.y = j + 0.5

rayCastMs = 0

textures = [
  tilemap.sprite(0, 0),
  tilemap.sprite(0, 1),
  tilemap.sprite(0, 2),
  tilemap.sprite(0, 3),
  tilemap.sprite(0, 4),
  tilemap.sprite(0, 5),
  tilemap.sprite(0, 6),
  tilemap.sprite(0, 7),
  tilemap.sprite(0, 8),
  tilemap.sprite(0, 9)
]

total_ray_casting_us = 0
def castRay(screen_x, angle):
    # change the ray angle into vectors
    rayDirX = math.cos(angle)
    rayDirY = math.sin(angle)

    intersections = dda(player.x, player.y, rayDirX, rayDirY, gamemap, 50)
    intersections = reversed(intersections)

    for intersection in intersections:
        tile_index = intersection[7]
        tile = mapDefs[tile_index]

        # wall height is inversely proportional to distance, simples
        wallHeight = 200 / intersection[6]
        topend = 60 - int(wallHeight / 2)

        # calculate texture uv coordinates scaled to the texture size
        u = intersection[5]
        u = math.floor(u * TEXTURE_SIZE)

        # determine which texture to use
        texture_index = tile.texture - 1
        # check if intersection edge is top or bottom of grid square, if so
        # shift texture index for darkened variants
        if intersection[4] == 0 or intersection[4] == 2:
          texture_index += 5
        texture = textures[texture_index]

        # draw the wall
        screen.vspan_tex(texture, screen_x, topend, wallHeight, u, 0, u, TEXTURE_SIZE - 1)
        if tile.doubleHeight:
            screen.vspan_tex(texture, screen_x, topend - wallHeight + 1, wallHeight, u, 0, u, TEXTURE_SIZE - 1)



def raycast():
    #rayStep = player.fov / 160

    #

    # fov_left = player.angle - (player.fov / 2)
    # fov_right = player.angle - (player.fov / 2)

    # rayDirX = math.cos(angle)
    # rayDirY = math.sin(angle)

    for x in range(160):
        angle = player.angle - (player.fov / 2) + (x * (player.fov / 160))
        angle %= math.pi * 2
        # if angle > math.pi * 2: angle -= math.pi * 2
        # if angle < 0: angle += math.pi * 2
        castRay(x, angle)

lastFrameMs = 0


def player_move():
    if io.BUTTON_C in io.held:
        player.angle += math.pi / 30
        if player.angle > math.pi * 2: player.angle = 0
    elif io.BUTTON_A in io.held:
        player.angle -= math.pi / 30
        if player.angle < 0: player.angle = math.pi * 2
    if io.BUTTON_UP in io.held:
        player.x += math.cos(player.angle) / player.speed
        player.y += math.sin(player.angle) / player.speed
    if io.BUTTON_DOWN in io.held:
        player.x -= math.cos(player.angle) / player.speed
        player.y -= math.sin(player.angle) / player.speed

def update():
    global player
    global gamemap
    global lastFrameMs

    player_move()

    screen.scale_blit(background, 0, 0, 160, 120)
    raycast()

    fps = 1000 / (io.ticks - lastFrameMs)
    screen.text(str(fps), 0, 0)
    lastFrameMs = io.ticks

if __name__ == "__main__":
    run(update)
