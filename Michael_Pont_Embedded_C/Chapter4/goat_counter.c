/**********************************************


goat_counter(v1.00)

-------------------------------------------------
"Goat_counter" program for the 8051

-------------------------------------------------*/

#include <Reg52.h>

// Connect switch to this pin

sbit Switch_pin_GLOBAL = P1^0;

//Display count in PORT3
#define COUNT_PORT P3

//define semantic values for pressed buttons
#define SWITCH_NOT_PRESSED (bit) 0
#define SWITCH_PRESSED (bit) 1

// Funtion prototypes

void SWITCH_Init();
bit SWITCH_GET_INPUT_rising_edge(const unsigned char);
void DISPLAY_COUNT_ON_OUTPUT_Init(void);
void DISPLAY_COUNT_ON_OUTPUT_Update(const unsigned char);
void DELAY_LOOP_Wait(const unsigned int);

/***************************************************************/

void main(void) 
{
	unsigned char Switch_presses = 0;
	
	// Init Functions
	SWITCH_Init();
	DISPLAY_COUNT_ON_OUTPUT_Init();
	
	Switch_presses = COUNT_PORT;
	
	//Superloop
	
	while(1) {
		
		if (SWITCH_GET_INPUT_rising_edge(30) == SWITCH_PRESSED)
		{
			Switch_presses++;
		}
		DISPLAY_COUNT_ON_OUTPUT_Update(Switch_presses);
	}
}

// Functions

/**********************************************************

SWITCH_Init()
INITIALIZATION OF SWITCH PIN SELECTED AS INPUT

**********************************************************/

void SWITCH_Init(){
		Switch_pin_GLOBAL = 1;
}

/**********************************************************

SWITCH_Get_Input()
Reads and debounces a mechanical switch as follows:
72 Embedded C
8322 Chapter 4 p57-80 21/2/02 9:55 am Page 72
1. If switch is not pressed, return SWITCH_NOT_PRESSED.
2. If switch is pressed, wait for DEBOUNCE_PERIOD (in ms),
then:
a. If switch is still pressed, return SWITCH_PRESSED.
b. If switch is not pressed, return SWITCH_NOT_PRESSED
See Switch_Wait.H for details of return values.

**********************************************************/

bit SWITCH_GET_INPUT_rising_edge(const unsigned char DEBOUNCE_PERIOD) {
    bit Return_value = SWITCH_NOT_PRESSED;
    if (Switch_pin_GLOBAL == 0) {
        // Switch is pressed
        // Debounce – just wait...
        DELAY_LOOP_Wait(DEBOUNCE_PERIOD);
        // Check switch again
        if (Switch_pin_GLOBAL == 0) {
	while(Switch_pin_GLOBAL == 0) {
	}
            Return_value = SWITCH_PRESSED;
        }
    }
    // Now return switch value
    return Return_value;
}

/*------------------------------------------------------------*-
DELAY_LOOP_Wait()
Delay duration varies with parameter.
Parameter is, *ROUGHLY*, the delay, in milliseconds,
on 12MHz 8051 (12 osc cycles).
You need to adjust the timing for your application!
-*------------------------------------------------------------*/
void DELAY_LOOP_Wait(const unsigned int DELAY_MS) {
    unsigned int x, y;
    for (x = 0; x <= DELAY_MS; x++) {
        for (y = 0; y <= 120; y++)
            ;
    }
}

/*------------------------------------------------------------*-
DISPLAY_COUNT_Init()
Initialisation function for the DISPLAY COUNT library.
-*------------------------------------------------------------*/
void DISPLAY_COUNT_ON_OUTPUT_Init(void)
{
    COUNT_PORT = 0xF0;
    }
/*------------------------------------------------------------*-
DISPLAY_COUNT_Update()
Simple function to display tByte data (COUNT)
on LEDs connected to port (Count_Port)
-*------------------------------------------------------------*/
void DISPLAY_COUNT_ON_OUTPUT_Update(const unsigned char COUNT)
{
    COUNT_PORT = COUNT;
    }
