


# GitHub Universe Badge 2025

- [Introduction](#introduction)
- [Getting started](#getting-started)
- [The basics](#the-basics)
  - [Debugging](#debugging)
  - [Timing](#timing)
- [The filesystem](#the-filesystem)
  - [Editing code on the badge](#editing-code-on-the-badge)
  - [Writing to files from application code](#writing-to-files-from-application-code)
- [Reading button state](#reading-button-state)
- [The screen](#the-screen)
- [Images](#images)
  - [Clipping with image windows](#clipping-with-image-windows)
- [Drawing shapes](#drawing-shapes)
  - [Transforming shapes](#transforming-shapes)
  - [Primitives](#primitives)
    - [Rectangle](#rectangle)
    - [Rounded rectangle](#rounded-rectangle)
    - [Circle](#circle)
    - [Squircle](#squircle)
    - [Arc](#arc)
    - [Pie](#pie)
    - [Regular polygon](#regular-polygon)
- [Text](#text)
  - [Pixel fonts](#pixel-fonts)
    - [Included fonts:](#included-fonts)
  - [Vector fonts](#vector-fonts)
- [Wireless networking and Bluetooth](#wireless-networking-and-bluetooth)

## Introduction

Your badge this year is based on our upcoming "Tufty" Badgeware product. It's the fourth, most ambitious, and best, digital badge that we've developed for GitHub Universe so far!

On the board we've packed in a bunch of great features:

- RP2350 Dual-core ARM Cortex-M33 @ 200MHz
- 512kB SRAM
- 16MB QSPI XiP flash
- 320x240 full colour IPS display (currently pixel doubled to 160x120)
- 2.4GHz WiFi and Bluetooth 5
- 1000mAh chargeable battery (8 hours runtime)
- Qw/ST and SWD ports for accessories and debugging
- Five front facing buttons
- Battery voltage monitoring and charge status
- USB-C port for charging and programming
- RESET / BOOTSEL buttons
- 4-zone LED backlight
- Durable polycarbonate case with lanyard fixings

We hope you really love tinkering with it during, and after, the event. Ping us on socials and show us what you're up to!

\- your friends at Pimoroni ❤️

> This documentation is an early draft and both it and the API are subject to change! We're putting together a new build with more features and some performance enhancements which we'll share soon!

## Getting started

The board is pre-loaded with a special build of MicroPython that includes drivers for all of the built-in hardware.

We've also included a small suite of example applications to demonstrate how different features of the badge work. Feel free to poke around in the code and experiment.

## The basics

Your application should implement an `update()` function which will automatically be called every frame to give it a chance to update state and render new output.

```python
# select a font to use
screen.font = PixelFont.load("nope.ppf")

# called every frame, do all your stuff here!
def update():
  # calculate and draw an animated sine wave
  y = (math.sin(io.ticks / 100) * 20) + 80
  screen.brush = brushes.color(0, 255, 0)
  for x in range(160):
    screen.draw(shapes.rectangle(x, y, 1, 1))

  # draw a message to the user
  screen.brush = brushes.color(255, 255, 255)
  screen.text("badge says hi :-)", 10, 10)
```

### Debugging

You can use the built in python `print()` function to write to `stdout` this can be accessed by connecting a serial monitor to the badge from your computer and is very handy for debugging and extra information!

> We are working on more comprehensive debugging tools including a desktop/web based badge simulator and the ability to draw to a separate debugging screen when running on the badge.

### Timing

Often what you do inside `update()` depends on the current time or how much time has passed since the last call to `update()`.

Our `io` module provides two values:

- `ticks`: The number of milliseconds since the badge started up.
- `ticks_delta`: The number of milliseconds since the last `update()`.

> These values are from the moment your `update()` function was called. They will not change for the duration of the `update()` call.

`ticks_delta` is very useful to help you pace animations when the framerate may vary depending on the amount of work being done during `update()`.

```python
import io

screen.font = PixelFont.load("ark.ppf")
screen.brush = brushes.color(255, 255, 255)

def update():
  screen.text(f"{io.ticks}ms since boot", 10, 10)

  # calculate the current framerate
  fps = round(1000 / io.ticks_delta)
  screen.text(f"FPS: {fps}", 10, 40)
```

> you can still use the `time` module to get the current timestamp instead of the value frozen prior to `update()` if needed. For example `time.ticks_ms()`.
>
## The filesystem

The badge includes a filesystem with a number of mounted volumes:

- `/system` (8MB) - this is where application code should live, it is mounted read only when the badge is running so you cannot store data here.
- `/storage` (8MB) - this is an area for applications to store data

### Editing code on the badge

The easiest way to edit the code on the device is to put it into mass storage mode:

- Connect your badge up to your computer via a USB-C cable
- Press the RESET button twice
- The USB Disk Mode screen will appear
- The badge should appear as a disk named "BADGER" on your computer

In this mode you can see the contents of the `/system/` mount. This is where all application code should live, it is writeable *only* via USB Disk Mode.

### Writing to files from application code

The badge has a writeable partition located at `/storage` which is intended for applications to store state information and cache any data they may need to hold on to across resets.

The `/storage` partition is 4MB.

You can use normal Python style file access from your code:

```python
with open("/storage/myfile.txt", "w") as out:
  out.write("this is some text i want to keep\n")
```

## Reading button state

The `io` module also exposes helpful information about the state of the buttons on your badge. Each button is represented by a constant value: `io.BUTTON_A`, `io.BUTTON_B`, `io.BUTTON_C`, `io.BUTTON_D`, `io.BUTTON_E`.

Each of the following lists contains the buttons that are relevant to the current `update()`:

- `io.held` buttons that are currently held down
- `io.pressed` buttons that were pressed this frame
- `io.released` buttons that were released this frame
- `io.change` buttons that changed state this frame

```python
import io

screen.font = PixelFont.load("ark.ppf")
screen.brush = brushes.color(255, 255, 255)
def update():
  if io.button_A in io.held:
    screen.text("button A is held", 10, 10)
  else:
    screen.text("button A is not held", 10, 10)
```

> `pressed` and `released` are handy as they are only set for the single frame after the event occurs making them ideal for menu navigation for example.

## The screen

`screen` is an `Image` (`160` x `120`) and pixel doubled onto the display after the call to `update()` has finished.

```python
from lib import screen

def update():
  screen.draw(shapes.rectangle(10, 10, 20, 20))
```

> in the future there will be a high res mode allowing access to the full 320x240 resolution of the display

## Images

Images can be used to load graphics from stored files or to create graphics using drawing methods (or both!).

```python
sprites = Image.load("sprites.png")

def update():
  screen.blit(sprites, 10, 10)
```

### Clipping with image windows

You can take a reference to a portion of an `Image` which can then be drawn into, automatically clipping to the window bounds.

```python
def update():
  window = screen.window(20, 20, 100, 50)
  window.brush = brushes.color(0, 255, 0)

  # draw a circle clipped to the window bounds
  window.draw(shapes.circle(40, 40, 50))
```

## Drawing shapes

Unlike many microcontroller graphics libraries our PicoGraphics library supports drawing vector shapes (including with antialiasing!) which allows for all sorts of fun graphics to be created in realtime.

> All vector coordinates are floating point.

You can create a shape and then hold a reference to it for use later, or create them in realtime.

```python
screen.brush = brushes.color(0, 255, 0, 150)
squircle = shapes.squircle(80, 60, 20) # define a shape and hold onto it

def update():
  # draw our previously defined squircle
  screen.draw(squircle)

  # creates a new rectangle shape every frame
  screen.draw(shapes.rectangle(10, 10, 50, 50))
```

### Transforming shapes

Shapes can also be given a transformation matrix to adjust their scale, rotation, and skew - this is very useful for creating smooth animations.

```python
screen.brush = brushes.color(0, 255, 0, 150)
rectangle = shapes.rectangle(-20, -20, 40, 40) # note origin of rectangle is 0, 0

def update():
  # create a transform that slowly rotates the rectangle
  angle += io.ticks_delta / 100
  rectangle.transform = Matrix().rotate(angle)
  screen.draw(rectangle) # automatically applies the transform
```

Matrices support `rotate(angle)`, `rotate_radians(angle)`, `scale(x, y)`, `translate(x, y)`, and `multiple(matrix)` operations. You can chain operations to perform multiple transformations at once:

`shape.transform = Matrix().rotate(20).translate(20, 40).scale(0.5, 0.5)`

### Primitives
The currently supported primitives are:

#### Rectangle
- `shapes.rectangle(x, y, w, h)`

Define a rectangle starting at `x`, `y` with width of `w` and height of `h`.

#### Rounded rectangle
- `shapes.rounded_rectangle(x, y, w, h, r)`
- `shapes.rounded_rectangle(x, y, w, h, r1, r2, r3, r4)`

Works identically to `rectangle` but you can also specify either a single value for the corner radius `r` or four different corner radii `r1` through `r4` (starting at the top left corner and going clockwise).

> If the corner radius is greater than the width or height of the rectangle then the resulting shape can be malformed.

#### Circle
- `shapes.circle(x, y, r)`

Define a circle of radius `r` centred at `x`, `y`.

#### Squircle
- `shapes.squircle(x, y, r)`
- `shapes.squircle(x, y, r, n)`

Define a squircle (square-circle) of radius `r` centred at `x`, `y`.

Optionally you can supply the `n` parameter which defines how rounded the resulting shape is, `4` is the default.

#### Arc
- `shapes.arc(x, y, r, f, t)`

Define an arc of radius `r` centred at `x`, `y`. `f` and `t` are the "from" and "to" angles that the arc will occupy. They are specified in degrees, `0` straight down and increasing clockwise.

#### Pie
- `shapes.arc(x, y, r, f, t)`

Works identically to `arc` but creates a pie (pacman) shape instead.

#### Regular polygon
- `shapes.regular_polygon(x, y, r, s)`

Define a regular polygon of radius `r` centred at `x`, `y` with `s` sides.

## Text

### Pixel fonts

PicoGraphics includes thirty great licensed pixel fonts created by [somepx](https://somepx.itch.io). You can use these in your applications to add some variety and character!

```python
screen.font = PixelFont.load("nope.ppf")
screen.brush = brushes.color(0, 255, 0)

def update():
  screen.text("hello badgeware!", 10, 10)
```

#### Included fonts:

- `absolute`: bold, boxy, 10px tall
- `ark`: tiny, smallcaps, 6px tall
- `awesome`: cheerful, wholesome, monospace, 9px tall
- `bacteria`: rational, wide, monospace, 12px tall
- `compass`: classic, fantasy, 9px tall
- `corset`: elegant, cozy, 8px tall
- `curse`: comic, horror, smallcaps, 12px tall
- `desert`: tiny, drowsy, sunny, 6px tall
- `fear`: smallcaps, horror, 11px tall
- `futile`: big, bold, unique, 14px tall
- `holotype`: distinctive, premium, 9px tall
- `hungry`: playful, unique, monospace, 7px tall
- `ignore`: colossal, super-readable, intrepid, 17px tall
- `kobold`: classic, tiny, fantasy, 7px tall
- `lookout`: adventurous, piratesque, fantasy, 7px tall
- `loser`: slanted, smallcaps, monospace, 7px tall
- `manticore`: strong, metal, horror, 14px tall
- `match`: classic, joyful, 7px tall
- `memo`: wacky, distinctive, 9px tall
- `more`: chunky, huge, comic, 15px tall
- `nope`: clear, readable, 8px tall
- `outflank`: fantasy, arcane, 9px tall
- `saga`: medieval, fantasy, legendary, 8px tall
- `salty`: thick, all-purpose, 9px tall
- `sins`: tiny, classic, stylish, 7px tall
- `smart`: classic, chunky, smallcaps, 9px tall
- `teatime`: classic, readable, monospace, 7px tall
- `torch`: fiery, pocket-sized, fantasy, 6px tall
- `troll`: fantasy, ornate, 12px tall
- `unfair`: wide, retro, eccentric, 8px tall
- `vest`: elegant, classic, serif, 9px tall
- `winds`: tiny, extra-spaced, easy to read, 7px tall
- `yesterday`: bold, readable, distinctive, 10px tall
- `yolk`: classic, fantasy, 9px tall
- `ziplock`: round, cheerful, comic, 13px tall

> todo: include font sampler image

### Vector fonts

> this feature is experimental and does not perform well enough for most usecases at the moment. It will come in a later build.

## Wireless networking and Bluetooth

You can use the existing MicroPython functionality for wireless networking and bluetooth functionality.

- Wireless networking: https://docs.micropython.org/en/latest/rp2/quickref.html#wlan
- Bluetooth: https://docs.micropython.org/en/latest/library/bluetooth.html#module-bluetooth