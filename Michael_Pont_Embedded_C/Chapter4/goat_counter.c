#include <Reg52.h>

// Connect switch to this pin

sbit Switch_pin = P1 ^ 0;

// Return values from Switch_Get_Input()

#define SWITCH_NOT_PRESSED (bit) 0
#define SWITCH_PRESSED (bit) 1

// Function prototypes
void SWITCH_Init(void);
bit SWITCH_Get_Input(const unsigned char DEBOUNCE_PERIOD);
void DISPLAY_SWITCH_STATUS_Init(void);
void DISPLAY_SWITCH_STATUS_Update(const bit);
void DELAY_LOOP_Wait(const unsigned int DELAY_MS);

/* --------------------------------------------------------- */
void main(void) {


    }

/*------------------------------------------------------------*-
SWITCH_Init()
Initialisation function for the switch library.
-*------------------------------------------------------------*/
void SWITCH_Init(void) {
    Switch_pin = 1; // Use this pin for input
}

/*------------------------------------------------------------*-
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
-*------------------------------------------------------------*/
bit SWITCH_Get_Input(const unsigned char DEBOUNCE_PERIOD) {
    bit Return_value = SWITCH_NOT_PRESSED;
    if (Switch_pin == 0) {
        // Switch is pressed
        // Debounce – just wait...
        DELAY_LOOP_Wait(DEBOUNCE_PERIOD);
        // Check switch again
        if (Switch_pin == 0) {
            Return_value = SWITCH_PRESSED;
        }
    }
    // Now return switch value
    return Return_value;
}

/* SWITCH_Get_Input_After_Rising_Edge()
Reads and debounces a mechanical switch as follows:
1. If switch is not pressed, return SWITCH_NOT_PRESSED.
2. If switch is pressed, wait for DEBOUNCE_PERIOD (in ms).
a. If switch is not pressed, return SWITCH_NOT_PRESSED.
b. If switch is pressed, wait (indefinitely) for
switch to be released, then return SWITCH_PRESSED

______       HERE VALUE RETURNS->______
-----|                           |----|
-----|___________________________|
------------------------------> TIME
-------------------------------------------------------------*/

bit SWITCH_Get_Input_After_Rising_Edge(const unsigned char DEBOUNCE_PERIOD)
{
    bit Return_value = SWITCH_NOT_PRESSED;
    if (Switch_pin == 0) {
        // Switch is pressed
        // Debounce – just wait...
        DELAY_LOOP_Wait(DEBOUNCE_PERIOD);
        // Check switch again
        if (Switch_pin == 0) {
            // Wait until the switch is released.
            while (Switch_pin == 0)
                ;
            Return_value = SWITCH_PRESSED;
        }
    }
    // Now (finally) return switch value
    return Return_value;
}
/*----------------------------


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
void DISPLAY_COUNT_Init(void)
{
    Count_port = 0x00;
    }
/*------------------------------------------------------------*-
DISPLAY_COUNT_Update()
Simple function to display tByte data (COUNT)
on LEDs connected to port (Count_Port)
-*------------------------------------------------------------*/
void DISPLAY_COUNT_Update(const unsigned char COUNT)
{
    Count_port = COUNT;
    }
