
# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(USERMOD_DIR)/modpicovector_bindings.c

SRC_USERMOD_CXX += $(USERMOD_DIR)/modpicovector.cpp $(USERMOD_DIR)/picovector.cpp $(USERMOD_DIR)/image.cpp

CFLAGS_USERMOD += -I$(USERMOD_DIR)
CXXFLAGS_USERMOD += -I$(USERMOD_DIR) -std=c++20 -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit

LDFLAGS_USERMOD += -lstdc++