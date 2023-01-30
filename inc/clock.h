#include <stdint.h>
#include <stdbool.h>

typedef struct clock_s * clock_t;

clock_t ClockCreate(uint16_t ticks_per_second);

bool ClockGetTime(clock_t clock, uint8_t *time, uint8_t size);

void ClockSetupTime(clock_t clock, uint8_t const * const time, uint8_t size);

void ClockNewTick(clock_t clock);

void ClockSetupAlarm(clock_t clock, uint8_t const * const alarm, uint8_t size);

bool ClockGetAlarm(clock_t clock, uint8_t * alarm, uint8_t size);
