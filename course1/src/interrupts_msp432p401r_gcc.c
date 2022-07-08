//*****************************************************************************
//
// Copyright (C) 2012 - 2016 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//  Redistributions of source code must retain the above copyright
//  notice, this list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the
//  documentation and/or other materials provided with the
//  distribution.
//
//  Neither the name of Texas Instruments Incorporated nor the names of
//  its contributors may be used to endorse or promote products derived
//  from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// MSP432P401R Interrupt Vector Implementation and startup code for GCC
//
//****************************************************************************

#include <stdint.h>

/* Entry point for the application. */
extern int main(void);

/* External declaration for system initialization function                  */
extern void SystemInit(void);

/* Forward declaration of the default fault handlers. */
/* This is the code that gets called when the processor first starts execution */
/* following a reset event.  Only the absolutely necessary set is performed,   */
/* after which the application supplied entry() routine is called.  Any fancy  */
/* actions (such as making decisions based on the reset cause register, and    */
/* resetting the bits in that register) are left solely in the hands of the    */
/* application.
 *
 * This is the code that gets called when the processor first starts execution */
/* following a reset event.  Only the absolutely necessary set is performed,   */
/* after which the application supplied entry() routine is called.  Any fancy  */
/* actions (such as making decisions based on the reset cause register, and    */
/* resetting the bits in that register) are left solely in the hands of the    */
/* application.                                                                */
extern uint32_t __data_load__;
extern uint32_t __data_start__;
extern uint32_t __data_end__;

#ifndef HWREG
#define HWREG(x) (*((volatile uint32_t *)(x)))
#endif

__attribute__((interrupt,section(".text:Reset_Handler")))
void Reset_Handler(void)
{
	/* Copy the data segment initializers from flash to SRAM. */
	    uint32_t *pui32Src, *pui32Dest;

	    pui32Src = &__data_load__;
	    for(pui32Dest = &__data_start__; pui32Dest < &__data_end__; )
	    {
	        *pui32Dest++ = *pui32Src++;
	    }

	    /* Zero fill the bss segment. */
	    __asm("    ldr     r0, =__bss_start__\n"
	          "    ldr     r1, =__bss_end__\n"
	          "    mov     r2, #0\n"
	          "    .thumb_func\n"
	          "zero_loop:\n"
	          "    cmp     r0, r1\n"
	          "    it      lt\n"
	          "    strlt   r2, [r0], #4\n"
	          "    blt     zero_loop");

	    /* Call system initialization routine */
		SystemInit();

	    /* Call the application's entry point. */
	    main();
}

/* This is the code that gets called when the processor receives a NMI.  This  */
/* simply enters an infinite loop, preserving the system state for examination */
/* by a debugger.                                                              */
__attribute__((interrupt,section(".text:NMI_Handler")))
void NMI_Handler(void)
{
    /* Enter an infinite loop. */
    while(1)
    {
    }
}


/* This is the code that gets called when the processor receives a fault        */
/* interrupt.  This simply enters an infinite loop, preserving the system state */
/* for examination by a debugger.                                               */
__attribute__((interrupt,section(".text:HardFault_Handler")))
void HardFault_Handler(void)
{
    /* Enter an infinite loop. */
    while(1)
    {
    }
}

__attribute__((interrupt,section(".text:Default_Handler")))
void Default_Handler(void)
{
	/* Enter an infinite loop. */
	while(1)
	{
	}
}

__attribute__((weak,alias("Default_Handler")))
void MemManage_Handler(void);
__attribute__((weak,alias("Default_Handler")))
void BusFault_Handler(void);
__attribute__((weak,alias("Default_Handler")))
void UsageFault_Handler(void);
__attribute__((weak,alias("Default_Handler")))
void SVC_Handler(void);
__attribute__((weak,alias("Default_Handler")))
void DebugMon_Handler(void);
__attribute__((weak,alias("Default_Handler")))
void PendSV_Handler(void);

/* device specific interrupt handler */
__attribute__((weak,alias("Default_Handler")))
void SysTick_Handler(void);
__attribute__((weak,alias("Default_Handler")))
void PSS_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void CS_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void PCM_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void WDT_A_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void FPU_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void FLCTL_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void COMP_E0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void COMP_E1_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA0_0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA0_N_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA1_0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA1_N_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA2_0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA2_N_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA3_0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void TA3_N_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIA0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIA1_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIA2_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIA3_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIB0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIB1_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIB2_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void EUSCIB3_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void ADC14_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void T32_INT1_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void T32_INT2_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void T32_INTC_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void AES256_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void RTC_C_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void DMA_ERR_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void DMA_INT3_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void DMA_INT2_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void DMA_INT1_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void DMA_INT0_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void PORT1_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void PORT2_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void PORT3_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void PORT4_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void PORT5_IRQHandler(void);
__attribute__((weak,alias("Default_Handler")))
void PORT6_IRQHandler(void);

