#include <stdio.h>

void main(){
	uint32_t eax_input = 0x80000008;
	uint32_t eax_output;


	asm volatile(
		"mov %1, %%eax;" //double percentage to signify literal register name, single percentage for operand (either output register operand or input operand)
		"cpuid;"
		"mov %%eax, %0"
		: "=m" (eax_output) //output register operand (0) 
		:"m" (eax_input) //input operand (1) 
		:"eax" //clobber 
	); 

	printf("EAX output (hex): %x\n", eax_output );
	printf("Physical address bits (hex): %x\n", eax_output & 0xFF);
	printf("Linear address bits (hex): %x\n", (eax_output & 0xFF00) >> 8);
	


}