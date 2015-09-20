#ifndef _rpi_interrupt_h_
#define _rpi_interrupt_h_

#include <stdint.h>

/*
* The base address of the interrupt controller. From Section 7.5 of the BC2835
* peripherals manual, this is 0x7e000b000. There's a 0x200 offset to the first
* addressable register from there and all addresses are mapped to a base
* address of 0x2000000.
*/
#define RPI_INTERRUPT_CONTROLLER_ADDRESS (0x2000B200)

/* Memory mapped IRQ controller. See BCM2835 peripherals p. 112 */
typedef struct {
    volatile uint32_t IRQ_basic_pending;
    volatile uint32_t IRQ_pending_1;
    volatile uint32_t IRQ_pending_2;
    volatile uint32_t FIQ_control;
    volatile uint32_t Enable_IRQs_1;
    volatile uint32_t Enable_IRQs_2;
    volatile uint32_t Enable_Basic_IRQs;
    volatile uint32_t Disable_IRQs_1;
    volatile uint32_t Disable_IRQs_2;
    volatile uint32_t Disable_Basic_IRQs;
} rpi_irq_controller_t;

/* Basic IRQ table. BCM2835 peripherals p. 112 */
#define RPI_BASIC_ARM_TIMER_IRQ         (1 << 0)
#define RPI_BASIC_ARM_MAILBOX_IRQ       (1 << 1)
#define RPI_BASIC_ARM_DOORBELL_0_IRQ    (1 << 2)
#define RPI_BASIC_ARM_DOORBELL_1_IRQ    (1 << 3)
#define RPI_BASIC_GPU_0_HALTED_IRQ      (1 << 4)
#define RPI_BASIC_GPU_1_HALTED_IRQ      (1 << 5)
#define RPI_BASIC_ACCESS_ERROR_1_IRQ    (1 << 6)
#define RPI_BASIC_ACCESS_ERROR_0_IRQ    (1 << 7)

rpi_irq_controller_t * RPI_GetIRQController();

#endif
