#include <arm_timer.h>

#include <gpio.h>

#define INTERRUPT_HANDLER(type) void __attribute__((interrupt(type)))

INTERRUPT_HANDLER("ABORT") reset_vector()
{
}


INTERRUPT_HANDLER("UNDEF") undefined_instruction_vector()
{
    while (1)
    {
        /* nothing */
    }
}

INTERRUPT_HANDLER("SWI") software_interrupt_vector()
{
    while (1)
    {
        /* nothing */
    }
}

INTERRUPT_HANDLER("ABORT") prefetch_abort_vector()
{
}

INTERRUPT_HANDLER("ABORT") data_abort_vector()
{
}

INTERRUPT_HANDLER("IRQ") interrupt_vector()
{
    static int is_lit = 0;

    /* Clear the timer interrupt. */
    RPI_GetArmTimer()->IRQClear = 1;

    if (is_lit) {
        led_off();
        is_lit = 0;
    } else {
        led_on();
        is_lit = 1;
    }
}

INTERRUPT_HANDLER("FIQ") fast_interrupt_vector()
{
    /* This was required to satisfy a GCC constraint error */
    while (1)
    {
        /* nothing */
    }
}
