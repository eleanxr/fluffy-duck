#ifndef _arm_timer_h_
#define _arm_timer_h_

#include <stdint.h>

/* ARM timer base address, from p. 196 of the BCM2835 peripherals manual. */
#define RPI_ARMTIMER_BASE 0x2000B400

#define RPI_ARMTIMER_CTRL_23BIT (1 << 1)

#define RPI_ARMTIMER_CTRL_PRESCALE_1   (0 << 2)
#define RPI_ARMTIMER_CTRL_PRESCALE_16  (1 << 2)
#define RPI_ARMTIMER_CTRL_PRESCALE_256 (2 << 2)

#define RPI_ARMTIMER_CTRL_INT_ENABLE  (1 << 5)
#define RPI_ARMTIMER_CTRL_INT_DISABLE (0 << 5)

#define RPI_ARMTIMER_CTRL_ENABLE  (1 << 7)
#define RPI_ARMTIMER_CTRL_DISABLE (0 << 7)

/* Memory mapped structure for accessing the ARM timer. See p. 196 of the
 * BCM2835 manual.
 */
typedef struct {
    volatile uint32_t Load;
    volatile uint32_t Value;
    volatile uint32_t Control;
    volatile uint32_t IRQClear;
    volatile uint32_t RawIRQ;
    volatile uint32_t MaskedIRQ;
    volatile uint32_t Reload;
    volatile uint32_t PreDivider;
    volatile uint32_t FreeRunningCounter;
} rpi_armtimer_t;

rpi_armtimer_t * RPI_GetArmTimer();

#endif
