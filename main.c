#include <string.h>
#include <stdlib.h>

#include "gpio.h"
#include "timer.h"

int kernel_main(void) __attribute__((naked));
int kernel_main(void) {

    led_init();

    while (1) {
        wait_us(500000);

        led_on();

        wait_us(500000);

        led_off();
    }
}
