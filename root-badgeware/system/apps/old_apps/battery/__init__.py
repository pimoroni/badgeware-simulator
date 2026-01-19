import badgeware
import time
from math import floor

display = badgeware.display
vector = badgeware.vector
WIDTH = badgeware.WIDTH
BLACK = display.create_pen(0, 0, 0)
WHITE = display.create_pen(255, 255, 255)

MAX = 4.20
MIN = 3.60
conversion_factor = (3.3 / 65536)
last_value = 100

# Percentage = (Current Voltage - Minimum Voltage) / (Maximum Voltage - Minimum Voltage) * 100

class App:

    def init(self):
        pass

    def sample_adc_u16(self, adc, samples=1):

        val = []
        for _ in range(samples):
            val.append(adc.read_u16())
        return sum(val) / len(val)

    def update(self):
        # Use the battery voltage to estimate the remaining percentage

        # Get the average reading over 20 samples from our VBAT and VREF
        self.voltage = self.sample_adc_u16(badgeware.VBAT_SENSE, 10) * conversion_factor * 2
        self.vref = self.sample_adc_u16(badgeware.SENSE_1V1, 10) * conversion_factor
        self.voltage = self.voltage / self.vref * 1.1

        # Cap the value at 4.2v
        self.voltage = min(self.voltage, MAX)

        # Return the battery level as a perecentage
        self.percentage = floor((self.voltage - MIN) / (MAX - MIN) * 100)

    def render(self):
        display.set_pen(WHITE)
        display.clear()
        display.set_pen(BLACK)

        display.text(f"BAT%:{self.percentage}", 10, 30, WIDTH, 1)
        display.text(f"CHARGE: {badgeware.CHARGE_STAT.value()}", 10, 40, WIDTH, 1)
        display.text(f"VOLT: {self.voltage}", 10, 50, WIDTH, 1)

        display.update()
        time.sleep(1.0 / 60)

app = App()
init = app.init
update = app.update
render = app.render
