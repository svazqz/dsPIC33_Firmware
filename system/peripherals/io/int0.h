#ifndef INT0_H
#define INT0_H
void INT0_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _INT0Interrupt ( void );
void INT0_CallBack( void );
#endif