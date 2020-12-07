//==============================================================================
//File name:    "device_msg.h"
//Processor:    ARM LPC17xx
//Toolkit:      EWARM (IAR Systems)
//Purpose:      Header File
//Version:      1.00
//Copyright:    (c) 2016, Akimov Vladimir  E-mail: decoder@rambler.ru		
//==============================================================================
#ifndef  _BT_TX_H_
#define  _BT_TX_H_

#ifdef  __cplusplus
extern "C" 
{
#endif //end __cplusplus

//func
void BT_DM3_tx(char channel, int length, char *data);
unsigned long long btbb_gen_syncword(const int LAP);

#ifdef __cplusplus
}
#endif //end __cplusplus

#endif //end file