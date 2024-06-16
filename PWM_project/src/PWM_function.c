#include<header.h>

unsigned char pwm0(unsigned short up_pulses, unsigned short period) 
{
	static unsigned short count=0;
	if(count<up_pulses)
	{
		count++;
		return PULSE_ON;
	}
	else if(count<period-1)
	{
		count++;
		return PULSE_OFF;
	}
	else
	{
		if(up_pulses>=period)
		{
			count=0;     
			return PULSE_ON;   //when pulse_width==period
		}
		else
		{
			count=0;     
			return PULSE_OFF;   //when pulse_width<period
		}
	}
}
//------------------------------------------------------------------------------------------------------------
