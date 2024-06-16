#include<header.h>

void LCD_Command(unsigned char cmnd)
{
	LCD_Data_Port= cmnd;
	LCD_Command_Port &= ~(1<<RS);	// RS=0 command reg.
	LCD_Command_Port &= ~(1<<RW);	// RW=0 Write operation
	LCD_Command_Port |= (1<<EN);	// Enable pulse
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_ms(3);
}
void LCD_Init (void)			// LCD Initialize function
{
	LCD_Command_Dir = 0xFF;		// Make LCD command port direction as o/p
	LCD_Data_Dir = 0xFF;		// Make LCD data port direction as o/p
	_delay_ms(20);			// LCD Power ON delay always >15ms
	
	LCD_Command (0x38);		// Initialization of 16X2 LCD in 8bit mode
	LCD_Command (0x0C);		// Display ON Cursor OFF
	LCD_Command (0x06);		// Auto Increment cursor
	LCD_Command (0x01);		// Clear display
	LCD_Command (0x80);		// Cursor at home position *
}
void LCD_String_start(void)
{
	static unsigned short flag1=FALSE,flag2=FALSE,count1=0;
	if(var_24us==TRUE)
	{
		if(flag1==FALSE)
		{
			LCD_Data_Port= 0x80;
			LCD_Command_Port &= ~(1<<RS);	// RS=0 command reg.
			LCD_Command_Port &= ~(1<<RW);	// RW=0 Write operation
			LCD_Command_Port |= (1<<EN);	// Enable pulse
			flag1=TRUE;
		}
		else
		{
			if(flag2==FALSE)
			{
				if(count1<1)
				{
					count1++;
				}
				else
				{
					LCD_Command_Port &= ~(1<<EN);
					flag2=TRUE;
					count1=0;
				}
			}
			else
			{
				if(count1<300)  //300*8us= 2.4ms necessary wait for 0x80 command
				{
					count1++;
				}
				else
				{
					if(LCD_Char_C()==1)
					{
						count1=0;
						flag1=FALSE;
						flag2=FALSE;
					}
				}
			}
		}
		var_24us=FALSE;
	}
}
//---------------------------------------------------------------------------
unsigned char LCD_Char_C(void)
{
	static unsigned short flag1=FALSE,flag2=FALSE,count1=0;
	if(flag1==FALSE)
	{
		LCD_Data_Port= 'C';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=TRUE;
		return 0;
	}
	else
	{
		if(flag2==FALSE)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=TRUE;
				count1=0;
				return 0;
			}
		}
		else
		{
			switch(channel_position)
			{
				case 0:
				{
					//-------------------------------------------------------------------------
					if(LCD_Char_ch_1()==1)
					{
						count1=0;
						flag1=FALSE;
						flag2=FALSE;
						return 1;
					}
					else
					{
						return 0;
					}
				}
				case 1:
				{
					//---------------------------------------------------------------------------
					if(LCD_Char_ch_2()==1)
					{
						count1=0;
						flag1=FALSE;
						flag2=FALSE;
						return 1;
					}
					else
					{
						return 0;
					}
				}
				case 2:
				{
					//---------------------------------------------------------------------------
					if(LCD_Char_ch_3()==1)
					{
						count1=0;
						flag1=FALSE;
						flag2=FALSE;
						return 1;
					}
					else
					{
						return 0;
					}
				}
				case 3:
				{
					//---------------------------------------------------------------------------
					if(LCD_Char_ch_4()==1)
					{
						count1=0;
						flag1=FALSE;
						flag2=FALSE;
						return 1;
					}
					else
					{
						return 0;
					}
				}
				default:return 0;
			}
		}
	}
}
unsigned char LCD_Char_ch_1(void)
{
	static unsigned short flag1=FALSE,flag2=FALSE,count1=0;
	if(flag1==FALSE)
	{
		LCD_Data_Port= '1';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=TRUE;
		return 0;
	}
	else
	{
		if(flag2==FALSE)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=TRUE;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_space()==1)
			{
				count1=0;
				flag1=FALSE;
				flag2=FALSE;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
unsigned char LCD_Char_ch_2(void)
{
	static unsigned short flag1=FALSE,flag2=FALSE,count1=0;
	if(flag1==FALSE)
	{
		LCD_Data_Port= '2';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=TRUE;
		return 0;
	}
	else
	{
		if(flag2==FALSE)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=TRUE;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_space()==1)
			{
				count1=0;
				flag1=FALSE;
				flag2=FALSE;
				return 1;
			}
			else
			{
				return 0;
				}
		}
	}
}
unsigned char LCD_Char_ch_3(void)
{
	static unsigned short flag1=FALSE,flag2=FALSE,count1=0;
	if(flag1==FALSE)
	{
		LCD_Data_Port= '3';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=TRUE;
		return 0;
	}
	else
	{
		if(flag2==FALSE)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=TRUE;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_space()==1)
			{
				count1=0;
				flag1=false;
				flag2=FALSE;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
unsigned char LCD_Char_ch_4(void)
{
	static unsigned short flag1=FALSE,flag2=FALSE,count1=0;
	if(flag1==FALSE)
	{
		LCD_Data_Port='4';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=TRUE;
		return 0;
	}
	else
	{
		if(flag2==FALSE)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=TRUE;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_space()==1)
			{
				count1=0;
				flag1=FALSE;
				flag2=FALSE;
				return 1;
			}
			else
			{
			return 0;
			}
		}
	}
}
unsigned char LCD_Char_space(void)
{
	static unsigned short flag1=FALSE,flag2=FALSE,count1=0;
	if(flag1==FALSE)
	{
		LCD_Data_Port=' ';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=TRUE;
		return 0;
	}
	else
	{
		if(flag2==FALSE)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=TRUE;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(signal_on==TRUE)
			{
				if(LCD_Char_O1()==1)
				{
					count1=0;
					flag1=FALSE;
					flag2=FALSE;
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(signal_off==TRUE)
			{
				if(LCD_Char_O2()==1)
				{
					count1=0;
					flag1=FALSE;
					flag2=FALSE;
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(display_T==TRUE)
			{
				if(LCD_Char_space_fromT()==1)
				{
					count1=0;
					flag1=FALSE;
					flag2=FALSE;
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				if(LCD_Char_F()==TRUE)
				{
					count1=0;
					flag1=FALSE;
					flag2=FALSE;
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
}
