        .arch msp430g2553
        .p2align 1,0

        ;.global?
        .text
jt:     
        .word default
        .word case01
        .word case02
        .word case03
        .word case04
        .word case05
        .word case06
        .word case07
        .word case08
        .word case09
        .word case10
        .word case11
        .word case12
        .word case13
        .word case14
        .word case15
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
        call #buzzer_set_period(523) 
        jmp end;
case02:
        mov #2, &state;
        call #buzzer_set_period(523)
        jmp end
case03:
        mov #3, &state;
        call #buzzer_set_period(500); //D
        jmp end
case04:
        mov #4, &state;
        call #buzzer_set_period(450); //E
        jmp end
case05:
        mov #5, &state;
        call #buzzer_set_period(450); //E
        jmp end;
case06:
        mov #6, &state;
        call #buzzer_set_period(500); //D
        jmp end;
case07:
        mov #7, &state;
        call #buzzer_set_period(523); //C
        jmp end;
case08:
        mov #8, &state;
        call #buzzer_set_period(600); //B
        jmp end;
case09:
        mov #9, &state;
        call #buzzer_set_period(650); //A
        jmp end;
case10:
        mov #10, &state;
        jmp end;
        call #buzzer_set_period(650); //A
case11:
        mov #11, &state;
        call #buzzer_set_period(600); //B
        jmp end;
case12:
        mov #12, &state;
        call #buzzer_set_period(523); //c
        jmp end;
case13:
        mov #13, &state;
        call #buzzer_set_period(600); //B
        jmp end;
case14:
        mov #14, &state;
        call #buzzer_set_period(600);
        jmp end;
case15:
        mov #15, &state;
        call #buzzer_set_period(0);
        buzzer_init();
        jmp end;
default:
        call #buzzer_init();

end: 
        ret
