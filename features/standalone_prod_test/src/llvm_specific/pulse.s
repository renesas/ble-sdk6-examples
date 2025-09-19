.syntax unified
.thumb

.global measure_pulse
.type measure_pulse, %function

// Constants
.equ GUARD_COUNTER_INIT, 3000000
.equ SYSTICK_CTRL_ADDR,  0xE000E010
.equ SYSTICK_LOAD_ADDR,  0xE000E014
.equ SYSTICK_VAL_ADDR,   0xE000E018
.equ SYSTICK_CALIB_ADDR, 0xE000E01C

measure_pulse:
    push {r1-r5}
    mov r5, lr

    ldr r5, =GUARD_COUNTER_INIT

wait_low:
    subs r5, r5, #1
    beq abort
    ldrh r2, [r0]
    tst r2, r1
    bne wait_low

wait_high:
    subs r5, r5, #1
    beq abort
    ldrh r2, [r0]
    tst r2, r1
    beq wait_high

    // Start SysTick timer
    ldr r2, =SYSTICK_CTRL_ADDR
    ldr r3, [r2]
    movs r4, #1
    orrs r3, r3, r4
    str r3, [r2]

while_high:
    subs r5, r5, #1
    beq abort
    ldrh r2, [r0]
    tst r2, r1
    bne while_high

    // Read SysTick value
    ldr r2, =SYSTICK_VAL_ADDR
    ldr r0, [r2]
    pop {r1-r5}
    bx lr

abort:
    movs r0, #0
    pop {r1-r5}
    bx lr
