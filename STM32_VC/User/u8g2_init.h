#ifndef __U8G2_INIT_H
#define __U8G2_INIT_H
#include "u8g2.h"

extern u8g2_t u8g2;

void User_U8g2_Init();
void User_Display_Function_SLAVE();
void User_Display_Function_MASTER(unsigned char mode);


extern float adc[3];
extern float current;


#endif
