//显示部分的程序使用u8g2库
//https://github.com/olikraus/u8g2/wiki
//使用硬件i2c时不可与硬件spi同时使用，会有问题。
//可配置硬件i2c与软件i2c之间选择
//包含显示的函数

#include "main.h"
#include "u8g2_init.h"
#include "u8g2.h"
#include "u8g2_buffer.h"



//#define READ_MENU_SELECT HAL_GPIO_ReadPin(KEY_3_GPIO_Port, KEY_3_Pin)
//#define READ_MENU_NEXT	 HAL_GPIO_ReadPin(KEY_1_GPIO_Port, KEY_1_Pin)
//#define READ_MENU_PREV	 HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin)
//#define READ_MENU_HOME 	 HAL_GPIO_ReadPin(KEY_0_GPIO_Port, KEY_0_Pin)

#define READ_MENU_SELECT  0
#define READ_MENU_NEXT	  0
#define READ_MENU_PREV	  0
#define READ_MENU_HOME 	  0



//#define software_mode
#define hardware_mode

#ifdef software_mode
//SDA配置成输出开漏模式 可读可写
#define SET_I2C_SDA 	 HAL_GPIO_WritePin(SW_I2C_SDA_GPIO_Port,SW_I2C_SDA_Pin,GPIO_PIN_SET);
#define CLEAR_I2C_SDA 	 HAL_GPIO_WritePin(SW_I2C_SDA_GPIO_Port,SW_I2C_SDA_Pin,GPIO_PIN_RESET);
#define SET_I2C_SCL 	 HAL_GPIO_WritePin(SW_I2C_SCL_GPIO_Port,SW_I2C_SCL_Pin,GPIO_PIN_SET);
#define CLEAR_I2C_SCL 	 HAL_GPIO_WritePin(SW_I2C_SCL_GPIO_Port,SW_I2C_SCL_Pin,GPIO_PIN_RESET);
#endif

#ifdef hardware_mode

uint8_t User_u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
	static uint8_t buffer[32];		/* u8g2/u8x8 will never send more than 32 bytes between START_TRANSFER and END_TRANSFER */
	  static uint8_t buf_idx;
	  uint8_t *data;

	  switch(msg)
	  {
	    case U8X8_MSG_BYTE_SEND:
	      data = (uint8_t *)arg_ptr;
	      while( arg_int > 0 )
	      {
		buffer[buf_idx++] = *data;
		data++;
		arg_int--;
	      }
	      break;
	    case U8X8_MSG_BYTE_INIT:
	      /* add your custom code to init i2c subsystem */
	      break;
	    case U8X8_MSG_BYTE_SET_DC:
	      /* ignored for i2c */
	      break;
	    case U8X8_MSG_BYTE_START_TRANSFER:
	      buf_idx = 0;
	      break;
	    case U8X8_MSG_BYTE_END_TRANSFER:
	    	HAL_I2C_Master_Transmit(&hi2c1,u8x8_GetI2CAddress(u8x8),&buffer[0], buf_idx, 10);
	      break;
	    default:
	      return 0;
	  }
	  return 1;
}
#endif



