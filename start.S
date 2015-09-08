.section ".text.startup"

.global _start
.global _get_stack_pointer
.global _exception_table

_start:
    // Set up the exception vector table (ARM AR architecture 1.8.1 table B1-3
    ldr pc, _reset_h
    ldr pc, _undefined_instruction_vector_h
    ldr pc, _software_interrupt_vector_h
    ldr pc, _prefetch_abort_vector_h
    ldr pc, _data_abort_vector_h
    ldr pc, _unused_handler_h
    ldr pc, _interrupt_vector_h
    ldr pc, _fast_interrupt_vector_h

// Create a table to control the interrupt vector table addresses.
// If we didn't do this, the compiler would generate its own and
// we wouldn't be able to move the table to 0x0 on startup.
_reset_h:                        .word _reset_
_undefined_instruction_vector_h: .word undefined_instruction_vector
_software_interrupt_vector_h:    .word software_interrupt_vector
_prefetch_abort_vector_h:        .word prefetch_abort_vector
_data_abort_vector_h:            .word data_abort_vector
_unused_handler_h:               .word _reset_
_interrupt_vector_h:             .word interrupt_vector
_fast_interrupt_vector_h:        .word fast_interrupt_vector

_reset_:
    // Copy the vector table to the active table at 0x0000
    mov r0, #0x8000
    mov r1, #0x0000
    ldmia r0!,{r2, r3, r4, r5, r6, r7, r8, r9}
    stmia r1!,{r2, r3, r4, r5, r6, r7, r8, r9}
    ldmia r0!,{r2, r3, r4, r5, r6, r7, r8, r9}
    stmia r1!,{r2, r3, r4, r5, r6, r7, r8, r9}
    
    // Load the startup address into the sp (stack pointer)
    // register. On the ARM processor, this is 0x8000
    // ldr sp, =0x8000
    // Give ourselves 64MB of heap space before we start the stack.
    mov sp, #(64 * 1024 * 1024)
    // The rest of the startup function is in C. Run it.
    bl _cstartup

_inf_loop:
    b _inf_loop

_get_stack_pointer:
    // return the stack pointer
    str sp, [sp]
    ldr r0, [sp]
    // Return
    mov pc, lr

