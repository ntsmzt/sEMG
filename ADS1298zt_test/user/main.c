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

  ads1298_init();                                  //ads1298��ʼ��
	resetADS1298();
	
	//configForNoiseTest(); 
	configForNormalMeasurement();
	//configForSquarewaveTest();
	//Read_CH();
	//delayMs(40000);
	
	beginReadDataC();                							//��ʼ��������ģʽ	 
  while (1)                                     //ִ�г���
  {
	}
}    