import glob
from PIL import Image

screenshots = sorted(glob.glob("screenshots/screenshot-*.png"))

times = [int(screenshot.split("/")[-1][11:-4]) for screenshot in screenshots]

deltas = [times[i + 1] - times[i] for i in range(len(times) - 1)]
delta_avg = int(sum(deltas) / len(deltas))
deltas.insert(0, delta_avg)  # Duration for the first frame is unknowable so use the average
head = Image.open(screenshots[0]).convert("P")

images = []
for screenshot in screenshots[1:]:
    images.append(Image.open(screenshot).convert("P"))

head.save("animation.gif", save_all=True, optimize=True, append_images=images, duration=deltas, loops=0)

print(f"Converted {len(screenshots)} screenshots to a video lasting {sum(deltas) / 1000:.02f}sec. Average frame: {delta_avg}ms.")
