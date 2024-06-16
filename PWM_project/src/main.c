#include<header.h>

int main(void)
{ 
	initialization(); 
	
	while(1)
	{		
		//--buttons--
		state_machine();
		switch_T_FU();
		
		//--USART--
		commandReceived();
		
		//--Display-- 
		LCD_String_start();    //update display every ~8ms       
		
		//--PWM-- 
		call_1ms();      //transmission/reception every 1ms     
		
	}
	return 0;
}