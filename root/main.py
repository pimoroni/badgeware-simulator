# This file is copied from /system/main.py to /main.py on first run
import sys
import os
from badgeware import run, io, Image, screen
import machine
import gc
import powman

startup = __import__("/system/apps/badge")

def update():
    startup.update()