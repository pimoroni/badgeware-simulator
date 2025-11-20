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

#define MS_PER_FRAME 16.66f

extern bool simulator_realtime;

unsigned long long now_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
}

unsigned long long now_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (unsigned long long)(tv.tv_sec) * 1000000 + (unsigned long long)(tv.tv_usec); 
}

int main(int argc, char* argv[]) {
    badgeware_preinit();

    if(badgeware_init("root", "root/system", "screenshots") != 0) {
        exit(EXIT_FAILURE);
    }

    badgeware_init_args(argc, argv);

    unsigned long long time_start = now_ms();
    unsigned long frame = 0;
    while(true) {
	    unsigned long long time_ms = now_ms();
        uint32_t ticks = simulator_realtime ? time_ms - time_start : frame * MS_PER_FRAME;
	    //unsigned long long time_start_us = now_us();
        badgeware_update(ticks);
	    //unsigned long long time_end_us = now_us();
	    //long long time_taken = time_end_us - time_start_us;
	    //printf("Time taken: %llu\n", time_taken);
        if(simulator_realtime) {
            usleep(MS_PER_FRAME * 1000);
        }
        if(badgeware_should_exit()) {
            break;
        }
        frame++;
    }
    badgeware_deinit();
}
