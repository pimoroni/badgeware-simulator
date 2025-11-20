#include <stdint.h>

// TODO: I think normal `printf` is overriden *somewhere* so we must explicitly print to stdout
//#define debug_printf(fmt, ...)
#define debug_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)
#define warning_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)


// Framebuffer and "emulator" state
extern uint32_t framebuffer[];
extern int screen_width;
extern int screen_height;

#define DEBUG_BUFFER_WIDTH 300
#define DEBUG_BUFFER_HEIGHT 360

extern uint32_t debug_buffer[DEBUG_BUFFER_WIDTH * DEBUG_BUFFER_HEIGHT];

void badgeware_preinit(void);
void badgeware_init_args(int argc, char **argv);
int badgeware_init(const char *root_path, const char *watch_path, const char *screenshot_path);
void badgeware_update(int ticks);
void badgeware_deinit(void);
void badgeware_input(uint8_t mask, bool set);
void badgeware_trigger_hot_reload(void);
bool badgeware_will_hot_reload(void);
int badgeware_screenshot(void *buffer, const char *fn);
bool badgeware_should_exit(void);
