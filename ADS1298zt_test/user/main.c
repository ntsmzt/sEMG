#include "ads1298.h"
#include "usart.h"
#include "stm32f10x.h"
#include "schedule.h"
int r;

int main(void)
{
	u8 i,j;

  SystemInit();
  usart1_Init(115200); 

  ads1298_init();                                  //ads1298初始化
	resetADS1298();
	
	//configForNoiseTest(); 
	configForNormalMeasurement();
	//configForSquarewaveTest();
	//Read_CH();
	//delayMs(40000);
	
	beginReadDataC();                							//开始连续测量模式	 
  while (1)                                     //执行程序
  {
	}
}    