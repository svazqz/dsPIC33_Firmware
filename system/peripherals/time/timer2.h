#ifndef TIMER2_H
#define TIMER2_H
void Timer2_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T2Interrupt ( void );
void TMR2_CallBack( void );
#endif