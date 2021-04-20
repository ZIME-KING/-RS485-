#include "main.h"
#include "user_init.h"



uint16_t temp;
uint16_t AD_DMA[10];

//启动外设
void Start_Peripheral(){
	HAL_TIM_Base_Start_IT(&htim2);  //Start timer interrupt启动定时器中断（同时就启动定时器了不用单独启动定时器）
	HAL_UART_Receive_IT(&huart1,(uint8_t*)&buffer,1);  //Start uart interrupt启动串口中断
	HAL_UART_Transmit_Str(&huart1,(uint8_t*)"usart_ok");

	HAL_ADCEx_Calibration_Start(&hadc1);              	//AD校准

	led_function_2(3,30);  //呼吸灯
	User_U8g2_Init();
}

//定时器回调函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
		Uart_Time_Even();
		Key_Timer_Interrupt();
	}
}

//外部中断回调函数
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	if(GPIO_Pin == GPIO_PIN_9){
//		if(NRF24L01_RxPacket(rece_buf)==0)
////		{
//			HAL_GPIO_TogglePin(LED_0_GPIO_Port,  LED_0_Pin);
////			Rx_Buf();
////		}
//	}
//}




