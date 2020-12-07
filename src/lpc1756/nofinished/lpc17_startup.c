#include <lpc17.h>

__root unsigned long _interrupt_vector_table @ 0x400 = 0;
__root unsigned long _data  @ ".data"; //!!!! не правильно лежит ?
__root unsigned long _edata @ ".data";
__root unsigned long _etext @ ".text";
extern unsigned long _bss;
extern unsigned long _ebss;

extern void __libc_init_array(void);
extern int main(void);

/*
#ifdef __cplusplus
extern "C" {
#endif
*/

/* Reset Handler */
void Reset_Handler(void)
{
  unsigned long *src, *dest;

  // Copy the data segment initializers from flash to SRAM
  src = &_etext;
  for(dest = &_data; dest < &_edata; )
   {
     *dest++ = *src++;
   }
/*
  // Initialize the .bss segment of memory to zeros
  src = &_bss;
  while (src < &_ebss)
   {
     *src++ = 0;
   } */

   ///__libc_init_array();
    
   //Set the vector table location.
   //SCB_VTOR - Vector Table Offset Register
   SCB_VTOR = (uint32_t)&_interrupt_vector_table;
    
   main();

   // In case main() fails, have something to breakpoint
   while(1){;}
}

#pragma language=extended
/*
__interwork int __low_level_init(void)
{*/
  /*==================================*/
  /*  Initialize hardware.            */
  /*==================================*/
  /*
  unsigned long *src, *dest;

  //Copy the data segment initializers from flash to SRAM
  src = &_etext;
  for(dest = &_data; dest < &_edata;)
   {
     *dest++ = *src++;
   }

  //Initialize the .bss segment of memory to zeros
  src = &_bss;
  while (src < &_ebss)
   {
     *src++ = 0;
   }

  ///__libc_init_array();
   
  // Set the vector table location.
  //Vector Table Offset Register
  SCB_VTOR = (uint32_t)&_interrupt_vector_table;
    */
  /*==================================*/
  /* Choose if segment initialization */
  /* should be done or not.           */
  /* Return: 0 to omit seg_init       */
  /*         1 to run seg_init        */
  /*==================================*/
  //go to --> main(); 
/* 
  return 1;
}*/

#pragma language=default

#ifdef __cplusplus
}
#endif
