#ifndef TIMER1_H
#define TIMER1_H
void Timer1_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T1Interrupt ( void );
void TMR1_CallBack( void );
#endif