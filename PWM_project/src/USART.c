#include<header.h>

char temp[6];
unsigned char index_vect=0;
unsigned char command_received=0;    //set at the end of reception
unsigned char command_transmited=0;  //set at the end of transmission

#define USART_BAUDRATE 9600                                     //Define frequency transfer
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)  //10ms for 1 character

void usart_init(void)
{
	UCSRB |= (1<<RXCIE) | (1 << RXEN) | (1<<TXCIE) | (1 << TXEN);   // Turn on the transmission reception...circuitry and receiver interrupt
	UCSRC |= (1 << URSEL) | (1 << UCSZ1)| (1 << UCSZ0);             // Use 8-bit character sizes
	UBRRL = BAUD_PRESCALE;             // Load lower 8-bits of the baud rate value...into the low byte of the UBRR register
	UBRRH = (BAUD_PRESCALE >> 8);      // Load upper 8-bits of the baud rate value...into the high byte of the UBRR register
}

ISR (USART_TXC_vect)
{
	if(temp[index_vect]!='\0')          //send elements until string end '\0'
	{
		UDR=temp[index_vect];           //write UDR
		index_vect++;                   //next element for transmission
	} 
	else
	{
		if(command_transmited==0)
		{
			UDR=0x0D;               //send '/n' in order to insert new line in serial communication receive output 
			command_transmited=1;   //just once
		}
		else
		{
			index_vect=0;     //end transmission->reset index for future reception interrupt
		}
	}
}

ISR (USART_RXC_vect)
{
	unsigned char value;
	value=UDR;                       //read UDR
	if(value!=0x0D)                  //if character != CR who's send as last character from serial
	{
		temp[index_vect] = value;         //fetch the received character into vector
		index_vect++;                     //next element
	}
	else                             //when value is equal to CR => the receive is done
	{
		command_transmited=0;        //reset command_transmited
		temp[index_vect]='\0';            //insert end string '/0' in vector
		command_received=1;          //set variable for function execution in while(1)
		index_vect=0;					 //reset index vector
		UDR=temp[index_vect];             //send first element in order to start transmission chain
		index_vect++;                     //next index for transmission chain
	}
}
void commandReceived(void)
{
	if(command_received==1)
	{
		if((temp[0]=='o')&&(temp[1]=='n'))    //"on" ->enable pwm
		{
			enable_pwm=TRUE;
		}
		if((temp[0]=='o')&&(temp[1]=='f')&&(temp[2]=='f'))     //"off" ->disable pwm
		{
			enable_pwm=FALSE;
		}
		if(temp[0]=='T')                //"T_ _" ->change T  (ex: T70, T90)
		{
			period=atoi(&temp[1]);
			if(period<MIN_T)              //period<10ms => period=10ms
			{
				period=MIN_T;
			}
			if(period>MAX_T)
			{
				period=MAX_T;           //period>5s => period=5s
			}
		}
		if(temp[0]=='F')                //"F_ _" ->change FU  (ex: F20, F50)
		{
			up_pulses=atoi(&temp[1]);
			if(up_pulses<MIN_UP_PULSES)                //pulse<0ms => pulse=0ms
			{
				up_pulses=0;
			}
			if(up_pulses>period)           //pulse>period => pulse=period
			{
				up_pulses=period;
			}
		}
		command_received=0;
	}
}