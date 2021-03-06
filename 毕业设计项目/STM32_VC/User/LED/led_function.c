#include "main.h"
#include "led_function.h"

#define Delay_ms(x)  	HAL_Delay(x)
#define Set_LED_0()     HAL_GPIO_WritePin(LED_TEST_GPIO_Port, LED_TEST_Pin,GPIO_PIN_SET)
#define Clear_LED_0()	HAL_GPIO_WritePin(LED_TEST_GPIO_Port, LED_TEST_Pin,GPIO_PIN_RESET)
//#define Set_LED_1()   	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin,GPIO_PIN_SET)
//#define Clear_LED_1()	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin,GPIO_PIN_RESET)
//#define Set_LED_2()    	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin,GPIO_PIN_SET)
//#define Clear_LED_2()	HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin,GPIO_PIN_RESET)

#define CONSTANT 1000 //一个周期时间设定 ms

static void Delay_1us(uint16_t i){
	uint16_t temp;
	while(i--){
		for(temp=0;temp<60;temp++);
	};
}


//prm周期1ms
//运行单个pwm周期
//x：高电平比例0到1000
//
static void led_function_1(float x){
	Clear_LED_0();  //亮
	//Clear_LED_1();  //亮
	//Clear_LED_1();  //亮
	Delay_1us(x);
	Set_LED_0();//灭
	//Set_LED_1();//灭
	//Set_LED_2();//灭
	Delay_1us(CONSTANT-x);
}
//设定呼吸的时间,单位ms
//fre呼吸次数
void led_function_2(uint8_t fre,uint16_t tim_ms){
	float interval;
	float pwm=0;
	uint16_t i;
	interval=(float)CONSTANT/(float)tim_ms;//每一个pwm周期变化量
	while(fre--){
		for(i=0;i<tim_ms;i++){
			pwm+=interval;
			led_function_1(pwm);
		}
		for(i=tim_ms;i>0;i--){
			pwm-=interval;
			led_function_1(pwm);
		}
	}
}
