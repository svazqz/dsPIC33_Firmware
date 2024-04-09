#ifndef DMA0_H
#define DMA0_H
#include "dmatypes.h"
#ifdef DMA0_ENABLED
DMA* getDMA0( void );
void __attribute__((interrupt,no_auto_psv)) _DMA0Interrupt(void);
#endif
#endif