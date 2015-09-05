#include "definitions.h"

/* GPIO Register Set  */
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

/* Loop variable */
volatile unsigned int tim;

int kernel_main(void) __attribute__((naked));
int kernel_main(void) {

    /* Enable GPIO 16 as an output by writing a 1 to the function select
     * 1 GPIO register
     */
    gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);

    while (1) {

        /* Wait */
        for (tim = 0; tim < 500000; tim++)
            ;

        /* Set the LED GPIO pin low */
        gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);

        /* Wait */
        for (tim = 0; tim < 500000; tim++)
            ;

        /* Set the LED GPIO pin high */
        gpio[LED_GPSET] = (1 << LED_GPIO_BIT);

    }
}
