#!/usr/bin/env python

import glob
import sys
from PIL import Image

OUTPUT_WIDTH = 640
OUTPUT_HEIGHT = 480

screenshots = sorted(glob.glob("screenshots/screenshot-*.png"))

times = [int(screenshot.split("/")[-1][11:-4]) for screenshot in screenshots]

deltas = [times[i + 1] - times[i] for i in range(len(times) - 1)]
delta_avg = int(sum(deltas) / len(deltas))
deltas.insert(0, delta_avg)  # Duration for the first frame is unknowable so use the average
head = Image.open(screenshots[0]).convert("RGB").resize((OUTPUT_WIDTH, OUTPUT_HEIGHT), resample=Image.Resampling.NEAREST)

images = []
for screenshot in screenshots[1:]:
    images.append(Image.open(screenshot).convert("RGB").resize((OUTPUT_WIDTH, OUTPUT_HEIGHT), resample=Image.Resampling.NEAREST))


filename = sys.argv[1] if len(sys.argv) > 1 else "animation.png"

head.save(f"{filename}", save_all=True, optimize=True, append_images=images, duration=deltas, loops=0)

print(f"Converted {len(screenshots)} screenshots to a video lasting {sum(deltas) / 1000:.02f}sec. Average frame: {delta_avg}ms.")
