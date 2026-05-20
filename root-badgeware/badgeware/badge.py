import _input
import os
import builtins
import machine
import powman
import binascii
import simulator

try:
    MODEL = os.uname().machine[9:-17].lower()
except AttributeError:
    MODEL = "tufty"

try:
    UID = binascii.hexlify(machine.unique_id()).decode("ASCII")
except AttributeError:
    UID = "000000000000"

builtins.LORES = 0b000
builtins.HIRES = 0b001
builtins.VSYNC = 0b010
builtins.DIRTY = 0b100

builtins.FAST_UPDATE = 3 << 4
builtins.FULL_UPDATE = 0 << 4
builtins.MEDIUM_UPDATE = 2 << 4
builtins.DITHER = 1 << 8

builtins.BUTTON_A = machine.Pin.board.BUTTON_A
builtins.BUTTON_B = machine.Pin.board.BUTTON_B
builtins.BUTTON_C = machine.Pin.board.BUTTON_C
builtins.BUTTON_UP = machine.Pin.board.BUTTON_UP
builtins.BUTTON_DOWN = machine.Pin.board.BUTTON_DOWN
builtins.BUTTON_HOME = machine.Pin.board.BUTTON_HOME


VBAT_SENSE = machine.ADC(machine.Pin.board.VBAT_SENSE)
VBUS_DETECT = machine.Pin.board.VBUS_DETECT
CHARGE_STAT = machine.Pin.board.CHARGE_STAT
SENSE_1V1 = machine.ADC(machine.Pin.board.SENSE_1V1)

BAT_MAX = 4.10
BAT_MIN = 3.00

conversion_factor = 3.3 / 65536

if MODEL == "tufty":
    LIGHT_SENSOR = machine.ADC(machine.Pin("LIGHT_SENSE"))
else:
    LIGHT_SENSOR = None


def sample_adc_u16(adc, samples=1):
    val = []
    for _ in range(samples):
        val.append(adc.read_u16())
    return sum(val) / len(val)


class Badge():
    def  __init__(self):
        if MODEL == "badger":
            self.default_clear = color.white
            self.default_pen = color.black
        else:
            self.default_clear = color.black
            self.default_pen = color.white

        # current display mode
        self._current_mode = None

        # either badger, tufty, or blinky
        self.model = MODEL

        # the system
        self.uid = UID

        # track first display update, for badger
        self.first_update = True

        self._case_light_values = [
            0, 0, 0, 0
        ]
        self._case_lights = [
            machine.PWM(machine.Pin.board.CL0),
            machine.PWM(machine.Pin.board.CL1),
            machine.PWM(machine.Pin.board.CL2),
            machine.PWM(machine.Pin.board.CL3)
        ]
        for led in self._case_lights:
            led.freq(500)
            led.duty_u16(0)

    @property
    def ticks(self):
        return _input.ticks

    @property
    def ticks_delta(self):
        return _input.ticks_delta

    def poll(self):
        _input.poll()

    @property
    def resolution(self):
        return screen.width, screen.height

    def clear(self):
        if self.default_clear is not None:
            screen.pen = self.default_clear
            screen.clear()
        screen.pen = self.default_pen
        return True

    def update(self):
        display.update()
        badge.clear()
        badge.poll()
        return True

    def mode(self, mode=None):
        if mode is None:
            return self._current_mode

        if mode == self._current_mode:
            return None

        self._current_mode = mode

        if MODEL == "tufty":
            display.fullres(bool(mode & HIRES))
            display.set_vsync(bool(mode & VSYNC))
            simulator.resolution(display.WIDTH, display.HEIGHT)

        elif MODEL == "badger":
            display.speed((self._current_mode >> 4) & 0xf)

        if MODEL == "tufty" or getattr(builtins, "screen", None) is None:
            font = getattr(getattr(builtins, "screen", None), "font", None)
            brush = getattr(getattr(builtins, "screen", None), "pen", None)
            builtins.screen = image(display.WIDTH, display.HEIGHT, framebuffer)
            screen.font = font if font is not None else rom_font.sins
            screen.pen = brush if brush is not None else self.default_pen

        return None

    def battery_voltage(self):
        # Get the average reading over 20 samples from our VBAT and VREF
        voltage = sample_adc_u16(VBAT_SENSE, 10) * conversion_factor * 2
        vref = sample_adc_u16(SENSE_1V1, 10) * conversion_factor
        return  voltage / vref * 1.1

    def usb_connected(self):
        return bool(VBUS_DETECT.value())

    def battery_level(self):
        # Use the battery voltage to estimate the remaining percentage
        return min(100, max(0, round(123 - (123 / pow((1 + pow((self.battery_voltage() / 3.2), 80)), 0.165)))))

    def is_charging(self):
        # We only want to return the charge status if the USB cable is connected.
        if VBUS_DETECT.value():
            return not CHARGE_STAT.value()

        return False

    def disk_free(self, mountpoint="/system"):
        # f_bfree and f_bavail should be the same?
        # f_files, f_ffree, f_favail and f_flag are unsupported.
        f_bsize, f_frsize, f_blocks, f_bfree = os.statvfs(mountpoint)[:4]

        f_total_size = f_frsize * f_blocks
        f_total_free = f_bsize * f_bfree

        return f_total_size, f_total_size - f_total_free, f_total_free

    def light_level(self):
        # TODO: Returning the raw u16 is a little meh here, can we do an approx lux conversion?
        if LIGHT_SENSOR is None:
            raise RuntimeError("Light level not supported!")
        return LIGHT_SENSOR.read_u16()
    
    def _translate_input(self, input_state):
        return [{
            0b100000: BUTTON_HOME,
            0b010000: BUTTON_A,
            0b001000: BUTTON_B,
            0b000100: BUTTON_C,
            0b000010: BUTTON_UP,
            0b000001: BUTTON_DOWN,
        }[i] for i in input_state]

    def pressed(self, button=None):
        if button is None:
            return self._translate_input(_input.pressed)
        return button in self._translate_input(_input.pressed)

    def held(self, button=None):
        if button is None:
            return self._translate_input(_input.held)
        return button in self._translate_input(_input.held)

    def released(self, button=None):
        if button is None:
            return self._translate_input(_input.released)
        return button in self._translate_input(_input.released)

    def changed(self, button=None):
        if button is None:
            return self._translate_input(_input.changed)
        return button in self._translate_input(_input.changed)

    def caselights(self, *args):
        if args:
            self._case_light_values[:] = (args[0], ) * 4 if len(args) == 1 else args

            for idx, cl in enumerate(self._case_lights):
                cl.duty_u16(int(self._case_light_values[idx] ** 2.2 * 65535))

        return list(self._case_light_values)

    def sleep(self, duration=None):
        powman.goto_dormant_for(duration) if duration else powman.sleep()

    def wake_reason(self):
        return powman.get_wake_reason()

    def woken_by_button(self):
        return powman.get_wake_reason() in (
            powman.WAKE_BUTTON_A,
            powman.WAKE_BUTTON_B,
            powman.WAKE_BUTTON_C,
            powman.WAKE_BUTTON_UP,
            powman.WAKE_BUTTON_DOWN,
        )

    def pressed_to_wake(self, button):
        return button in powman.get_wake_buttons()

    def woken_by_reset(self):
        return powman.get_wake_reason() == 255


builtins.badge = Badge()
