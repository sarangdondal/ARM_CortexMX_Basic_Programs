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

#include<stdio.h>



int fun_add(int a, int b, int c, int d){

	return a+b+c+d;

}

__attribute__((naked)) void change_sp_to_psp(void)
{
	__asm volatile(".equ SRAM_END, (0x20000000+(128*1024))");
	__asm volatile(".equ STACK_PSP_START, (SRAM_END-512)");
	__asm volatile("LDR R0,=STACK_PSP_START");
	__asm volatile("MSR PSP, R0");
	__asm volatile("MOV R0, #0X02");
	__asm volatile("MSR CONTROL, R0");
	__asm volatile("BX LR");





}

void generate_exception(void){

	__asm volatile("SVC #0x02");

}

int main(void)
{
    /* Loop forever */

	//change sp to psp

	change_sp_to_psp();

	int ret;

	ret=fun_add(1,4,5,6);
	printf("result= %d\n",ret);

	generate_exception();
	for(;;);
}

void SVC_Handler(void){

	printf("In SVC Handler\n");

	}
