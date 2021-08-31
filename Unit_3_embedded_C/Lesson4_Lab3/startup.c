#include <stdint.h>

extern unsigned int _E_text;
extern unsigned int _E_DATA;
extern unsigned int _S_DATA;
extern unsigned int _E_bss;
extern unsigned int _S_bss;

//extern from main.c
extern int main(void);

void Reset_Handler(void);

void Default_Handler(void)
{

	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler() __attribute__((weak, alias("Default_Handler")));

//booking 1024 B for stack in bss section (256*4=1024)
static unsigned long Stack_top[256];

//arry of pointer to functions
void (*g_PF_vectors[])() __attribute__((section(".vectors"))) =
	{
		(void(*)())	((unsigned long) Stack_top + sizeof(Stack_top)),
		&Reset_Handler,
		&NMI_Handler,
		&H_fault_Handler
};

void Reset_Handler(void)
{
	//copy data section from rom to sram
	unsigned int data_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA; //copy byte by byte even if there is an alignment, casting as it is a symbol
	unsigned char *src = (unsigned char *)&_E_text;
	unsigned char *dest = (unsigned char *)&_S_DATA;

	int i;
	for (i = 0; i < data_size; i++)
	{
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	}

	//reserve a space for bss in sram and init it with 0
	unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	dest = (unsigned char *)&_S_bss;

	for (i = 0; i < bss_size; i++)
	{
		*((unsigned char *)dest++) = (unsigned char)0;
	}

	main();
}
