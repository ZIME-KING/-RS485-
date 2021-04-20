#ifndef __USER_FUNCTION_H
#define __USER_FUNCTION_H

void Read_User_Configure();	//从flash读取用户配置（遥感校准值）
void GET_CH_Vlaue();        //获取各通道adc值
void Read_Rtc();
void Save_Date();
void To_Update_Rtc();

extern uint8_t  OUT_CH[9];  //实际输出通道值
extern uint16_t  battery_voltage;
extern uint16_t MAX_CH[4];
extern uint16_t MIN_CH[4];
extern uint16_t MID_CH[4];


extern uint16_t Ture_ADC_0;
extern uint16_t Ture_ADC_1;
extern uint16_t Ture_ADC_2;
#endif
