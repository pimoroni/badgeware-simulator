import json
from lib import *

# the User class gives us a nice place to collate the various API responses
# instead # of having a bunch of global variables

class User:
  name = None # full name of user
  handle = None # github username
  avatar = None # users avatar (type image)
  contributions = None # number of contributions
  repositories = None # number of repositories
  followers = None # number of followers
  levels = None # 2d array of contribution levels over past year [week][day]
  include_private = None # has private contributions turned on?
  last_update = None # last update time for user data

  # load the contribution data, convert the daily contributions into a
  # lightweight array for use later
  def load_contributions(path):
    try:
      with open(path, "r") as file:
        data = json.load(file)

        # pull out any interesting details
        User.last_update = data["generated_at"]
        User.include_private = data["private_contributions_included"]
        User.contributions = data["total_contributions"]

        # convert the contribution data in a simple array
        User.levels = [[0 for _ in range(7)] for _ in range(len(data["weeks"]))]
        for week in data["weeks"]:
          for day in week["contribution_days"]:
            User.levels[week["index"]][day["weekday"]] = day["level"]
    except:
      return False

    return True

  # load the users avatar image
  def load_avatar(path):
    try:
      User.avatar = image.load(path)
    except:
      return False

    return True

  # load the users profile data
  def load_profile(path):
    try:
      with open(path, "r") as file:
        data = json.load(file)
        # pull out any interesting details
        User.name = data["name"]
        User.handle = data["login"]
        User.followers = data["followers"]
        User.repositories = data["public_repos"]
    except:
      return False

    return True