#ifndef INT1_H
#define INT1_H
void INT1_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _INT1Interrupt ( void );
void INT1_CallBack( void );
#endif