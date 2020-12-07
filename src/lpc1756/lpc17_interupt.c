/**************************************************
 *
 * This file contains an interrupt vector for Cortex-M written in C.
 * The actual interrupt functions must be provided by the application developer.
 *
 * Copyright 2007 IAR Systems. All rights reserved.
 *
 * $Revision: 66254 $
 *
 **************************************************/
#pragma language=extended
#pragma segment="CSTACK"

//Default interrupt handler 
static void Default_Handler(void){while(1){;}}

//Empty handlers aliased to the default handler /
///#pragma call_graph_root = "interrupt"
__weak void NMI_Handler(void);
#pragma weak NMI_Handler=Default_Handler

__weak void HardFault_Handler(void);
#pragma weak HardFault_Handler=Default_Handler

__weak void MemManagement_Handler(void);
#pragma weak MemManagement_Handler=Default_Handler

__weak void BusFault_Handler(void);
#pragma weak BusFault_Handler=Default_Handler

__weak void UsageFault_Handler(void);
#pragma weak UsageFault_Handler=Default_Handler

__weak void SVC_Handler(void);
#pragma weak SVC_Handler=Default_Handler

__weak void DebugMon_Handler(void);
#pragma weak DebugMon_Handler=Default_Handler

__weak void PendSV_Handler(void);
#pragma weak PendSV_Handler=Default_Handler

//void SysTick_Handler(void);
//#pragma weak SysTick_Handler=Default_Handler

__weak void WDT_IRQHandler(void);
#pragma weak WDT_IRQHandler=Default_Handler

extern void TIMER0_IRQHandler(void);
///#pragma weak TIMER0_IRQHandler=Default_Handler

void TIMER1_IRQHandler(void);
#pragma weak TIMER1_IRQHandler=Default_Handler

__weak void TIMER2_IRQHandler(void);
#pragma weak TIMER2_IRQHandler=Default_Handler

__weak void TIMER3_IRQHandler(void);
#pragma weak TIMER3_IRQHandler=Default_Handler

__weak void UART0_IRQHandler(void);
#pragma weak UART0_IRQHandler=Default_Handler

__weak void UART1_IRQHandler(void);
#pragma weak UART1_IRQHandler=Default_Handler

__weak void UART2_IRQHandler(void);
#pragma weak UART2_IRQHandler=Default_Handler

__weak void UART3_IRQHandler(void);
#pragma weak UART3_IRQHandler=Default_Handler

__weak void PWM1_IRQHandler(void);
#pragma weak PWM1_IRQHandler=Default_Handler

__weak void I2C0_IRQHandler(void);
#pragma weak I2C0_IRQHandler=Default_Handler

__weak void I2C1_IRQHandler(void);
#pragma weak I2C1_IRQHandler=Default_Handler

__weak void I2C2_IRQHandler(void);
#pragma weak I2C2_IRQHandler=Default_Handler

__weak void SPI_IRQHandler(void);
#pragma weak SPI_IRQHandler=Default_Handler

__weak void SSP0_IRQHandler(void);
#pragma weak SSP0_IRQHandler=Default_Handler

__weak void SSP1_IRQHandler(void);
#pragma weak SSP1_IRQHandler=Default_Handler

__weak void PLL0_IRQHandler(void);
#pragma weak PLL0_IRQHandler=Default_Handler

__weak void RTC_IRQHandler(void);
#pragma weak RTC_IRQHandler=Default_Handler

__weak void EINT0_IRQHandler(void);
#pragma weak EINT0_IRQHandler=Default_Handler

__weak void EINT1_IRQHandler(void);
#pragma weak EINT1_IRQHandler=Default_Handler

__weak void EINT2_IRQHandler(void);
#pragma weak EINT2_IRQHandler=Default_Handler

//extern void EINT3_IRQHandler(void);
//#pragma weak EINT3_IRQHandler=Default_Handler

__weak void ADC_IRQHandler(void);
#pragma weak ADC_IRQHandler=Default_Handler

__weak void BOD_IRQHandler(void);
#pragma weak BOD_IRQHandler=Default_Handler

__weak void USB_IRQHandler(void);
#pragma weak USB_IRQHandler=Default_Handler

__weak void CAN_IRQHandler(void);
#pragma weak CAN_IRQHandler=Default_Handler

__weak void DMA_IRQHandler(void);
#pragma weak DMA_IRQHandler=Default_Handler

__weak void I2S_IRQHandler(void);
#pragma weak I2S_IRQHandler=Default_Handler

__weak void ENET_IRQHandler(void);
#pragma weak ENET_IRQHandler=Default_Handler

__weak void RIT_IRQHandler(void);
#pragma weak RIT_IRQHandler=Default_Handler

__weak void MCPWM_IRQHandler(void);
#pragma weak MCPWM_IRQHandler=Default_Handler

