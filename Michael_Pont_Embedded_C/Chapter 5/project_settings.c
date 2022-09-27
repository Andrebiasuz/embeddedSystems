#ifndef _MAIN_H
#define _MAIN_H
//--------------------------------------------------------------
// WILL NEED TO EDIT THIS SECTION FOR EVERY PROJECT
//-------------------------------------------------------------
// Must include the appropriate microcontroller header file here
#include <reg52.h>

// Oscillator / resonator frequency (in Hz) e.g. (11059200UL)

#define OSC_FREQ (12000000UL)

// Number of oscillations per instruction (12, etc)
// 12 – Original 8051 / 8052 and numerous modern versions
// 6 – Various Infineon and Philips devices, etc.
// 4 – Dallas 320, 520 etc.
// 1 – Dallas 420, etc.
#define OSC_PER_INST (12)

#include <AT89S53.H>

#define OSC_FREQ(11059200UL)

typedef unsigned char tByte;

//--------------------------------------------------------------
// SHOULD NOT NEED TO EDIT THE SECTIONS BELOW
//--------------------------------------------------------------
// Typedefs 
typedef unsigned char tByte;
typedef unsigned int tWord;
typedef unsigned long tLong;
// Interrupts 
#define INTERRUPT_Timer_0_Overflow 1
#define INTERRUPT_Timer_1_Overflow 3
#define INTERRUPT_Timer_2_Overflow 5
#endif
/*------------------------------------------------------------*-
---- END OF FILE --------------------------------------------
-*------------------------------------------------------------*/
