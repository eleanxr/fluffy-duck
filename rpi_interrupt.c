#include <rpi_interrupt.h>

static rpi_irq_controller_t * rpiIRQController =
    (rpi_irq_controller_t *)RPI_INTERRUPT_CONTROLLER_ADDRESS;

rpi_irq_controller_t * RPI_GetIRQController() {
    return rpiIRQController;
}