__weak void QEI_IRQHandler(void);
#pragma weak QEI_IRQHandler=Default_Handler

__weak void PLL1_IRQHandler(void);
#pragma weak PLL1_IRQHandler=Default_Handler

__weak void USBACT_IRQHandler(void);
#pragma weak USBACT_IRQHandler=Default_Handler

void CANACT_IRQHandler(void);
#pragma weak CANACT_IRQHandler=Default_Handler


extern void __iar_program_start( void );


extern void EINT3_IRQHandler(void);
/*
extern void NMI_Handler( void );
extern void HardFault_Handler( void );
extern void MemManage_Handler( void );
extern void BusFault_Handler( void );
extern void UsageFault_Handler( void );
extern void SVC_Handler( void );
extern void DebugMon_Handler( void );
extern void PendSV_Handler( void );
extern void SysTick_Handler( void ); */
///void Reset_Handler(void);

#pragma call_graph_root = "interrupt"
__weak void SysTick_Handler(void) {while (1) {}}

typedef void(*intfunc)( void );
typedef union {intfunc __fun; void * __ptr;} intvec_elem;

// The vector table is normally located at address 0.
// When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
// If you need to define interrupt service routines,
// make a copy of this file and include it in your project.
// The name "__vector_table" has special meaning for C-SPY, which
// is where to find the SP start value.
// If vector table is not located at address 0, the user has to initialize
// the  NVIC vector table register (VTOR) before using interrupts.

