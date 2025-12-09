import sys
import os

sys.path.insert(0, "/system/apps/quest")
os.chdir("/system/apps/quest")
import gc

import micropython
import math
import time
import random
from badgeware import State, PixelFont, Image, brush, screen, io, shapes, run
from picovector import dda
from badgeware import SpriteSheet

background = Image.load("assets/background.png")
screen.font = PixelFont.load("/system/assets/fonts/nope.ppf")

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

mapwidth = 20
mapheight = 15

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


total_ray_casting_us = 0
def castRay(rayNo, sliceWidth, rayAngle):
    global total_ray_casting_us
    global rayCastMs, player, gamemap, mapwidth, mapheight



    # change the ray angle into vectors
    rayDirX = math.cos(rayAngle)
    rayDirY = math.sin(rayAngle)

    start = time.ticks_us()
    rayHits = dda(player.x, player.y, rayDirX, rayDirY, 20)
    end = time.ticks_us()

    total_ray_casting_us += end - start


    rayCastMs += time.ticks_ms() - start


    i = 0
    draw_start = False

    for rayHit in reversed(rayHits):
        # extract the intersection x and y coordinates
        ix, iy = rayHit[0], rayHit[1]

        vertical = abs(ix - round(ix)) > abs(iy - round(iy))

        # determine which cell the intersection is with
        if vertical:
          gy = round(iy) - (1 if rayDirY < 0 else 0)
          gx = int(ix)
        else:
          gx = round(ix) - (1 if rayDirX < 0 else 0)
          gy = int(iy)

        # check within map bounds
        if gx < 0 or gx > 14 or gy < 0 or gy > 19:
            continue

        mapDefIndex = gamemap[gx][gy]
        # check if grid square has nothing renderable, if so skip
        if mapDefIndex <= 0:
            continue

        mapDef = mapDefs[mapDefIndex]

        distance = math.sqrt((ix - player.x) ** 2 + (iy - player.y) ** 2)

        if distance <= 0:
            continue

        # wall height is inversely proportional to distance, simples
        wallHeight = 200 / distance
        topend = 60 - int(wallHeight / 2)

        u = 0

        # determine the u coordinate of the texture by looking at the part of the hit location after the decimal
        # the orientation of the wall determines whether it's the x or y part of the hit location
        if vertical:
            u = ix - math.floor(ix)
        else:
            u = iy - math.floor(iy)

        # convert the 0-1 value of that u coordinate to
        u = math.floor(u * TEXTURE_SIZE)

        # if rayDirX > 0 or rayDirY < 0:#orientation == "w" or orientation == "s":
        #     u = TEXTURE_SIZE - u - 1


        v = mapDef.texture - 1

        if not vertical: #orientation == "n" or orientation == "s":
            v += 5

        xPos = rayNo * sliceWidth

        texture = tilemap.sprite(0, v)

        for i in range(sliceWidth):
            screen.vspan_tex(texture, xPos + i, topend, wallHeight, u, 0, u, TEXTURE_SIZE - 1)
            if mapDef.doubleHeight:
                screen.vspan_tex(texture, xPos + i, topend - wallHeight + 1, wallHeight, u, 0, u, TEXTURE_SIZE - 1)




def raycast():
    global rayCastMs
    rayCastMs = 0
    rays = 160
    screenWidth = 160
    sliceWidth = screenWidth / rays
    rayStep = player.fov / rays

    screen.scale_blit(background, 0, 0, 160, 120)

    for rayNo in range(rays):
        rayAngle = player.angle - (player.fov / 2) + (rayNo * rayStep)
        if rayAngle > math.pi * 2: rayAngle -= math.pi * 2
        if rayAngle < 0: rayAngle += math.pi * 2
        castRay(rayNo, sliceWidth, rayAngle)

lastFrameMs = 0

#def lookahead(entity):
#    lookAheadX = entity.x += math.cos(entity.angle) / entity.speed
#    lookAheadY = entity.y += math.sin(entity.angle) / entity.speed
#    return lookAheadX, lookAheadY

#def lookbehind():
#    lookBehindX = entity.x -= math.cos(entity.angle) / entity.speed
#    lookBehindY = entity.y -= math.sin(entity.angle) / entity.speed
#    return lookBehindX, lookBehindY

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
    global total_ray_casting_us
    global player
    global gamemap
    global lastFrameMs
    #rayHits = dda(1, 1, 1, 1, 5)
    player_move()
    screen.pen = color.rgb(20, 40, 0)
    gc.collect()

    total_ray_casting_us = 0
    raycast()


    fps = 1000 / (io.ticks - lastFrameMs)
    screen.text(str(fps), 0, 0)

    #screen.text(str(rayCastMs / 160), 0, 10)
    screen.text(str(total_ray_casting_us), 100, 20)

    lastFrameMs = io.ticks

if __name__ == "__main__":
    run(update)
