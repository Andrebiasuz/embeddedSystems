/*********************************************

LED BLINKING USING TIMER0. 
RESOLUTION : 50ms

**********************************************/
#include <reg52.h>

// LED will be connected to this pin
sbit LED_pin = P1^5; // ^ means XOR

// Stores the LED state

bit LED_state_G = 0;

// Function prototypes
void TOOGLE_OUTPUT_INIT(void);
void TOOGLE_OUTPUT_Change_State(void);
void DELAY_LOOP_Wait(const unsigned int);
void DELAY_HARDWARE_One_Second(void);
void DELAY_HARDWARE_50_ms (void);
 //*************************************************
 
 void main(void) 
 {
	 
	 TOOGLE_OUTPUT_INIT();
	 
	 while(1) 
	 {
		 // CHANGE THE STATE OF OUTPUT
		 TOOGLE_OUTPUT_Change_State();
		 // Delay for "APPROX" 1000ms
		 //DELAY_LOOP_Wait(1000);
		 DELAY_HARDWARE_One_Second();
		 
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

	
void DELAY_HARDWARE_One_Second(void)
{
   unsigned char d;
   
   for (d = 0 ; d < 20 ; d++)
   {
      DELAY_HARDWARE_50_ms();
}
}

void DELAY_HARDWARE_50_ms(void) 
{

   // Configure Timer as a 16-bit TIMER
   TMOD &= 0xF0; // clear Timer0 bits
   TMOD |= 0x01 ; // set Timer0 as 16 bit Timer 
   
   ET0 = 0; // No interrrupts
   
   // Values for High and Low calibration for 50ms delay 
   TH0 = 0x3C;
   TL0 = 0xB0;
   
   TF0 = 0; // Clear overflow flag
   TR0 = 1; // Start timer 0
   
   while(TF0 == 0); // Loop until timer Overflows
   
   TR0 = 0; // stop Timer 0
   
} 
