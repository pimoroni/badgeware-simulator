from picovector import screen, PixelFont, Font, brushes, shapes, Matrix
from lib import wrap_and_measure

BLACK = brushes.color(0, 0, 0)
GREEN = brushes.color(128, 255, 0)
DARKGREEN = brushes.color(64, 128, 0)
GREEN_A = brushes.color(128, 255, 0, 200)


class ShapesDemo:
  def __init__(self, shape="line"):
    self.shapes = {
      "line": shapes.line(10, 10, 150, 110, 5),
      "circle": shapes.circle(80, 60, 30),
      "rectangle": shapes.rectangle(50, 30, 60, 60),
      "pie": shapes.pie(80, 60, 30, -225, 45),
      "rounded_rectangle": shapes.rounded_rectangle(50, 30, 60, 60, 10, 0, 10, 0)
    }
    self.current_shape = self.shapes[shape]

  def update(self):
    screen.brush = GREEN
    screen.draw(self.current_shape)


class TransformDemo:
  def __init__(self, transform="scale"):
    self.transforms = {
      "scale": Matrix().scale(1.5),
      "translate": Matrix().translate(10, 10),
      "rotate": Matrix().rotate(45)
    }

    self.show_transform = self.transforms[transform]
    self.shape = shapes.squircle(0, 0, 30, 5)

  def update(self):
    screen.brush = DARKGREEN
    self.shape.transform = Matrix().translate(80, 60)
    screen.draw(self.shape)
    screen.brush = GREEN_A
    self.shape.transform = Matrix().translate(80, 60).multiply(self.show_transform)
    screen.draw(self.shape)

class FontDemo:
  def __init__(self, show_pixel = False):
    self.fonts = {
      "Bacteria": PixelFont.load("test/performance/assets/bacteria.ppf"),
      "Ignore": PixelFont.load("test/performance/assets/ignore.ppf"),
      "Nope": PixelFont.load("test/performance/assets/nope.ppf"),
      "Sins": PixelFont.load("test/performance/assets/sins.ppf"),
      "Vest": PixelFont.load("test/performance/assets/vest.ppf")
    }

    self.vector_font = Font.load("test/performance/assets/MonaSans-Medium-Low.af")
    self.vector_font_size = 20

    self.show_pixel = show_pixel

  def update(self):
      screen.brush = GREEN

      if self.show_pixel:
        y = 10
        for name, font in self.fonts.items():
          screen.font = font
          h = screen.measure_text(name)[1]
          screen.brush = DARKGDREEN
          screen.draw(shapes.line(10, y + h - 1, 150, y + h - 1, 1))
          screen.brush = GREEN
          screen.text(name, 10, int(y))
          y += 30 if name == "Ignore" else 18

      else:
        screen.font = self.vector_font
        text = wrap_and_measure(screen, "The quick brown fox jumps over the lazy dog!", self.vector_font_size, 140)
        y = 10
        for (line, width) in text:
          screen.text(line, 10, y, self.vector_font_size)
          y += self.vector_font_size

#demo = TransformDemo(transform="translate")
demo = ShapesDemo("rounded_rectangle")

screen.antialias = 4

def update():
  screen.brush = BLACK
  screen.clear()
  demo.update()