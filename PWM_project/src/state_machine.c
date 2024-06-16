#include<header.h>

void state_machine(void)
{
	switch(SELECT_BUTTONS)
	{
		case BUT0:      //only the first button
		{
			channel_position=POSITION_CHANNEL_1;
			str_measured_value[0]='\0';    //display nothing until new measurement
			display_T=TRUE;                //display T when changing the channel 
			break;
		}
		case BUT1:     //only the second button
		{
			channel_position=POSITION_CHANNEL_2;
			str_measured_value[0]='\0';    //display nothing until new measurement
			display_T=TRUE;                //display T when changing the channel
			break;
		}
		case BUT2:      //only the third button
		{
			channel_position=POSITION_CHANNEL_3;
			str_measured_value[0]='\0';    //display nothing until new measurement
			display_T=TRUE;                //display T when changing the channel
			break;
		}
		case BUT3:       //only the fourth button
		{
			channel_position=POSITION_CHANNEL_4;
			str_measured_value[0]='\0';    //display nothing until new measurement
			display_T=TRUE;                //display T when changing the channel
			break;
		}
		default:break;
	}
}
void switch_T_FU(void)
{
	static unsigned char flag_first_imp=FALSE;
	static unsigned char count_debounce=0;
	if(BUT5==BUTTON_PRESED)
	{
		count_debounce++;
		if(count_debounce==5)
		{
			if(flag_first_imp==FALSE)
			{
				display_T^=1;             //alternate between TRUE and FALSE
				str_measured_value[0]='\0';
				flag_first_imp=TRUE;
			}
			count_debounce=0;
		}
	}
	if(BUT5==BUTTON_UNPRESED)
	{
		flag_first_imp=FALSE;
		count_debounce=0;
	}
}