#include "clock.h"
#include <string.h>

clock_t ClockCreate(uint16_t ticks_per_second){
}

bool ClockGetTime(clock_t clock, uint8_t *time, uint8_t size){
    memset (time, 0, size);
    return false;
}