u8g2_t u8g2;
uint8_t u8x8_gpio_and_delay_template(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
	switch(msg)
	{
	case U8X8_MSG_GPIO_AND_DELAY_INIT:	// called once during init phase of u8g2/u8x8
		break;							// can be used to setup pins
	case U8X8_MSG_DELAY_NANO:			// delay arg_int * 1 nano second
		break;
	case U8X8_MSG_DELAY_100NANO:		// delay arg_int * 100 nano seconds
		break;
	case U8X8_MSG_DELAY_10MICRO:		// delay arg_int * 10 micro seconds
		break;
	case U8X8_MSG_DELAY_MILLI:			// delay arg_int * 1 milli second
		break;
	case U8X8_MSG_DELAY_I2C:			// arg_int is the I2C speed in 100KHz, e.g. 4 = 400 KHz
		break;							// arg_int=1: delay by 5us, arg_int = 4: delay by 1.25us

#ifdef software_mode
	case U8X8_MSG_GPIO_I2C_CLOCK:		// arg_int=0: Output low at I2C clock pin
		if(arg_int){
			SET_I2C_SCL;
			//HAL_GPIO_WritePin(SW_I2C_SCL_GPIO_Port,SW_I2C_SCL_Pin,GPIO_PIN_SET);
		}
		else{
			CLEAR_I2C_SCL
			//HAL_GPIO_WritePin(SW_I2C_SCL_GPIO_Port,SW_I2C_SCL_Pin,GPIO_PIN_RESET);
		}
		break;							// arg_int=1: Input dir with pullup high for I2C clock pin
	case U8X8_MSG_GPIO_I2C_DATA:		// arg_int=0: Output low at I2C data pin
		if(arg_int){
			SET_I2C_SDA;
			//HAL_GPIO_WritePin(SW_I2C_SDA_GPIO_Port,SW_I2C_SDA_Pin,GPIO_PIN_SET);
		}
		else{
			CLEAR_I2C_SDA;
			//HAL_GPIO_WritePin(SW_I2C_SDA_GPIO_Port,SW_I2C_SDA_Pin,GPIO_PIN_RESET);
		}
		break;							// arg_int=1: Input dir with pullup high for I2C data pin
#endif
	case U8X8_MSG_GPIO_MENU_SELECT:
		if(READ_MENU_SELECT!=1)
			u8x8_SetGPIOResult(u8x8, /* get menu select pin state */ 0);
		break;
	case U8X8_MSG_GPIO_MENU_NEXT:
		if(READ_MENU_NEXT!=1)
			u8x8_SetGPIOResult(u8x8, /* get menu next pin state */ 0);
		break;
	case U8X8_MSG_GPIO_MENU_PREV:
		if(READ_MENU_PREV!=1)
			u8x8_SetGPIOResult(u8x8, /* get menu prev pin state */ 0);
		break;
	case U8X8_MSG_GPIO_MENU_HOME:
		if(READ_MENU_HOME!=1)
			u8x8_SetGPIOResult(u8x8, /* get menu home pin state */ 0);
		break;
	default:
		u8x8_SetGPIOResult(u8x8, 1);			// default return value
		break;
	}
	return 1;
}

void User_U8g2_Init(){
#ifdef software_mode
	u8g2_Setup_ssd1306_i2c_128x64_noname_f(&u8g2, U8G2_R0, u8x8_byte_sw_i2c, u8x8_gpio_and_delay_template);
#endif
#ifdef hardware_mode
	u8g2_Setup_ssd1306_i2c_128x64_vcomh0_f(&u8g2, U8G2_R0, User_u8x8_byte_hw_i2c, u8x8_gpio_and_delay_template);
#endif
	u8g2_InitDisplay(&u8g2); 		// send init sequence to the display, display is in sleep mode after this,
	u8g2_SetPowerSave(&u8g2, 0); 	// wake up display
	u8g2_ClearBuffer(&u8g2);
	u8g2_SendBuffer(&u8g2);
	u8g2_DrawLine(&u8g2, 0,0, 128, 64);
	u8g2_DrawLine(&u8g2, 128,0, 0, 64);
	u8g2_SetFont(&u8g2,u8g2_font_6x13B_t_hebrew);
	u8g2_SendBuffer(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);
	HAL_Delay(500);
	//HAL_I2C_Master_Transmit(&hi2c1,u8x8_GetI2CAddress(u8x8)>> 1,&buffer[0], buf_idx, 1);
}


/*显示界面
 */
float adc[3];
float current;

