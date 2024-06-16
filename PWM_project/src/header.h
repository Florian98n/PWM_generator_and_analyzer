#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000ull

#define LCD_Data_Dir DDRB		    // Define LCD data port direction 
#define LCD_Command_Dir DDRC		// Define LCD command port direction register 
#define LCD_Data_Port PORTB		    // Define LCD data port 
#define LCD_Command_Port PORTC		// Define LCD data port 
#define RS PC0				        // Define Register Select (data/command reg.)pin 
#define RW PC1						// Define Read/Write signal pin 
#define EN PC2						// Define Enable signal pin 

#define TRUE 1
#define FALSE 0

#define SELECT_BUTTONS ((PIND>>2) & 0x0F)
#define BUT0 0x0E
#define BUT1 0x0D
#define BUT2 0X0B
#define BUT3 0X07

#define POSITION_CHANNEL_1 0
#define POSITION_CHANNEL_2 1
#define POSITION_CHANNEL_3 2
#define POSITION_CHANNEL_4 3
#define BUT5 (PINA>>7)
#define BUTTON_PRESED 0
#define BUTTON_UNPRESED 1

#define PULSE_ON 0
#define PULSE_OFF 1
#define MIN_T 10
#define MAX_T 5000
#define MIN_UP_PULSES 0


#include<avr/io.h>
#include<interrupt.h>
#include<util/delay.h>
#include<stdlib.h>

void initialization(void);

void state_machine(void);
void switch_T_FU(void);

void LCD_Command(unsigned char cmnd);
void LCD_Init (void);
void LCD_String_start(void);
unsigned char LCD_Char_C(void);
unsigned char LCD_Char_ch_1(void);
unsigned char LCD_Char_ch_2(void);
unsigned char LCD_Char_ch_3(void);
unsigned char LCD_Char_ch_4(void);
unsigned char LCD_Char_space(void);

unsigned char LCD_Char_O1(void);
unsigned char LCD_Char_n(void);
unsigned char LCD_Char_space1(void);
unsigned char LCD_Char_space2(void);
unsigned char LCD_Char_space3(void);
unsigned char LCD_Char_space4(void);
unsigned char LCD_Char_space5(void);
unsigned char LCD_Char_space6(void);
unsigned char LCD_Char_space7(void);
unsigned char LCD_Char_space8(void);
unsigned char LCD_Char_space9(void);
unsigned char LCD_Char_space10(void);
unsigned char LCD_Char_space11(void);


unsigned char LCD_Char_O2(void);
unsigned char LCD_Char_f1(void);
unsigned char LCD_Char_f2(void);

unsigned char LCD_Char_T(void);
unsigned char LCD_Char_space_fromT(void);
unsigned char LCD_Char_ddot(void);
unsigned char LCD_Char_m(void);
unsigned char LCD_Char_s(void);

unsigned char LCD_Char_F(void);
unsigned char LCD_Char_U(void);
unsigned char LCD_Char_percent(void);

unsigned char LCD_Char_str0(void);
unsigned char LCD_Char_str1(void);
unsigned char LCD_Char_str2(void);
unsigned char LCD_Char_str3(void);

void config_timer0(void);
void config_timer1(void);

void call_1ms(void);

unsigned char pwm0(unsigned short pulse_width, unsigned short period);

void usart_init(void);
void commandReceived(void);

volatile unsigned char var_1ms;     //variable set every 1ms
volatile unsigned char var_24us;		//variable set every 8us

unsigned short T_val;				//store T of signal
unsigned short FU_val;				//store FU of signal
char str_measured_value[6];				        //vector who stores in ASCII measured value;
unsigned char display_T;				//what to print on display: T or FU
unsigned char signal_on;            //=1 when measured value is always on
unsigned char signal_off;			//=1 when measured value is always off
unsigned char enable_pwm;           //option to turn off from USART communication transmission of pwm
unsigned char channel_position;     //stores the channel position of the signal
unsigned char position_ASCII[2];    //vector who stores in ASCII channel position
signed short up_pulses;               //FU generated by PWM function
signed short period;              //T generated by PWM function

#endif /* HEADER_H_ */