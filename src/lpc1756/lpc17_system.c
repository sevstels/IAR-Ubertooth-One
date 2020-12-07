#include "lpc17_system.h"
#include <stdint.h>

#pragma section = ".intvec" 

/* Reset_Handler variables defined in linker script */
//extern unsigned long _interrupt_vector_table;
//extern unsigned long _data;
//extern unsigned long _edata;
//extern unsigned long _etext;
//extern unsigned long _bss;
//extern unsigned long _ebss;

void SystemInit(void)
{   
  /*
  unsigned long *src, *dest;

  // Copy the data segment initializers from flash to SRAM
  src = &_etext;
  for(dest = &_data; dest < &_edata; )
  {
   *dest++ = *src++;
  }

  // Initialize the .bss segment of memory to zeros
  src = &_bss;
  while (src < &_ebss)
  {
    *src++ = 0;
  }
  __libc_init_array(); */
  
/*   
  
  //================ Clock Setup  
  // activate main oscillator
  SCS = SCS_OSCEN;
  while (!(SCS & SCS_OSCSTAT));

  //Setup Clock Divider temporarily set CPU clock divider to 1
  CCLKCFG = 0;   
 
  //Periphral clock must be selected before PLL0 enabling and connecting
  // - according errata.lpc1768-16.March.2010 -
  //Peripheral Clock Selection 
  PCLKSEL0 = PCLKSEL0_Val;     
  PCLKSEL1 = PCLKSEL1_Val;

#if (PLL0_SETUP)
  //Select Clock Source for PLL0
  CLKSRCSEL = CLKSRCSEL_Val;    

  //configure PLL0
  PLL0CFG   = PLL0CFG_Val;      
  PLL0FEED  = 0xAA;
  PLL0FEED  = 0x55;

  //PLL0 Enable
  PLL0CON   = 0x01;             
  PLL0FEED  = 0xAA;
  PLL0FEED  = 0x55;
  //Wait for PLOCK0
  while (!(PLL0STAT & (1<<26)));
  
  //PLL0 Enable & Connect
  PLL0CON   = 0x03;             
  PLL0FEED  = 0xAA;
  PLL0FEED  = 0x55;
  //Wait for PLLC0_STAT & PLLE0_STAT
  while (!(PLL0STAT & ((1<<25) | (1<<24))));
#endif

#if (PLL1_SETUP)
  PLL1CFG   = PLL1CFG_Val;
  PLL1FEED  = 0xAA;
  PLL1FEED  = 0x55;
  
  //PLL1 Enable
  PLL1CON   = 0x01;            
  PLL1FEED  = 0xAA;
  PLL1FEED  = 0x55;
  //Wait for PLOCK1
  while (!(PLL1STAT & (1<<10)));
  
  //PLL1 Enable & Connect
  PLL1CON   = 0x03;             
  PLL1FEED  = 0xAA;
  PLL1FEED  = 0x55;
  //Wait for PLLC1_STAT & PLLE1_STAT
  while (!(PLL1STAT & ((1<< 9) | (1<< 8))));
  
#else
  //Setup USB Clock Divider
  USBCLKCFG = USBCLKCFG_Val;   
#endif
  //Power Control for Peripherals
  PCONP     = PCONP_Val;        
  //Clock Output Configuration
  CLKOUTCFG = CLKOUTCFG_Val;    
#endif

#if (FLASH_SETUP == 1) 
  //Flash Accelerator Setup
  FLASHCFG  = FLASHCFG_Val;
#endif */  
  
  //Set the vector table location
  SCB_VTOR = (unsigned long) __section_begin(".intvec");
}

void SystemCoreClockUpdate(void){ }