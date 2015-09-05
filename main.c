#include <string.h>
#include <stdlib.h>

#include "definitions.h"

/* GPIO Register Set  */
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

/* Loop variable */
volatile unsigned int tim;

int kernel_main(void) __attribute__((naked));
int kernel_main(void) {

    int loop;

    /* Enable GPIO 16 as an output by writing a 1 to the function select
     * 1 GPIO register
     */
    gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);

    unsigned int * counters = malloc(1024 * sizeof(unsigned int));
    if (counters == 0) {
        while (1) {
            gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);
        }
    }

    for (loop = 0; loop < 1024; loop++) {
        counters[loop] = 0;
    }

    while (1) {

        /* Wait */
        for (counters[0] = 0; counters[0] < 500000; counters[0]++)
            ;

        /* Set the LED GPIO pin low */
        gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);

        /* Wait */
        for (counters[1] = 0; counters[1] < 500000; counters[1]++)
            ;

        /* Set the LED GPIO pin high */
        gpio[LED_GPSET] = (1 << LED_GPIO_BIT);

    }
}
