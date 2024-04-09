#ifndef INT2_H
#define INT2_H
void INT2_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _INT2Interrupt ( void );
void INT2_CallBack( void );
#endif