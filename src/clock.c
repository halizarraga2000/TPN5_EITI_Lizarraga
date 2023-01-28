#include "clock.h"
#include <string.h>

#define TIME_SIZE 6
#define START_VALUE 0

struct clock_s{
    bool valid;
    uint8_t time[TIME_SIZE];
};

static struct clock_s instances;

clock_t ClockCreate(uint16_t ticks_per_second){
    instances.valid = false;
    memset(instances.time, START_VALUE, TIME_SIZE);
    return &instances;
}

bool ClockGetTime(clock_t clock, uint8_t *time, uint8_t size){
    memcpy (time, clock->time, size);
    return clock->valid;
}

void ClockSetupTime(clock_t clock, uint8_t const * const time, uint8_t size){
    memcpy(clock->time, time, size);
    clock->valid = true;
}
