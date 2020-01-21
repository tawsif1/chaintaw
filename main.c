/*
 * LAB 4.c
 *
 * Created: 11/17/2018 2:01:06 PM
 * Author : Qasim Ali(ID #1) & Muhammad Raza Zafar(ID #1)
 */
#include "defines.h"
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

uint8_t buffer_values_MCU[32];
uint16_t input_data_values[33];
FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
int counter=0;

void view(void);

int main(void)
{	
stdout = &uart_str;   
 stdin = &uart_str;               
uart_init();           //initialize uart

PORTB &= ~(1<<PORTB0); // Setting the input capture unit
DDRB  &= ~(1<<PORTB0);                  
TCCR1A &= ~(1<<WGM11);

TCCR1A &= ~(1<<WGM10); //Selecting CTC timer mode         
TCCR1B &= ~(1<<WGM13);
TCCR1B |= (1<<WGM12);

TCCR1B &= ~(1<<ICES1); //Triggering input capture edge select on a falling edge
TCCR1B |= (1<<CS10);   //Setting pre-scaler as 1
TIMSK1 |= (1<<ICIE1);  //Enabling Input Capture interrupt  
sei() ;

while (1) 
{
}
}

//Defining Input Capture Interrupt 
ISR (TIMER1_CAPT_vect) 
{		
	input_data_values[Array_Length_Count] = TCNT1;
	TCNT1 = 0; //setting it as 0
	/*setting the preamble value as reference for other information*/
	if (input_data_values[0] >= 12500 && input_data_values[0] <= 14000) //Setting a definite range because the data can deviate from the exact ticks i.e. 13500
	{
		counter++;
		if (counter==33)
		{
			for (int j=0;j<4;j++)
			{
				buffer_values_MCU[j]=0;
				for (int i=1+j*8; i<=8+8*j; i++)
				buffer_values_MCU[j] |= ((input_data_values[i]>= 2000 && input_data_values <= 2400)<<(i-j*8-1));
			}
			view();
		}
	}
	else if (input_data_values[0] >= 10500 && input_data_values[0] <= 11900) 
		view();
	  
}

void view() {
	if ((buffer_values_MCU[0] + buffer_values_MCU[1] == 255) && (buffer_values_MCU[2] + buffer_values_MCU[3]==255)) //Positive and negative data for both addresses and data should equal 255
		fprintf(stdout, "Address: %X, Data: %X\r\n", buffer_values_MCU[0], buffer_values_MCU[2]);
	else 
		fprintf(stdout, "invalid\r\n");
		counter=0;
}