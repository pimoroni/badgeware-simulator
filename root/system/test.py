from picovector import algorithm

mode(HIRES)

ark = pixel_font.load("/system/assets/fonts/ark.ppf")

screen.antialias = screen.X2
image = image.load("/system/assets/mona-sprites/mona-heart.png").window(0, 0, 24, 24)
sprites = SpriteSheet("/system/assets/mona-sprites/mona-heart.png", 14, 1)
import math


import os

from system.tests import custom_shape



def update():
  custom_shape.update()

# def custom_shape():
#   pen(255, 0, 255)
#   s = shape.custom([point(10, 10), point(20, 10), point(20, 20), point(10, 20)], [point(15, 15), point(25, 15), point(25, 25), point(15, 25)])
#   s.transform = mat3().translate(160, 120).scale(5).rotate(io.ticks / 50)
#   screen.shape(s)

# def line_clipping():

#   pen(255, 255, 255)

#   # line clipping to window
#   p1 = point(
#     int(math.sin(io.ticks / 500) * 20 + 0),
#     int(math.sin(io.ticks / 400) * 30 + 0)
#   )

#   p2 = point(
#     int(math.sin(io.ticks / 300) * 20 + 150),
#     int(math.sin(io.ticks / 200) * 30 + 120)
#   )

#   w = screen.window(30, 30, 80, 80)
#   w.line(p1, p2)

#   # line clipping to rect
#   p1 = point(
#     int(math.sin(io.ticks / 500) * 20 + 0) + 100,
#     int(math.sin(io.ticks / 400) * 30 + 0)
#   )

#   p2 = point(
#     int(math.sin(io.ticks / 300) * 20 + 150) + 100,
#     int(math.sin(io.ticks / 200) * 30 + 120)
#   )

#   algorithm.clip_line(p1, p2, rect(130, 30, 80, 80))
#   screen.line(p1, p2)


# def window_blit():
#   w = screen.window(20, 20, 80, 80)
#   screen.blit(w, 180, 100)

# def transformed_sprite():
#   scale = (math.sin(io.ticks / 1000) + 1.0) * 5 + 2
#   angle = math.cos(io.ticks / 500) * 150
#   magic_sprite(image, (160, 120), scale, angle)

# def patterns():

#   pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 100), (
#     0b00000000,
#     0b01111110,
#     0b01000010,
#     0b01011010,
#     0b01011010,
#     0b01000010,
#     0b01111110,
#     0b00000000))
#   pattern = brush.pattern(color.rgb(255, 0, 0, 255), color.rgb(0, 0, 255, 255), 11)
#   pen(pattern)
#   screen.rectangle(0, 0, screen.width, screen.height)

#   pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), (
#     0b00000000,
#     0b01111110,
#     0b01000010,
#     0b01011010,
#     0b01011010,
#     0b01000010,
#     0b01111110,
#     0b00000000))
#   pattern = brush.pattern(color.rgb(255, 0, 255, 255), color.rgb(0, 0, 0, 0), 11)

#   pen(pattern)

#   screen.shape(shape.circle(160 + math.sin(io.ticks / 500) * 30, 120 + math.sin(io.ticks / 1000) * 30, 80))