
#ifndef __USER_INIT_H
#define __USER_INIT_H

void Start_Peripheral();


extern uint16_t AD_DMA[10];
extern uint8_t  rece_buf[32];

void Receive_Data();
void Send_Data();

#endif
