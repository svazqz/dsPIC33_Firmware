#ifndef TIMER4_H
#define TIMER4_H
void Timer4_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _T4Interrupt ( void );
void TMR4_CallBack( void );
#endif