/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



#include <stdio.h>
#include <stdint.h>

int32_t sum_numbers(int32_t x, int32_t y){


	int32_t res;
	__asm volatile("SVC #36");
	__asm volatile ("MOV %0,R0": "=r"(res):  );
	return res;
}

int32_t sub_numbers(int32_t x, int32_t y){

	int32_t res;
	__asm volatile("SVC #37");
	__asm volatile ("MOV %0,R0": "=r"(res):  );
	return res;

}

int32_t div_numbers(int32_t x, int32_t y){

	int32_t res;
	__asm volatile("SVC #39");
	__asm volatile ("MOV %0,R0": "=r"(res):  );
	return res;

}

int32_t mul_numbers(int32_t x, int32_t y){

	int32_t res;
	__asm volatile("SVC #38");
	__asm volatile ("MOV %0,R0": "=r"(res):  );
	return res;

}

int main(void)
{

	int32_t res;

	res= sum_numbers(40,-90);
	printf("add_res = %ld\n",res);

	res= sub_numbers(40,20);
	printf("add_res = %ld\n",res);

	res= mul_numbers(3,2);
	printf("add_res = %ld\n",res);

	res= div_numbers(4,2);
	printf("add_res = %ld\n",res);

	for(;;);
}

__attribute__((naked)) void SVC_Handler (void){

	//1.get the value of MSP
	__asm ("MRS R0,MSP");
	__asm ("B SVC_Handler_c");


}

void SVC_Handler_c(uint32_t* pBaseOfStackFrame){

	printf("In SVC Handler\n");

	int32_t arg0,arg1,res;

	uint8_t *pReturn_addr = (uint8_t*) pBaseOfStackFrame[6];

	//2.decreament the address by 2 to point to
	//opcode of SVC instruction in program memory

	pReturn_addr-=2;

	//3. Get the SVC number

	uint8_t SVC_number = *pReturn_addr;

	printf("SVC number is %d\n",SVC_number);

	arg0 = pBaseOfStackFrame[0];
	arg1 = pBaseOfStackFrame[1];

	switch(SVC_number){

	case 36:
		res= arg0 + arg1;
		break;

	case 37:
		res= arg0 - arg1;
		break;

	case 38:
		res= arg0 * arg1;
		break;

	case 39:
		res= arg0 / arg1;
		break;

	default:
		printf("Invalid SVC code\n");

	}

	pBaseOfStackFrame[0] = res;
}
