#include <stdint.h>

// TODO: I think normal `printf` is overriden *somewhere* so we must explicitly print to stdout
//#define debug_printf(fmt, ...)
#define debug_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)
#define warning_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)


// Framebuffer and "emulator" state
extern uint32_t framebuffer[];
extern int screen_width;
extern int screen_height;

void badgeware_preinit(void);
int badgeware_init(void);
void badgeware_update(int ticks);
void badgeware_deinit(void);
void badgeware_input(uint8_t mask, bool set);
void badgeware_hot_reload(void);