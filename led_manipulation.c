



/*
 * GccApplication2.c
 *
 *
 * Author : tiemoko and tawsif
 */ 

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <avr/io.h>
#define F_CPU 1000000UL
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "defines.h"
#include  "hd44780.h"
#include "lcd.h"
#include <avr/interrupt.h>
//#include "pgmspace.h"

/*
 * Do all the startup-time peripheral initializations.
 */
/*
 * Do all the startup-time peripheral initializations.
 */
static void
ioinit(void)
{
  
  lcd_init();
}


 
 FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);
 // strings for required outputs
const char string_1[] PROGMEM = "None   ";
const char string_2[] PROGMEM = "Red    ";
const char string_3[] PROGMEM = "Blue   ";
const char string_4[] PROGMEM = "Green   ";
const char string_5[] PROGMEM = "Yellow ";
const char string_6[] PROGMEM = "Cyan   ";
const char string_7[] PROGMEM = "Magenta";
const char string_8[] PROGMEM = "White  ";
const char string_9[] PROGMEM = "On ";
const char string_10[] PROGMEM ="Off";




volatile int16_t togglepin=0; // initialising toggle pin 



int main(void)
{
	
	bool r,b,g ; // 
	r=0;
	b=0;
	g=0;
	//
	
	  ioinit();
	 
	  
	  stderr = &lcd_str;
	DDRB |=( (1<<PINB1)|(1<<PINB2)|(1<<PINB3)) ;// setting the pinb 1 2 & 3 as output 
	DDRB &=~( (1<<5)|(1<<6)) ;
	DDRB&= ~(1<<7); // setting pin 5 6 7 as input
	PORTB|=((1<<5)|(1<<6));
	PORTB|= (1<<7); //setting the inputs high
	PORTB |= (1<<PINB1);
	PORTB |= (1<<PINB2);
	PORTB |= (1<<PINB3); // setting the outputs low
	/* Replace with your application code */
	
        DDRB&=~(1<<4); // chasing pinb4 for interrupt
	GIMSK|=(1<<PCIE0);
	PCMSK0|=(1<<PCINT4);
	
	
     fprintf(stderr," R: ,  G: ,  B: ");
	 
	while (1)
	{ 
		sei();
		
			// cap is touched	
			if(togglepin==1){
				PORTB |= (1<<PINB1); 
				PORTB |= (1<<PINB2);
				PORTB |= (1<<PINB3);
				hd44780_outcmd(0xCE);
				fputs_P(string_10,stderr);
				

				if ((!((PINB)&(1<<5))) || (!((PINB)&(1<<6))) || (!((PINB)&(1<<7)))){
				if(!((PINB)&(1<<5)))//checking if the switch for blue is pressed{ 
					
					if (b==0)//off {
						b=1; // setting the bool variable as one
					
						hd44780_outcmd(0x8F); // printing red as 1 on the lcd
						fprintf(stderr, "1");
						
					}
					else // on{
						b=0; // setting bool variable as 0
						hd44780_outcmd(0x8F);// printing the bool variable
						fprintf(stderr, "0");
						//PORTB |=(1<<PINB3);
						
						
					}
				}
				
				if(!((PINB)&(1<<7)))// checking if the switch for red is pressed{
				
					
					if (r==0){
					
						hd44780_outcmd(0x83);// print red as 1 on screen
						fprintf(stderr, "1");
						r=1; // change the bool variable for red to 1
						
					}
					else{
						r=0;
					
						
						hd44780_outcmd(0x83);// printing the bool variable
						fprintf(stderr, "0"); // print the value of r on lcd
						
						
					}
					
				}
				
				if(!((PINB)&(1<<6)))// checking if the switch for green is pressed{
					
					if (g==0){
					
						hd44780_outcmd(0x89); // print the value of g on lcd
						fprintf(stderr, "1");
						g=1; //change bool variable of g to1
						
					}
					else{
						g=0;
						hd44780_outcmd(0x89);// printing the bool variable
						fprintf(stderr, "0"); // print the value of g on lcd
					
						
					}
					
				}
				
				}
				
				
				}
			
			//cap not touch 
			
			else{	
				
				hd44780_outcmd(0xCE);
				fputs_P(string_9,stderr); // printing the on string
				
			if ((!((PINB)&(1<<5))) || (!((PINB)&(1<<6))) || (!((PINB)&(1<<7)))){
				
				
				
		if(!((PINB)&(1<<5))){ 
			                
			
		          if (b==0){ 
					  b=1; // setting the bool variable as one
					  PORTB &=~ (1<<PINB3); // turning on pinb3 ( blue led light)
					  hd44780_outcmd(0x8F); // printing the bool variable
					  fprintf(stderr, "1");
				       
				  }
        else{ 
			b=0; // setting the bool variable as 0
			  hd44780_outcmd(0x8F); // printing the bool variable
			  fprintf(stderr, "0");
			   PORTB |=(1<<PINB3); // turning off pinb3 (blue led light)
			     
			  
	         }
			 }
			 
		if(!((PINB)&(1<<7))){
			         
		
		    if (r==0){ 
					  PORTB &=~ (1<<PINB1); // turning on pinb1 ( red led light)
					  	hd44780_outcmd(0x83);
					  	fprintf(stderr, "1");
						  r=1; // setting the bool variable as one
				    
			}
		else{
			r=0; // setting the bool variable as 0
			 PORTB |=(1<<PINB1); // turning off pinb1 ( red led light)
			
			hd44780_outcmd(0x83);
			fprintf(stderr, "0");
		
		
		}
			
			}
			
		if(!((PINB)&(1<<6))){
			            
			if (g==0){ 
					  PORTB &=~ (1<<PINB2);  // turning on pinb2 ( green led light)
					  	hd44780_outcmd(0x89);
					  	fprintf(stderr, "1");
						  g=1; // setting the bool variable as one
				
					  }
               else{
				   g=0; // setting the bool variable as 0
				   hd44780_outcmd(0x89);
				   fprintf(stderr, "0");
			            PORTB |=(1<<PINB2);// turning off pinb2 ( green led light)
			   
				  }
					
				}
			}
				
			
			}
				
				
			
						//checking which of the lights are on by using the bool variable assigned to
                                                // them earlier in the code and printing then according on led
						
						
						if (r==0 && g==0 && b==0){
							
							hd44780_outcmd(0xC0);
							fputs_P(string_9,stderr);
							//hd44780_outcmd(0xCE);
							//fprintf(stderr, "0N");
						}
						
						if (r==0 && g==00 && b==1){
			
							hd44780_outcmd(0xC0);
							fputs_P(string_3,stderr);
							//fprintf(stderr, "BLUE   ");
							//hd44780_outcmd(0xCE);
							//fprintf(stderr, "0N");
							//
						}
						
						if (r==0 && g==1 && b==0){
							
							hd44780_outcmd(0xC0);
							fputs_P(string_4,stderr);
							//fprintf(stderr, "GREEN   ");
							//hd44780_outcmd(0xCE);
							//fprintf(stderr, "0N");
						}
						
						if (r==0 && g==1 && b==1){
							
						hd44780_outcmd(0xC0);
						fputs_P(string_6,stderr);
						//fprintf(stderr, "CYAN   ");
						//hd44780_outcmd(0xCE);
						//fprintf(stderr, "0N");
						}
						
						if (r==1 && g==0 && b==0){
							
							hd44780_outcmd(0xC0);
							fputs_P(string_2,stderr);
							//fprintf(stderr, "RED    ");
							//hd44780_outcmd(0xCE);
							//fprintf(stderr, "0N");
						}
						
						if (r==1 && g==0 && b==1){
							
							hd44780_outcmd(0xC0);
							fputs_P(string_7,stderr);
							//fprintf(stderr, "MAGENTA");
							//hd44780_outcmd(0xCE);
							//fprintf(stderr, "0N");
						}
						
						if (r==1 && g==1 && b==0){
							hd44780_outcmd(0xC0);
							fputs_P(string_5,stderr);
							//fprintf(stderr, "YELLOW  ");
							//hd44780_outcmd(0xCE);
							//fprintf(stderr, "0N");
							
						}
						
						if (r==1 && g==1 && b==1){
							
							hd44780_outcmd(0xC0);
							fputs_P(string_8,stderr);
							//fprintf(stderr, "WHITE  ");
							//hd44780_outcmd(0xCA);
							////fprintf(stderr, "0N");
						}
		
		
	}
}

ISR(PCINT2_vect){
	hd44780_outcmd(0xC0);
	fputs_P(string_10,stderr); // printing the ‘off’ string
	if((PINB&(PINB4)))
       // checking if pinb4 is high or low
       // toggling the value of togglepin 
        {
	if(togglepin==0){
		togglepin=1;
		
	}
	else {
		togglepin=0;
	}
	}

      
}		
	