//#pragma location=".intvec" 
const intvec_elem __vector_table[] @ ".intvec" =
{
  //Cortex-M3 Interrupts: IRQ Number - Exception Number - Offset - Vector Description  

{.__ptr = __sfe("CSTACK")},//  0  0x00  Initial SP Value - defined in Linker Script
  __iar_program_start,     //  1  0x04	Reset Handler
  NMI_Handler,		// -14 2  0x08	Non-Maskable Interrupt Handler
  HardFault_Handler,	// -13 3  0x0C	Hard Fault Handler +
  MemManagement_Handler,// -12 4  0x10	Memory Management Fault Handler
  BusFault_Handler,	// -11 5  0x14	Bus Fault Handler
  UsageFault_Handler,	// -10 6  0x18	Usage Fault Handler
  0,			//     7  0x1C	Reserved
  0,			//     8  0x20	Reserved
  0,			//     9  0x24	Reserved
  0,			//     10 0x28	Reserved
  SVC_Handler,		//     11 0x2C	SVCall Handler +
  DebugMon_Handler,	//     12 0x30	Debug Monitor Handler  +
  0,			// -2  13 0x34	Reserved        + 
  PendSV_Handler,	// -1  14 0x38	PendSV Handler  +
  SysTick_Handler,	//  0  15 0x3C	SysTick Handler +

  //LPC17xx Interrupts: 
  //Interrupt ID - Exception Number - Vector Offset - Description and Flags
  WDT_IRQHandler,	// 0  16 0x40	WDT Watchdog Interrupt (WDINT)
  TIMER0_IRQHandler,	// 1  17 0x44	Timer 0 Match 0 - 1 (MR0, MR1)
			// 		Capture 0 - 1 (CR0, CR1)
  TIMER1_IRQHandler,	// 2  18 0x48 	Timer 1 Match 0 - 2
			// 		(MR0, MR1, MR2), Capture 0 - 1 (CR0, CR1)
  TIMER2_IRQHandler,	// 3  19 0x4C	Timer 2 Match 0-3
			// 		Capture 0-1
  TIMER3_IRQHandler,	// 4  20 0x50	Timer 3 Match 0-3
			// 		Capture 0-1
  UART0_IRQHandler,	// 5  21 0x54	UART0 Rx Line Status (RLS)
			// 		Transmit Holding Register Empty (THRE)
			// 		Rx Data Available (RDA)
			// 		Character Time-out Indicator (CTI)
			// 		End of Auto-Baud (ABEO)
			// 		Auto-Baud Time-Out (ABTO)
  UART1_IRQHandler,	// 6  22 0x58	UART1 Rx Line Status (RLS)
			// 		Transmit Holding Register Empty (THRE)
			// 		Rx Data Available (RDA)
			// 		Character Time-out Indicator (CTI)
			// 		Modem Control Change
			// 		End of Auto-Baud (ABEO)
			// 		Auto-Baud Time-Out (ABTO)
  UART2_IRQHandler,	// 7  23 0x5C	UART 2 Rx Line Status (RLS)
			// 		Transmit Holding Register Empty (THRE)
			// 		Rx Data Available (RDA)
			// 		Character Time-out Indicator (CTI)
			// 		End of Auto-Baud (ABEO)
			// 		Auto-Baud Time-Out (ABTO)
  UART3_IRQHandler,	// 8  24 0x60	UART 3 Rx Line Status (RLS)
			// 		Transmit Holding Register Empty (THRE)
			// 		Rx Data Available (RDA)
			// 		Character Time-out Indicator (CTI)
			// 		End of Auto-Baud (ABEO)
			// 		Auto-Baud Time-Out (ABTO)
  PWM1_IRQHandler,	// 9  25 0x64	PWM1 Match 0 - 6 of PWM1
			// 		Capture 0-1 of PWM1
  I2C0_IRQHandler,	// 10 26 0x68	I2C0 SI (state change)
  I2C1_IRQHandler,	// 11 27 0x6C	I2C1 SI (state change)
  I2C2_IRQHandler,	// 12 28 0x70	I2C2 SI (state change)
  SPI_IRQHandler,	// 13 29 0x74	SPI SPI Interrupt Flag (SPIF)
			// 		Mode Fault (MODF)
  SSP0_IRQHandler,	// 14 30 0x78	SSP0 Tx FIFO half empty of SSP0
			// 		Rx FIFO half full of SSP0
			// 		Rx Timeout of SSP0
			// 		Rx Overrun of SSP0
  SSP1_IRQHandler,	// 15 31 0x7C	SSP 1 Tx FIFO half empty
			// 		Rx FIFO half full
			// 		Rx Timeout
			// 		Rx Overrun
  PLL0_IRQHandler,	// 16 32 0x80	PLL0 (Main PLL) PLL0 Lock (PLOCK0)
  RTC_IRQHandler,	// 17 33 0x84	RTC Counter Increment (RTCCIF)
			// 		Alarm (RTCALF)
  EINT0_IRQHandler,	// 18 34 0x88	External Interrupt External Interrupt 0 (EINT0)
  EINT1_IRQHandler,	// 19 35 0x8C	External Interrupt External Interrupt 1 (EINT1)
  EINT2_IRQHandler,	// 20 36 0x90	External Interrupt External Interrupt 2 (EINT2)
  EINT3_IRQHandler,	// 21 37 0x94	External Interrupt External Interrupt 3 (EINT3).
			// 		Note: EINT3 channel is shared with GPIO interrupts
  ADC_IRQHandler,	// 22 38 0x98	ADC A/D Converter end of conversion
  BOD_IRQHandler,	// 23 39 0x9C	BOD Brown Out detect
  USB_IRQHandler,	// 24 40 0xA0	USB USB_INT_REQ_LP, USB_INT_REQ_HP, USB_INT_REQ_DMA
  CAN_IRQHandler,	// 25 41 0xA4	CAN CAN Common, CAN 0 Tx, CAN 0 Rx, CAN 1 Tx, CAN 1 Rx
  DMA_IRQHandler,	// 26 42 0xA8	GPDMA IntStatus of DMA channel 0, IntStatus of DMA channel 1
  I2S_IRQHandler,	// 27 43 0xAC	I2S irq, dmareq1, dmareq2
  ENET_IRQHandler,	// 28 44 0xB0	Ethernet WakeupInt, SoftInt, TxDoneInt, TxFinishedInt, TxErrorInt,
			// 		TxUnderrunInt, RxDoneInt, RxFinishedInt, RxErrorInt, RxOverrunInt.
  RIT_IRQHandler,	// 29 45 0xB4	Repetitive Interrupt Timer (RITINT)
  MCPWM_IRQHandler,	// 30 46 0xB8	Motor Control PWM IPER[2:0], IPW[2:0], ICAP[2:0], FES
  QEI_IRQHandler,	// 31 47 0xBC	Quadrature Encoder INX_Int, TIM_Int, VELC_Int, DIR_Int, ERR_Int, ENCLK_Int,
			// 		POS0_Int, POS1_Int, POS2_Int, REV_Int, POS0REV_Int, POS1REV_Int, POS2REV_Int
  PLL1_IRQHandler,	// 32 48 0xC0	PLL1 (USB PLL) PLL1 Lock (PLOCK1)
  USBACT_IRQHandler,	// 33 49 0xC4	USB Activity Interrupt USB_NEED_CLK
  CANACT_IRQHandler,	// 34 50 0xC8	CAN Activity Interrupt CAN1WAKE, CAN2WAKE 
}; 

/*
#include "lpc17.h"
__weak void Reset_Handler(void)
{
  // Set the vector table location, Vector Table Offset Register
  SCB_VTOR = (uint32_t)&__vector_table;
}*/

#include "lpc17.h"
void __cmain(void);
__weak void __iar_init_core(void);
__weak void __iar_init_vfp(void);

#pragma required=__vector_table
void __iar_program_start(void)
{
  __iar_init_core();
  __iar_init_vfp();
  __cmain();
}

/*
////extern unsigned long _StackTop;
//__no_init unsigned long _StackTop @ ".stacktop";
//#pragma location = ".stacktop"
__root unsigned long _StackTop @ ".stacktop";
*/