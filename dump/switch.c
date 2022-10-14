#include "timer.h"
#include "switch.h"


#define SWITCH_NOT_PRESSED (bit) 0
#define SWITCH_PRESSED (bit) 1

bit SWITCH_NPN(const unsigned char DEBOUNCE_PERIOD, bit SWITCH_PIN) {
    bit Return_value = SWITCH_NOT_PRESSED;
    if (SWITCH_PIN == 0) {
        // Switch is pressed
        // Debounce – just wait...
        
        //INPUT HERE TIMER FOR DEBOUNCER
        
        // Check switch again
        if (SWITCH_PIN == 0) {
	while(SWITCH_PIN == 0) {
	}
            Return_value = SWITCH_PRESSED;
        }
    }
    // Now return switch value
    return Return_value;
}

bit SWITCH_PNP(const unsigned char DEBOUNCE_PERIOD, bit SWITCH_PIN) {
    bit Return_value = SWITCH_NOT_PRESSED;

    // If switch is pressed
    if (SWITCH_PIN == 1) {
        // Wait for debounce

        // INPUT HERE DEBOUNCE FUNCTION WITH TIMER0

        // If Switch is released
        if (SWITCH_PIN == 1) {
        // if switch is kept pressed, nothing happens , change for timeout later
            while(SWITCH_PIN == 1);
            // Switch released, value 1 pushed to variable
            Return_value = SWITCH_PRESSED;
        }

        // return value
        return Return_value;
    }
    }
    
