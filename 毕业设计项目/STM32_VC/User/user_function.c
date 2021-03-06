#include "main.h"
#include "user_function.h"
#include "u8g2.h"

uint16_t Ture_ADC_0;
uint16_t Ture_ADC_1;
uint16_t Ture_ADC_2;
uint16_t Ture_ADC_3_ref;

//冒泡传入数组，数组元素数量
void bubbleSort(uint16_t arr[], int n)
{
  int i, j, tmp;

  for(i = 0; i < n - 1; i++)
  {
    for(j = 1; j < n; j++)
    {
      if(arr[j] < arr[j - 1])
      {
        tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
      }
    }
  }
}


#define MULTIPLE   1.0058
#define MULTIPLE_2 1.02
uint16_t temp_0[50];
uint16_t temp_1[50];
uint16_t temp_2[50];
uint16_t temp_3[50];
//获取实际输出通道值
void GET_CH_Vlaue(){
 	static int i;
 	int ii;
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)&AD_DMA[0], 3);
		temp_0[i]=(uint16_t)AD_DMA[0];
		temp_1[i]=(uint16_t)AD_DMA[1];
		temp_2[i]=(uint16_t)AD_DMA[2];

		i++;
		if(i>=50){
			i=0;
			 bubbleSort(temp_0,50);
			 bubbleSort(temp_1,50);
			 bubbleSort(temp_2,50);

			 Ture_ADC_0=(float)temp_0[25]*MULTIPLE;
			 Ture_ADC_1=(float)temp_1[25]*MULTIPLE;
			 Ture_ADC_2=(float)temp_2[25]*MULTIPLE_2;

			for(ii=0;ii<50;ii++){
				temp_0[ii]=0;
				temp_1[ii]=0;
				temp_2[ii]=0;
			}
		}
}




