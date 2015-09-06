#include <stdint.h>

#define RPI_SYSTIMER_BASE 0x20003000

typedef struct {
    volatile uint32_t control_status;
    volatile uint32_t counter_lo;
    volatile uint32_t counter_hi;
    volatile uint32_t compare0;
    volatile uint32_t compare1;
    volatile uint32_t compare2;
    volatile uint32_t compare3;
} sys_timer_t;

static sys_timer_t* timer = (sys_timer_t*)RPI_SYSTIMER_BASE;

void wait_us(uint32_t us)
{
    volatile uint32_t now = timer->counter_lo;
    while (timer->counter_lo - now < us)
    {
        /* spin */
    }
}

