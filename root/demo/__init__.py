screen.font = PixelFont.load("/system/assets/fonts/nope.ppf")

menu_items = ["item 1", "item 2", "item 3", "item 4"]
selected_item = 0

def update():
  global selected_item

  # clear the framebuffer
  screen.brush = brushes.color(0, 0, 0)
  screen.clear()

  # adjust selected item index based on button presses
  if io.BUTTON_UP in io.pressed:
    selected_item -= 1

  if io.BUTTON_DOWN in io.pressed:
    selected_item += 1

  # wrap and clamp selected index to the range of items in the menu
  selected_item %= len(menu_items)

  # draw the menu on the screen
  screen.brush = brushes.color(255, 255, 255)
  for i in range(len(menu_items)):
    # if this is the selected item then highlight it
    if i == selected_item:
      screen.text(">", 0, i * 10)

    # write the menu item label
    screen.text(menu_items[i], 10, i * 10)


"""
# the character's position
pos_x, pos_y = 80, 60

# the character's motion vector
dir_x, dir_y = 0, 0

# character's max run speed
max_dir_x = 2

def update():
  global dir_x, dir_y, pos_x, pos_y

  # clear the framebuffer
  screen.brush = brushes.color(0, 0, 0)
  screen.clear()

  if io.BUTTON_A in io.held:
    # move left
    dir_x = -1
  elif io.BUTTON_C in io.held:
    # move right
    dir_x = 1

  if io.BUTTON_B in io.pressed:
    # jump when B is pressed
    dir_y = -3

  # apply gravity and dampen sideways movement
  dir_x *= 0.8
  dir_y += 0.1

  pos_x += dir_x
  pos_y += dir_y

  # clamp to floor
  if pos_y > 60:
    dir_y = 0
    pos_y = 60

  # draw the floor
  screen.brush = brushes.color(255, 255, 255)
  screen.draw(shapes.rectangle(0, 60, 160, 10))

  # draw the character
  screen.brush = brushes.color(255, 0, 255)
  screen.draw(shapes.circle(pos_x, pos_y, 3))

#"""