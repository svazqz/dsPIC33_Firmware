#ifndef TIMER5_H
#define TIMER5_H
void Timer5_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T5Interrupt ( void );
void TMR5_CallBack( void );
#endif