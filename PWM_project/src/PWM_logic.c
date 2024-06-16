#include<header.h>
#include<string.h>

void call_1ms(void)
{
	static unsigned short counter_up=0,counter_down=0,measured_pwm=0;
	static unsigned char flag_up=0,flag_down=0;
	
	if(var_1ms==TRUE)
	{
		//TRANSMISSION PWM-----------------------------------------------------------------------------------
		
		if(enable_pwm==TRUE)              //changeable using USART
		{
			if(pwm0(up_pulses,period)==PULSE_ON)
			{
				PORTD&=~(1<<PIND7);      //write 0
			}
			else
			{
				PORTD|=1<<PIND7;         //write 1
			}
		}
		else
		{
			PORTD|=1<<PIND7;        //enable_pwm==FALSE =>write 1
		}
		//RECEPTION PWM--------------------------------------------------------------------------------------

		measured_pwm=(PINA>>channel_position)&1;  //save current value of pwm
		
		if(measured_pwm==PULSE_ON)
		{
			counter_up++;
			flag_up=TRUE;
			if(counter_up==5000)
			{
				signal_on=TRUE;   //display "On" 
				counter_up=0;
			}
		}
		else
		{
			if(flag_up==TRUE)    //flag_up is TRUE just once after measured_pwm==PULSE_ON at least once 
			{
				signal_on=FALSE;
				T_val=counter_up;      //T_val becomes number of up pulses
				counter_up=0;
				flag_up=FALSE;
			}
		}
		if(measured_pwm==PULSE_OFF)
		{
			counter_down++;
			flag_down=TRUE;
			if(counter_down==5000)
			{
				signal_off=TRUE;
				counter_down=0;
			}

		}
		else
		{
			if(flag_down==TRUE)    //flag_down is TRUE just once after measured_pwm==PULSE_OFF at least once
			{
				
				signal_off=FALSE;
				if(display_T==TRUE)        //display T
				{
					T_val+=counter_down;     // <=> T_val = counter_down + counter_up
					itoa(T_val,str_measured_value,10);      //update vector in order to display it
				}
				else
				{
					FU_val=((unsigned long)T_val*100)/(T_val+counter_down);     // <=> FU_val = counter_down*100 / T
					itoa(FU_val,str_measured_value,10);                //update vector in order to display it
				}
				counter_down=0;
				flag_down=FALSE;
			}
		}
		var_1ms=FALSE;
	}
}