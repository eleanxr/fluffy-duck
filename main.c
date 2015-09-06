#include <string.h>
#include <stdlib.h>

#include "gpio.h"

/* Loop variable */
volatile unsigned int tim;

int kernel_main(void) __attribute__((naked));
int kernel_main(void) {

    int loop;

    led_init();

    unsigned int * counters = malloc(1024 * sizeof(unsigned int));
    if (counters == 0) {
        while (1) {
            led_on();
        }
    }

    for (loop = 0; loop < 1024; loop++) {
        counters[loop] = 0;
    }

    while (1) {

        /* Wait */
        for (counters[0] = 0; counters[0] < 500000; counters[0]++)
            ;

        led_on();

        /* Wait */
        for (counters[1] = 0; counters[1] < 500000; counters[1]++)
            ;

        led_off();

    }
}
