import math, json

coastlines = []

def load_coastlines():
  with open("/system/assets/countries.geo.json", "r") as f:
    data = json.loads(f.read())
    for feature in data["features"]:
      if feature["geometry"]["type"] == "Polygon":
        path = [vec2(p[0], -p[1]) for p in feature["geometry"]["coordinates"][0]]
        coastlines.append(shape.custom(path))
      if feature["geometry"]["type"] == "MultiPolygon":
        for polygon in feature["geometry"]["coordinates"]:
          path = [vec2(p[0], -p[1]) for p in polygon[0]]
          coastlines.append(shape.custom(path))

load_coastlines()

import network
import time
import urequests

ssid = "melanzane"
password = "test2021"

wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect(ssid, password)

iss = None
def update_iss_position():
  global iss
  response = urequests.get("http://api.open-notify.org/iss-now.json")

  if response.status_code == 200:
    data = response.json()["iss_position"]
    iss = {"latitude": float(data["latitude"]), "longitude": float(data["longitude"])}
  else:
    print("HTTP error:", response.status_code)

  response.close()

last_update = None

def update():
  global last_update
  if not last_update or last_update < time.time() - 10:
    update_iss_position()
    last_update = time.time()

  screen.antialias = image.OFF
  screen.clear(color.rgb(20, 40, 60))

  i = 0
  pen(color.rgb(20, 80, 40))
  for coastline in coastlines:
    i = i + 1
    hue = 100
    x = math.sin(io.ticks / 1000) * 120
    s = math.sin(io.ticks / 1000) * 1 + 2
    pen(color.hsv(i, 255, 255))

    coastline.transform = mat3().translate(160, 120).scale(1.45, 1.45)
    screen.shape(coastline)

  if iss:
    pen(color.rgb(170, 180, 190))
    circle = shape.circle(iss["latitude"], iss["longitude"], 4)
    circle.transform = mat3().translate(160, 120).scale(1.45, 1.45)
    screen.shape(circle)
