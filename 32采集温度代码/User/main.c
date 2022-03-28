#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "ds18b20.h"


int main()
{
	float temper;
	
	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	USART1_Init(9600);
	while(DS18B20_Init())
	{
		printf("DS18B20检测失败，请插好!\r\n");
		delay_ms(500);
	}
	printf("DS18B20检测成功!\r\n");
	
	while(1)
	{
		
		temper=DS18B20_GetTemperture();

		printf("Temp:%.1fC\r\n",temper);
	
		delay_ms(1500);
	}
}
