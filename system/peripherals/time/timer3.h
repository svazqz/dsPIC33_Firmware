#ifndef TIMER3_H
#define TIMER3_H
void Timer3_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T3Interrupt ( void );
void TMR3_CallBack( void );
#endif