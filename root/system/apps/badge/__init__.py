from lib import *
import ui
from user import User
import secrets

# user profile information api
profile_url = f"https://api.github.com/users/{secrets.GITHUB_USERNAME}"

# 'wsrv.nl' is a CDN that resizes and reformats the image for us
avatar_url = f"https://wsrv.nl/?url=https://github.com/{secrets.GITHUB_USERNAME}.png&w=75&output=png"

# user contribution graph information api
contributions_url = f"https://github.com/{secrets.GITHUB_USERNAME}.contribs"

# location to store cached data files
profile_path = "/profile.json"
avatar_path = "/avatar.png"
contributions_path = "/contributions.json"

def profile_callback(response):
  if not response.ok:
    ui.http_error(response)
    return

  User.load_profile(profile_path)

def avatar_callback(response):
  if not response.ok:
    ui.http_error(response)
    return

  User.load_avatar(avatar_path)

def contributions_callback(response):
  if not response.ok:
    ui.http_error(response)
    return

  User.load_contributions(contributions_path)

def wifi_connected():
  headers = {"User-Agent": "GitHub Universe Badge 2025"}

  # fetch users profile
  f = open(profile_path, "w")
  fetch.get(profile_url, headers=headers, file=f, callback=profile_callback)

  # fetch users avatar image
  f = open(avatar_path, "wb")
  fetch.get(avatar_url, headers=headers, file=f, callback=avatar_callback)

  # fetch the users contribution history for the past year
  f = open(contributions_path, "w")
  fetch.get(contributions_url, headers=headers, file=f, callback=contributions_callback)

def wifi_error():
  # TODO: are we actually triggering any error events? how to disambiguate
  # different errors like wrong username / password or connection timeout?
  print("wifi failed to connect")

def init():
  wifi.connect(secrets.WIFI_PASSWORD, secrets.WIFI_PASSWORD, on_success=wifi_connected, on_error=wifi_error)

  # if we already have cached data we can load that first
  # User.load_profile("/profile.json")
  # User.load_avatar("/avatar.png")
  # User.load_contributions("/contributions.json")

def update():
  system_tick() # TODO: this should happen in background to allow system stuff to do any work that's needed like async fetches or easing functions

  # draws the animated contribution graph background
  ui.background()
  ui.name_and_handle()
  ui.statistics()
  ui.avatar()

  # # show the wifi connection error screen
  # ui.connection_error()

  # show the missing details error screen
  #ui.no_secrets_error()

# TODO: rename to just `exit()`
def on_exit():
  pass # we don't need to preserve any state here


#         # draw handle
#         screen.font = large_font
#         handle = self.handle

#         w, _ = screen.measure_text(handle)
#         screen.brush = white
#         screen.text(handle, 80 - (w / 2), 2)

#         # draw name
#         screen.font = small_font
#         screen.brush = phosphor
#         name = placeholder_if_none(self.name)
#         w, _ = screen.measure_text(name)
#         screen.text(name, 80 - (w / 2), 16)

#         # draw statistics
#         self.draw_stat("followers", self.followers, 88, 33)
#         self.draw_stat("contribs", self.contribs, 88, 62)
#         self.draw_stat("repos", self.repos, 88, 91)

#         # draw avatar imagee
#         if not self.avatar:
#             # create a spinning loading animation while we wait for the avatar to load
#             screen.brush = phosphor
#             squircle = shapes.squircle(0, 0, 10, 5)
#             screen.brush = brushes.color(211, 250, 55, 50)
#             for i in range(4):
#                 mul = sin(io.ticks / 1000) * 14000
#                 squircle.transform = Matrix().translate(42, 75).rotate(
#                     (io.ticks + i * mul) / 40).scale(1 + i / 1.3)
#                 screen.draw(squircle)
#         else:
#             screen.blit(self.avatar, 5, 37)



# def fake_number():
#     return random.randint(10000, 99999)


# def placeholder_if_none(text):
#     if text:
#         return text
#     old_seed = random.seed()
#     random.seed(int(io.ticks / 100))
#     chars = "!\"£$%^&*()_+-={}[]:@~;'#<>?,./\\|"
#     text = ""
#     for _ in range(20):
#         text += random.choice(chars)
#     random.seed(old_seed)
#     return text


# class User:
#     levels = [
#         brushes.color(21 / 2,  27 / 2,  35 / 2),
#         brushes.color(3 / 2,  58 / 2,  22 / 2),
#         brushes.color(25 / 2, 108 / 2,  46 / 2),
#         brushes.color(46 / 2, 160 / 2,  67 / 2),
#         brushes.color(86 / 2, 211 / 2, 100 / 2),
#     ]

#     def __init__(self):
#         self.handle = None
#         self.update()

#     def update(self, force_update=False):
#         self.name = None
#         self.followers = None
#         self.contribs = None
#         self.contribution_data = None
#         self.repos = None
#         self.avatar = None
#         self._task = None
#         self._force_update = force_update

