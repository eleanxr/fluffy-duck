#include "gpio.h"

#include "gpio_defs.h"

/* GPIO Register Set  */
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

void led_init()
{
    /* Enable GPIO 16 as an output by writing a 1 to the function select
     * 1 GPIO register
     */
    gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);
}

void led_on()
{
    gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);
}

void led_off()
{
    gpio[LED_GPSET] = (1 << LED_GPIO_BIT);
}

