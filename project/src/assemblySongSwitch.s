        .arch msp430g2553
        .p2align 1,0

        ;.global?
        .text
jt:     
        .word default
        .word case01
        .text
        .global state_adv
state_adv:
        cmp #16, &state
        jc default

        mov &state, r12
        add r12, r12 ; we are doing this to double the amount of "cells"
        mov jt(r12), r0 ;moving the data to the first position ro
case01:
        mov #1, &state
        mov #523, r12
        call #buzzer_set_period
        jmp end;
default:
        call #buzzer_init;

end: 
        ret
