#include "clock.h"

void Clock_Init( void ) {
    RCONbits.SWDTEN = 0;                        /* Disable Watch Dog Timer*/
    
    PLLFBD = 54;                                // M=56
    CLKDIVbits.PLLPOST = 0;                     // N1=2
    CLKDIVbits.PLLPRE = 0;                      // N2=2

    // Clock switching to incorporate PLL
    __builtin_write_OSCCONH( 0x03 );            // Initiate Clock Switch to Primary

    // Oscillator(XT) with PLL (NOSC=0b011)
    __builtin_write_OSCCONL( OSCCON || 0x01 );  // Start clock switching
    while( OSCCONbits.COSC != 0b011 );
    // Wait for Clock switch to occur
}