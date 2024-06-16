#include<header.h>

void config_timer0(void)
{
	TCCR0 |= (0<<CS02) | (1<<CS01) | (1<<CS00); // prescaler 1/64 -> fclk=16MHz->  f=16MHz/64 -> f=250kHz-> t=1/f -> t=1/250k -> t=4us
	TIMSK |= (1<<OCIE0);                        //set interrupt compare
	OCR0=249;                                   //t=4us   t*x=tTimer = 4us*x=1ms -> x 1ms/4us = 250
	TCCR0 |= 1<<WGM01;                          //CTC
	sei();                                      // enable all interrupts
}
ISR(TIMER0_COMP_vect)
{
	var_1ms = 1;
}

void config_timer1(void)
{
	TCCR1B|=(0<<CS12)|(1<<CS11)|(1<<CS10); // prescaler 1/64 -> fclk=16MHz->  f=16MHz/64 -> f=250kHz-> t=1/f -> t=1/250k -> t=4us
	TIMSK|=(1<<OCIE1A);                    //set interrupt compare
	OCR1A=5;                               //t=4us   t*x=tTimer = 4us*x=24us -> x 8us/4us = 6
	TCCR1B|=1<<WGM12;                      //CTC
	sei();                                 // enable all interrupts
}
ISR(TIMER1_COMPA_vect)
{
	var_24us=1;
}