#     def draw_stat(self, title, value, x, y):
#         screen.brush = white if value else faded
#         screen.font = large_font
#         screen.text(str(value) if value is not None else str(fake_number()), x, y)
#         screen.font = small_font
#         screen.brush = phosphor
#         screen.text(title, x - 1, y + 13)

#     def draw(self, connected):
#         # draw contribution graph background
#         size = 15
#         graph_width = 53 * (size + 2)
#         xo = int(-sin(io.ticks / 5000) *
#                  ((graph_width - 160) / 2)) + ((graph_width - 160) / 2)

#         screen.font = small_font
#         rect = shapes.rounded_rectangle(0, 0, size, size, 2)
#         for y in range(7):
#             for x in range(53):
#                 if self.contribution_data:
#                     level = self.contribution_data[y][x]
#                     screen.brush = User.levels[level]
#                 else:
#                     screen.brush = User.levels[1]
#                 pos = (x * (size + 2) - xo, y * (size + 2) + 1)
#                 if pos[0] + size < 0 or pos[0] > 160:
#                     # skip tiles that aren't in view
#                     continue
#                 rect.transform = Matrix().translate(*pos)
#                 screen.draw(rect)

#         # draw handle
#         screen.font = large_font
#         handle = self.handle

#         # use the handle area to show loading progress if not everything is ready
#         if (not self.handle or not self.avatar or not self.contribs) and connected:
#             if not self.name:
#                 handle = "fetching user data..."
#                 if not self._task:
#                     self._task = get_user_data(self, self._force_update)
#             elif not self.contribs:
#                 handle = "fetching contribs..."
#                 if not self._task:
#                     self._task = get_contrib_data(self, self._force_update)
#             else:
#                 handle = "fetching avatar..."
#                 if not self._task:
#                     self._task = get_avatar(self, self._force_update)

#             try:
#                 next(self._task)
#             except StopIteration:
#                 self._task = None

#         if not connected:
#             handle = "connecting..."

#         w, _ = screen.measure_text(handle)
#         screen.brush = white
#         screen.text(handle, 80 - (w / 2), 2)

#         # draw name
#         screen.font = small_font
#         screen.brush = phosphor
#         name = placeholder_if_none(self.name)
#         w, _ = screen.measure_text(name)
#         screen.text(name, 80 - (w / 2), 16)

#         # draw statistics
#         self.draw_stat("followers", self.followers, 88, 33)
#         self.draw_stat("contribs", self.contribs, 88, 62)
#         self.draw_stat("repos", self.repos, 88, 91)

#         # draw avatar imagee
#         if not self.avatar:
#             # create a spinning loading animation while we wait for the avatar to load
#             screen.brush = phosphor
#             squircle = shapes.squircle(0, 0, 10, 5)
#             screen.brush = brushes.color(211, 250, 55, 50)
#             for i in range(4):
#                 mul = sin(io.ticks / 1000) * 14000
#                 squircle.transform = Matrix().translate(42, 75).rotate(
#                     (io.ticks + i * mul) / 40).scale(1 + i / 1.3)
#                 screen.draw(squircle)
#         else:
#             screen.blit(self.avatar, 5, 37)


# user = User()
# connected = file_exists("/contrib_data.json") and file_exists("/user_data.json") and file_exists("/avatar.png")
# force_update = False




# # tell the user where to fill in their details
# def no_secrets_error():
#   screen.font = large_font
#   screen.brush = white
#   center_text("Missing Details!", 5)

#   screen.text("1:", 10, 23)
#   screen.text("2:", 10, 55)
#   screen.text("3:", 10, 87)

#   screen.brush = phosphor
#   screen.font = small_font
#   wrap_text("""Put your badge into\ndisk mode (tap\nRESET twice)""", 30, 24)

#   wrap_text("""Edit 'secrets.py' to\nset WiFi details and\nGitHub username.""", 30, 56)

#   wrap_text("""Reload to see your\nsweet sweet stats!""", 30, 88)


# # tell the user that the connection failed :-(
# def connection_error():
#   screen.font = large_font
#   screen.brush = white
#   center_text("Connection Failed!", 5)

#   screen.text("1:", 10, 63)
#   screen.text("2:", 10, 95)

#   screen.brush = phosphor
#   screen.font = small_font
#   wrap_text("""Could not connect\nto the WiFi network.\n\n:-(""", 16, 20)

#   wrap_text("""Edit 'secrets.py' to\nset WiFi details and\nGitHub username.""", 30, 65)

#   wrap_text("""Reload to see your\nsweet sweet stats!""", 30, 96)


# def update():
#     global connected, force_update

#     screen.brush = brushes.color(0, 0, 0)
#     screen.draw(shapes.rectangle(0, 0, 160, 120))

#     force_update = False

#     if io.BUTTON_A in io.held and io.BUTTON_C in io.held:
#         connected = False
#         user.update(True)

#     if get_connection_details(user):
#         if wlan_start():
#             user.draw(connected)
#         else:  # Connection Failed
#             connection_error()
#     else:      # Get Details Failed
#         no_secrets_error()


# if __name__ == "__main__":
#     run(update)

