import math, os, gc
from lib import *

mona = SpriteSheet(f"../assets/mona-sprites/mona-heart.png", 14, 1).animation()
screen.font = PixelFont.load("../assets/fonts/nope.ppf")
screen.antialias = Image.X2

# create a dictionary of all the images in the images directory
files = []
for file in os.listdir("images"):
  file = file.rsplit("/", 1)[-1]
  name, ext = file.rsplit(".", 1)
  if ext == "png":
    files.append({
      "name": file,
      "title": name.replace("-", " ")
    })

# load the thumbnail images to match
thumbnails = []
for file in files:
  thumbnails.append(Image.load(f"thumbnails/{file["name"]}"))


# given a gallery image index it clamps it into the range of available images
def clamp_index(index):
  return index % len(files)


# load the main image based on the gallery index provided
def load_image(index):
  global image
  index = clamp_index(index)
  image = Image.load(f"images/{files[index]["name"]}")


# render the thumbnail strip
def draw_thumbnails():
  spacing = 36
  # render the thumbnail strip
  for i in range(-3, 4):
    offset = thumbnail_scroll - int(thumbnail_scroll)

    pos = (((i + -offset) * spacing) + 60, 92)

    # determine which gallery image we're drawing the thumbnail for
    thumbnail = clamp_index(int(thumbnail_scroll) + i)
    thumbnail_image = thumbnails[thumbnail]

    # draw the thumbnail shadow
    screen.brush = brushes.color(0, 0, 0, 50)
    screen.draw(shapes.rectangle(pos[0] + 2, pos[1] + 2, thumbnail_image.width, thumbnail_image.height))

    # draw the active thumbnail outline
    if i == 0:
      brightness = (math.sin(io.ticks / 200) * 127) + 127
      screen.brush = brushes.color(brightness, brightness, brightness, 150)
      screen.draw(shapes.rectangle(pos[0] - 1, pos[1] - 1, thumbnail_image.width + 2, thumbnail_image.height + 2))

    screen.blit(thumbnail_image, *pos)

  # draw a jumping mona
  mona_off = abs(((thumbnail_scroll - int(thumbnail_scroll)) * math.pi))
  mona_y = math.sin(mona_off) * 20
  screen.scale_blit(mona.frame(io.ticks / 100), 130, 68 - mona_y, -24, 24)


# start up with the first image in the gallery
index = 0
load_image(index)

thumbnail_scroll = index
def update():
  global index, thumbnail_scroll

  # if the user presses left or right then switch image
  if io.BUTTON_A in io.pressed:
    index -= 1
    load_image(index)

  if io.BUTTON_C in io.pressed:
    index += 1
    load_image(index)

  # draw the currently selected image
  screen.blit(image, 0, 0)

  # smooth scroll towards the newly selected image
  if thumbnail_scroll < index:
    thumbnail_scroll = min(thumbnail_scroll + 0.1, index)
  if thumbnail_scroll > index:
    thumbnail_scroll = max(thumbnail_scroll - 0.1, index)

  # draw the thumbnail ui
  draw_thumbnails()

  title = files[clamp_index(index)]["title"]
  width, _ = screen.measure_text(title)

  screen.brush = brushes.color(0, 0, 0, 100)
  screen.draw(shapes.rounded_rectangle(80 - (width / 2) - 8, -6, width + 16, 22, 6))
  screen.text(title, 80 - (width / 2) + 1, 1)
  screen.brush = brushes.color(255, 255, 255)
  screen.text(title, 80 - (width / 2), 0)

  return True
