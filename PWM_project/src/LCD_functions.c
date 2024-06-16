/*#include<header.h>


void LCD_Char (unsigned char char_data)	// LCD data write function 
{
	LCD_Data_Port= char_data;
	LCD_Command_Port |= (1<<RS);	// RS=1 Data reg. 
	LCD_Command_Port &= ~(1<<RW);	// RW=0 write operation 
	LCD_Command_Port |= (1<<EN);	// Enable Pulse 
	_delay_us(1);
	LCD_Command_Port &= ~(1<<EN);
	_delay_us(3000);
	//static unsigned short count=0;
	//if(count<3000)
	//count++;
	
}


void LCD_String (char *str)		/ Send string to LCD function *
{
	int i;
	for(i=0;str[i]!=0;i++)		/ Send each char of string till the NULL *
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)/ Send string to LCD with xy position *
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/ Command of first row and required position<16 *
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/ Command of first row and required position<16 *
	LCD_String(str);		/ Call LCD string function *
}

void LCD_Clear(void)
{
	LCD_Command (0x01);		// clear display *
	LCD_Command (0x80);		// cursor at home position *
}
*/