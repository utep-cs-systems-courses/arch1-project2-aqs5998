# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: buzzer.elf 

#additional rules for files
buzzer.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o assemblySongSwitch.o switches.o buzzer.o buzzerMain.o wdInterruptHandler.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^

load: buzzer.elf
	msp430loader.sh buzzer.elf
#should remove all o and elf files
clean:
	rm -f *.o *.elf

buzzer.c: buzzer.h
buzzerMain.c: buzzer.h
stateMachines.o: stateMachines.h
assemblySongSwitch.o :assemblySongSwitch.h
wdInterruptHandler.o: stateMachines.h


