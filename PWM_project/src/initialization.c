#include<header.h>

void initialization(void)
{
	var_1ms=0;
	var_24us=0;
	channel_position=0;
	display_T=1;
	enable_pwm=1;
	up_pulses=10;
	period=200;

	DDRD=0xC0;
	PORTD=0x3F;
	DDRA=0x00;
	PORTA=0xFF;

	usart_init();
	LCD_Init();
	config_timer0();
	config_timer1();
}