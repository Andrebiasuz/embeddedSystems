
void DELAY_HARDWARE_50_ms(void);







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

// BUILD PORTABLE TIMER 

/*

INPUTS: OUTSIDE FUNCTION
VALUE OF TIMER IN MS

INPUTS: INSIDE FUNCTION
CLOCK FREQUENCY
INSTRUCTION PER CYCLE
RESOLUTION

OUTPUT: NONE
*/

void PORTABLE_TIMER0_MS(unsigned char time) {
    unsigned int OVERFLOW_VALUE = 0;
    unsigned char i;
    unsigned char HIGH_REGISTER_TIMER , LOW_REGISTER_TIMER;
    // OVERFLOW FLAG CALCULATION
    OVERFLOW_VALUE = (65536 - 1) - ((time/1000) * (CLOCK_VALUE/INSTRUCTION_PER_CYCLE));

    HIGH_REGISTER_TIMER = OVERFLOW_VALUE / 256;
    LOW_REGISTER_TIMER = OVERFLOW_VALUE % 256 ;

   TMOD &= 0xF0; // clear Timer0 bits
   TMOD |= 0x01 ; // set Timer0 as 16 bit Timer 
   
   ET0 = 0; // No interrrupts
   
   // Values for High and Low calibration for 50ms delay 
   TH0 = HIGH_REGISTER_TIMER;
   TL0 = LOW_REGISTER_TIMER;
   
   TF0 = 0; // Clear overflow flag
   TR0 = 1; // Start timer 0
   
   while(TF0 == 0); // Loop until timer Overflows
   
   TR0 = 0; // stop Timer 0
    
}
