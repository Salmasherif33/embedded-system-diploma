#@Prepared by <<<< Salma Sherif >>>>>>

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = Lab3_ToggleLed_Cortex_m4

all: $(Project_name).bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	 $(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

#@uart.o: uart.c
	#@$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@


$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf
	
$(Project_name).bin: $(Project_name).elf
	 $(CC)objcopy.exe -O binary $< $@
	 
	 
clean-all:
	rm *.o *bin *.elf *.map

	 