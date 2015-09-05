.section ".text.startup"

.global _start
.global _get_stack_pointer

_start:
    // Load the startup address into the sp (stack pointer)
    // register. On the ARM processor, this is 0x8000
    // ldr sp, =0x8000
    // Give ourselves 64MB of heap space before we start the stack.
    ldr sp, =(64 * 1024 * 1024)
    // The rest of the startup function is in C. Run it.
    b _cstartup

_inf_loop:
    b _inf_loop

_get_stack_pointer:
    // return the stack pointer
    str sp, [sp]
    ldr r0, [sp]
    // Return
    mov pc, lr

