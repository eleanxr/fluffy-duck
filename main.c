#include <string.h>
#include <stdlib.h>

#include <arm_timer.h>
#include <rpi_interrupt.h>

#include "gpio.h"
#include "timer.h"

/* Defined in start.S. */
extern void _enable_interrupts();

int kernel_main(void) __attribute__((naked));
int kernel_main(void) {

    led_init();

    /* Enable the timer interrupt IRQ */
    RPI_GetIRQController()->Enable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ;

    /* Set up the system timer interrupt */
    /* Timer frequency = clk/256 * 0x400 */
    /* TODO ^^^ Look that up */
    RPI_GetArmTimer()->Load = 0x400;

    /* Set up the ARM timer */
    RPI_GetArmTimer()->Control =
        RPI_ARMTIMER_CTRL_23BIT |
        RPI_ARMTIMER_CTRL_ENABLE |
        RPI_ARMTIMER_CTRL_INT_ENABLE |
        RPI_ARMTIMER_CTRL_PRESCALE_256;

    /* Enable interrupts globally */
    _enable_interrupts();

    while (1) {
        /* spin */
    }
}
