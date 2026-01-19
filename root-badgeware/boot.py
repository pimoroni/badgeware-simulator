import picovector
import simulator
import builtins

# Import PicoSystem module constants to builtins,
# so they are available globally.
for k, v in picovector.__dict__.items():
    if not k.startswith("__"):
        setattr(builtins, k, v)

#for k in ("default_target", ):
#    setattr(builtins, k, getattr(picovector, k))

setattr(builtins, "framebuffer", memoryview(simulator.framebuffer))

import badgeware