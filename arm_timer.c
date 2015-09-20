#include <arm_timer.h>

static rpi_armtimer_t * rpiArmTimer = (rpi_armtimer_t *)RPI_ARMTIMER_BASE;

rpi_armtimer_t * RPI_GetArmTimer() {
    return rpiArmTimer;
}
