#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "ds18b20.h"


int main()
{
	float temper;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //�ж����ȼ����� ��2��
	LED_Init();
	USART1_Init(9600);
	while(DS18B20_Init())
	{
		printf("DS18B20���ʧ�ܣ�����!\r\n");
		delay_ms(500);
	}
	printf("DS18B20���ɹ�!\r\n");
	
	while(1)
	{
		
		temper=DS18B20_GetTemperture();

		printf("Temp:%.1fC\r\n",temper);
	
		delay_ms(1500);
	}
}
