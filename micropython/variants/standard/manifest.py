include("$(PORT_DIR)/variants/manifest.py")

include("$(MPY_DIR)/extmod/asyncio")

# Handy for dealing with APIs
require("datetime")

require("bundle-networking")
require("urllib.urequest")
require("umqtt.simple")

freeze("$(PORT_DIR)/../modules")