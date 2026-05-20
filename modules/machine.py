class BoardPins:
    pass


class Pin:
    board = BoardPins()

    def __init__(self, value):
        self._value = value

    def value(self):
        return self._value

class ADC:
    def __init__(self, pin):
        self._pin = pin
        self._value = 1

    def read_u16(self):
        if callable(self._value):
            return self._value()
        return self._value


class I2C():
    def __init__(self):
        return None


class RTC():
    def __init__(self):
        pass

    def datetime(self, *args):
        if len(args):
            return
        return 2026, 1, 19, 0, 12, 5, 0, 0
    

class PWM():
    def __init__(self, *args):
        pass

    def freq(self, freq):
        pass

    def duty_u16(self, duty):
        pass



Pin.board.CL0 = Pin(0)
Pin.board.CL1 = Pin(1)
Pin.board.CL2 = Pin(2)
Pin.board.CL3 = Pin(3)

Pin.board.I2C_SDA = Pin(4)
Pin.board.I2C_SCL = Pin(5)

Pin.board.BUTTON_DOWN = Pin(6)
Pin.board.BUTTON_A = Pin(7)
Pin.board.BUTTON_B = Pin(9)
Pin.board.BUTTON_C = Pin(10)
Pin.board.BUTTON_UP = Pin(11)

Pin.board.VBUS_DETECT = Pin(12)
Pin.board.CHARGE_STAT = Pin(-2)  # Ext GPIO 2)
Pin.board.RTC_ALARM = Pin(13)
Pin.board.BUTTON_RESET = Pin(14)
Pin.board.BUTTON_INT = Pin(15)
Pin.board.BUTTON_HOME = Pin(22)
Pin.board.WL_ON = Pin(23)
Pin.board.WL_D = Pin(24)
Pin.board.WL_CS = Pin(25)
Pin.board.LCD_BACKLIGHT = Pin(26)
Pin.board.LCD_CS = Pin(27)
Pin.board.LCD_RS = Pin(28)
Pin.board.WL_CLK = Pin(29)
Pin.board.LCD_WR = Pin(30)
Pin.board.LCD_RD = Pin(31)
Pin.board.LCD_DB0 = Pin(32)
Pin.board.LCD_DB1 = Pin(33)
Pin.board.LCD_DB2 = Pin(34)
Pin.board.LCD_DB3 = Pin(35)
Pin.board.LCD_DB4 = Pin(36)
Pin.board.LCD_DB5 = Pin(37)
Pin.board.LCD_DB6 = Pin(38)
Pin.board.LCD_DB7 = Pin(39)
Pin.board.VBAT_SENSE = Pin(40)
Pin.board.POWER_EN = Pin(41)
Pin.board.SENSE_1V1 = Pin(42)
Pin.board.LIGHT_SENSE = Pin(43)