void User_Display_Function_1(){
	int8_t temp_buf[20];
//	float temp;

	u8g2_ClearBuffer(&u8g2);


	adc[0]=(float)Ture_ADC_0/4095*3.3;

	adc[1]=(float)Ture_ADC_1/4095*3.3;

	adc[2]=(float)Ture_ADC_2/4095*3.3*4;

	sprintf((char*)temp_buf,"ADC_0:%.3fV",adc[0]); // @suppress("Float formatting support")
	u8g2_DrawStr(&u8g2,0,16,(char*)temp_buf);    //

	sprintf((char*)temp_buf,"ADC_1:%.3fV",adc[1]);
	u8g2_DrawStr(&u8g2,0,32,(char*)temp_buf);    //

	sprintf((char*)temp_buf,"ADC_2:%.3fV",adc[2]);
	u8g2_DrawStr(&u8g2,0,48,(char*)temp_buf);    //

	current=(float)(Ture_ADC_1-Ture_ADC_0)/4095*3.3*1000/50*100;

	if(current<10 && current >-10){
		current=0;
	}
	sprintf((char*)temp_buf,"current:%.3f   mA",current);
	u8g2_DrawStr(&u8g2,0,64,(char*)temp_buf);    //


	u8g2_SendBuffer(&u8g2);
}

//高度48  5V最大值*9
uint8_t Map_V(unsigned int _value)
{
	_value=_value/4095*3*4*9;
    return (63-((unsigned char)_value));
}

uint8_t Map_C(uint8_t _value)
{
    return 63 - ((_value * 3) >> 4);
}

static uint8_t waveform[128];
void Vave_V()
{
	unsigned char temp_buf[15];
    static uint8_t phase = 0;
    //static uint8_t waveform[128];

	sprintf((char*)temp_buf,"ADC_2:%.3fV",adc[2]);
	u8g2_DrawStr(&u8g2,64,0,(char*)temp_buf);    //

    //128点电压值
    waveform[phase++] =Map_V(Ture_ADC_2);
    if (phase == 128)
    {
        phase = 0;
        u8g2_SetDrawColor(&u8g2, 0);
        u8g2_DrawBox(&u8g2, 0, 16, 128, 48);
        u8g2_SetDrawColor(&u8g2, 1);
        for (uint8_t i = 1; i != 128; ++i)
            u8g2_DrawLine(&u8g2, i - 1, (waveform[i - 1]),
                                 i    , (waveform[i    ]));
        u8g2_SendBuffer(&u8g2);
        u8g2_UpdateDisplayArea(&u8g2, 0, 2, 16, 6);
    }
}

//void Vave_C()
//{
//    static uint8_t phase = 0;
//    static uint8_t waveform[128];
//    //128点电流值
//    waveform[phase++] = Ture_ADC_1-Ture_ADC_0;
//    if (phase == 128)
//    {
//        phase = 0;
//        u8g2_SetDrawColor(&u8g2, 0);
//        u8g2_DrawBox(&u8g2, 0, 16, 128, 48);
//        u8g2_SetDrawColor(&u8g2, 1);
//        for (uint8_t i = 1; i != 128; ++i)
//            u8g2_DrawLine(&u8g2, i - 1, map(waveform[i - 1]),
//                                 i    , map(waveform[i    ]));
//        u8g2_UpdateDisplayArea(&u8g2, 0, 2, 16, 6);
//    }
//}
//
//int main()
//{
//    u8g2_Setup_ssd1306_128x64_noname_f(&u8g2, U8G2_R0, u8x8_comm_callback, u8x8_gpio_delay_callback);
//    u8g2_InitDisplay(&u8g2);
//    u8g2_SetPowerSave(&u8g2, 0);
//    u8g2_SendBuffer(&u8g2);
//    adc_init();
//    timer_init();
//    timer_register(timer);
//    while (1)
//        ;
//}
//





