#include<header.h>

unsigned char LCD_Char_space_fromT(void)
{
	static unsigned short flag1=0,flag2=0,count1=0;
	if(flag1==0)
	{
		LCD_Data_Port=' ';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=1;
		return 0;
	}
	else
	{
		if(flag2==0)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=1;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_T()==1)
			{
				count1=0;
				flag1=0;
				flag2=0;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
unsigned char LCD_Char_T(void)
{
	static unsigned short flag1=0,flag2=0,count1=0;
	if(flag1==0)
	{
		LCD_Data_Port='T';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=1;
		return 0;
	}
	else
	{
		if(flag2==0)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=1;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_ddot()==1)
			{
				count1=0;
				flag1=0;
				flag2=0;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
unsigned char LCD_Char_ddot(void)
{
	static unsigned short flag1=0,flag2=0,count1=0;
	if(flag1==0)
	{
		LCD_Data_Port=':';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=1;
		return 0;
	}
	else
	{
		if(flag2==0)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=1;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(str_measured_value[0]!='\0')
			{
				if(LCD_Char_str0()==1)
				{
					count1=0;
					flag1=0;
					flag2=0;
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				if(LCD_Char_space1()==1)
				{
					count1=0;
					flag1=0;
					flag2=0;
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
unsigned char LCD_Char_m(void)
{
	static unsigned short flag1=0,flag2=0,count1=0;
	if(flag1==0)
	{
		LCD_Data_Port='m';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=1;
		return 0;
	}
	else
	{
		if(flag2==0)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=1;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_s()==1)
			{
				count1=0;
				flag1=0;
				flag2=0;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
unsigned char LCD_Char_s(void)
{
	static unsigned short flag1=0,flag2=0,count1=0;
	if(flag1==0)
	{
		LCD_Data_Port='s';
		LCD_Command_Port |= (1<<RS);	/* RS=1 Data reg. */
		LCD_Command_Port &= ~(1<<RW);	/* RW=0 Write operation */
		LCD_Command_Port |= (1<<EN);	/* Enable pulse */
		flag1=1;
		return 0;
	}
	else
	{
		if(flag2==0)
		{
			if(count1<1)
			{
				count1++;
				return 0;
			}
			else
			{
				LCD_Command_Port &= ~(1<<EN);
				flag2=1;
				count1=0;
				return 0;
			}
		}
		else
		{
			if(LCD_Char_space4()==1)
			{
				count1=0;
				flag1=0;
				flag2=0;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}