#ifndef INTCN_H
#define INTCN_H
void CN_Init( void );
void __attribute__ ( ( interrupt, no_auto_psv ) ) _CNRXInterrupt ( void );
void CN_CallBack( void );
#endif