//void User_Display_Function_2(){
//	//page2：遥控信息首页显示遥感位置
//	int8_t temp_y,temp_x;
//	u8g2_ClearBuffer(&u8g2);
//	u8g2_DrawStr(&u8g2,0,13,(char*)"PAGE:2/10");  //页面
//	if(1)
//		u8g2_DrawBitmap(&u8g2, 112, 0, 2,16, &gImage_2[0]); //有信号
//	else
//		u8g2_DrawBitmap(&u8g2, 112, 0, 2,16, &gImage_3[0]); //无信号
//
//	u8g2_DrawFrame(&u8g2,14, 59, 36, 5);
//	u8g2_DrawFrame(&u8g2,78, 59, 36, 5);
//	u8g2_DrawFrame(&u8g2,5, 18, 5, 36);
//	u8g2_DrawFrame(&u8g2,69, 18, 5, 36);
//	u8g2_DrawLine(&u8g2,0,16, 128, 16);
//	//圆 x,y,r 大圆
//	u8g2_DrawCircle(&u8g2, 32, 36, 18,U8G2_DRAW_ALL);
//	u8g2_DrawCircle(&u8g2, 96, 36, 18,U8G2_DRAW_ALL);
//	temp_x=36*OUT_CH[0]/255  -18;
//	temp_y=36*OUT_CH[1]/255  -18   ;
//	u8g2_DrawCircle(&u8g2, 96+temp_x, 36+temp_y, 1,U8G2_DRAW_ALL);
//	temp_x=36*OUT_CH[2]/255  -18;
//	temp_y=36*OUT_CH[3]/255  -18  ;
//	u8g2_DrawCircle(&u8g2, 32+temp_x, 36+temp_y, 1,U8G2_DRAW_ALL);   //
//	u8g2_SendBuffer(&u8g2);
//}
//
//void User_Display_ADC_Value(){
//	uint8_t temp_srt[20];
//
//	u8g2_ClearBuffer(&u8g2);
//	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&AD_DMA, 10); //;
//	sprintf((char*)temp_srt,"ch0:%d",AD_DMA[0]);
//	u8g2_DrawStr(&u8g2,0,12,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch1:%d",AD_DMA[1]);
//	u8g2_DrawStr(&u8g2,0,24,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch2:%d",AD_DMA[2]);
//	u8g2_DrawStr(&u8g2,0,36,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch3:%d",AD_DMA[3]);
//	u8g2_DrawStr(&u8g2,0,48,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch4:%d",AD_DMA[4]);
//	u8g2_DrawStr(&u8g2,0,60,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch5:%d",AD_DMA[5]);
//	u8g2_DrawStr(&u8g2,64,12,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch6:%d",AD_DMA[6]);
//	u8g2_DrawStr(&u8g2,64,24,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch7:%d",AD_DMA[7]);
//	u8g2_DrawStr(&u8g2,64,36,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch8:%d",AD_DMA[8]);
//	u8g2_DrawStr(&u8g2,64,48,(char*)temp_srt);
//	sprintf((char*)temp_srt,"ch9:%d",AD_DMA[9]);
//	u8g2_DrawStr(&u8g2,64,60,(char*)temp_srt);
//	u8g2_SendBuffer(&u8g2);
//}
//
//void User_Display_Function_3(){
//	//！显示时钟
//	uint8_t temp_str[50];
//
//	//uint32_t user_temp;
//
//	u8g2_ClearBuffer(&u8g2);
//	RTC_DateTypeDef sdatestructureget;
//	RTC_TimeTypeDef stimestructureget;
//	/* Get the RTC current Time */
//	HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
//	/* Get the RTC current Date */
//	HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);
//	/* Display time Format : hh:mm:ss */
//
//	To_Update_Rtc();
//	sprintf((char *)temp_str, "%2d:%2d:%2d", stimestructureget.Hours, stimestructureget.Minutes, stimestructureget.Seconds);
//	String_Handle((char*)temp_str);
//	/* Display date Format : mm-dd-yy */
//	u8g2_DrawStr(&u8g2,0,24,(char*)temp_str);
//	//HAL_UART_Transmit_Str(&huart1,(uint8_t*)send_buf);
//	sprintf((char *)temp_str, "%d_%2d_%2d_%2d",2000+sdatestructureget.Year,sdatestructureget.Month,sdatestructureget.Date,sdatestructureget.WeekDay);
//	String_Handle((char *)temp_str);
//	u8g2_DrawStr(&u8g2,0,48,(char*)temp_str);
//
//
////	user_temp=RTC_ReadTimeCounter(&hrtc);
////	sprintf((char *)temp_str, "%1.f",(float)user_temp);
////	u8g2_DrawStr(&u8g2,0,64,(char*)temp_str);
//
//	u8g2_SendBuffer(&u8g2);
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
