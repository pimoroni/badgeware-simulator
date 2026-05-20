class ST7789:
    def __init__(self):
        self._fullres = True

    def backlight(self, value):
        pass

    def update(self):
        pass

    def fullres(self, value):
        self._fullres = value

    def set_vsync(self, value):
        pass

    def speed(self, value):
        pass

    @property
    def WIDTH(self):
        return 320 if self._fullres else 160

    @property
    def HEIGHT(self):
        return 240 if self._fullres else 120