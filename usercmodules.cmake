# PicoVector and supporting libs
find_package(PICOVECTOR CONFIG REQUIRED)
target_link_libraries(usermod INTERFACE usermod_picovector)

# Input module
include(modinput/micropython)