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
        cmp #16, &stateAssemlby
        jc default

        mov &stateAssemlby, r12
        add r12, r12 ; we are doing this to double the amount of "cells"
        mov jt(r12), r0 ;moving the data to the first position 

case01:
        mov #1, &stateAssemlby
        mov #523, r12
        call #buzzer_set_period
        ;jmp end;
case02:
        mov #2, &stateAssemlby;
        mov #523, r12
        call #buzzer_set_period
        jmp end
case03:
        mov #3, &stateAssemlby;
        mov #500, r12
        call #buzzer_set_period ; //D
        jmp end
case04:
        mov #4, &stateAssemlby;
        mov #450, r12
        call #buzzer_set_period; //E
        jmp end
case05:
        mov #5, &stateAssemlby;
        mov #450, r12
        call #buzzer_set_period ; //E
        jmp end;
case06:
        mov #6, &stateAssemlby;
        mov #500, r12
        call #buzzer_set_period; //D
        jmp end;
case07:
        mov #7, &stateAssemlby;
        mov #523, r12
        call #buzzer_set_period; //C
        jmp end;
case08:
        mov #8, &stateAssemlby;
        mov #600, r12
        call #buzzer_set_period ; //B
        jmp end;
case09:
        mov #9, &stateAssemlby;
        mov #650, r12
        call #buzzer_set_period ; //A
        jmp end;
case10:
        mov #10, &stateAssemlby;
        mov #650, r12
        call #buzzer_set_period; //A
        jmp end
case11:
        mov #11, &stateAssemlby;
        mov #600, r12
        call #buzzer_set_period ; //B
        jmp end;
case12:
        mov #12, &stateAssemlby;
        mov #523, r12
        call #buzzer_set_period; //c
        jmp end;
case13:
        mov #13, &stateAssemlby;
        mov #600, r12
        call #buzzer_set_period; //B
        jmp end;
case14:
        mov #14, &stateAssemlby;
        mov #600, r12
        call #buzzer_set_period;
        jmp end;
case15:
        mov #15, &stateAssemlby;
        mov #0, r12
        call #buzzer_set_period;
        call #buzzer_init;
        jmp end;
default:
        mov #600, r12
        call #buzzer_set_period;

end: 
        ret
