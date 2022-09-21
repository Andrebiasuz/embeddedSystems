/***********************************
helloworld.c
----------------------------------
"A Hello World in Embedded C for the 8051

--------------------------------------------*/

#include <reg52.h>

// LED will be connected to this pin
sbit LED_pin = P1^5; // ^ means XOR

// Stores the LED state

bit LED_state_G = 0;

// Function prototypes
 void TOOGLE_OUTPUT_Init(void);
 void TOOGLE_OUTPUT_Change_State(void);
 void DELAY_LOOP_Wait(const unsigned int);
 //*************************************************
 
 void main(void) 
 {
	 TOOGLE_OUTPUT_Init();
	 
	 while(1) 
	 {
		 // CHANGE THE STATE OF OUTPUT
		 TOOGLE_OUTPUT_Change_State();
		 // Delay for "APPROX" 1000ms
		 DELAY_LOOP_Wait(1000);
	 }
 }
 
 //**********************************************

// FUNCTIONS IMPLEMENTATIONS
 
 // Initialization for the TOOGLE_OUTPUT FUNCTION
 void TOOGLE_OUTPUT_INIT(){
	 LED_state_G = 0;
 }
 
 // FUNCTION TO TOOGLE AN OUTPUT, BOUND TO THIS BASIC IMPLEMENTATION
 void TOOGLE_OUTPUT_Change_State(void)
	 {
	 if (LED_state_G == 1)
		 {
			LED_state_G = 0;
			LED_pin = 0;
	 }
		else 
		{
			LED_state_G = 1;
			LED_pin = 1;
			
		}
 }

 // FUNCTION TO IMPLEMENTATION A NON-CANONIC DELAY BY USING THE OSCILLATOR CYCLE TO OUR
 // ADVANTAGE. THIS IS NOT THE BEST IMPLEMENTATION FOR A DELAY
 // OSCILLATOR = 12MHZ 
 // DELAY = 1000ms
 // EACH INSTRUCTION AFTER 12 CYCLES SO: 
 
  void DELAY_LOOP_Wait(const unsigned int DELAY)
	{
		unsigned int x , y;
		
		for (x = 0; x <= DELAY ; x++)
		{
			for (y = 0; y <= 120; y++)
			{
			}
		}
	}

	
 
 
