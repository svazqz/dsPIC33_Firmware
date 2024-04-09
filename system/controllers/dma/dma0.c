#include "dma0.h"
#include "dma.h"
#ifdef DMA0_ENABLED
static void DMA0_Init( void );
static DMA DMA0;

void DMA0_Init( void ) {
    DMA0CONbits.SIZE    = 0; 
	DMA0CONbits.DIR     = 0; 
    DMA0CONbits.HALF    = 0;
    DMA0CONbits.NULLW   = 0;
    DMA0CONbits.AMODE   = 2;                                                    // Configure DMA for Peripheral indirect mode
    DMA0CONbits.MODE    = DMA0.mode;                                            // Configure DMA for Continuous Ping-Pong mode
    DMA0REQbits.IRQSEL  = DMA0.attached_interrupt;
    DMA0CNTbits.CNT     = 0;
 
	DMA0PAD = (volatile unsigned int) DMA0.padding;
	DMA0STAL = (unsigned int) DMA0.buffA;
	DMA0STAH = 0x0;
    DMA0STBL = (unsigned int) DMA0.buffB;
    DMA0STBH = 0;
    
    if(DMA0.enableInterrupts) {
        IFS0bits.DMA0IF = 0;                                                    // Clear the DMA interrupt flag bit
        IEC0bits.DMA0IE = 1;                                                    // Set the DMA interrupt enable bit
    }
    
    DMA0CONbits.CHEN = 1;                                                       // Enable DMA
}

void __attribute__((interrupt,no_auto_psv)) _DMA0Interrupt(void) {
    DMA0.callback();
    IFS0bits.DMA0IF = 0;
}

DMA* getDMA0() {
    return &DMA0;
}
#endif
