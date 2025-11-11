#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "badgeware.h"
#include "modsimulator.h"

#ifndef NO_QSTR
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#endif

int main(int argc, char* argv[]) {
    badgeware_preinit();

    if(badgeware_init("root", "root/system", "screenshots") != 0) {
        exit(EXIT_FAILURE);
    }

    struct timeval tv;
    while(true) {
        gettimeofday(&tv, NULL);
        unsigned long long time_ms = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
        badgeware_update(time_ms);
        usleep(16 * 1000);
        if(badgeware_should_exit()) {
            break;
        }
    }
    badgeware_deinit();
}