/* 
 * File:   adc.c
 * Author: Sergio Vazquez
 *
 * Created on January 2, 2018, 8:14 PM
 */
#include "adc.h"

static unsigned int adcBuffA[16][1] __attribute__((aligned(16 * 16)));
static unsigned int adcBuffB[16][1] __attribute__((aligned(16 * 16)));
static DMA *ADC_DMA_CHANNEL;

void ADC_Init( void ) {
    ADC_DMA_CHANNEL = getDMA(ADC_PERIPHERAL_ID);
#ifndef PROD
    ANSELAbits.ANSA0 = 1;
    ANSELAbits.ANSA1 = 1;
#else
    ANSELBbits.ANSB0 = 1;
    ANSELBbits.ANSB1 = 1;
#endif
    AD1CON1bits.ADDMABM = 0; //DMA Buffer Build Mode bit
    AD1CON1bits.AD12B = 1; //ADC 10-Bit or 12-Bit Operation Mode bit
    AD1CON1bits.FORM = 0; //Data Output Format bits
    AD1CON1bits.SSRCG = 0;
    AD1CON1bits.SSRC = 7;
    AD1CON1bits.SIMSAM = 0;
    AD1CON1bits.ASAM = 1;
    
    AD1CON2bits.VCFG = 0;
    AD1CON2bits.CSCNA = 0; // * 0
    AD1CON2bits.CHPS = 0;
    AD1CON2bits.BUFM = 0;
    AD1CON2bits.SMPI = 1;
    AD1CON2bits.ALTS = 1;
    
    AD1CON3bits.ADRC = 0;
    AD1CON3bits.ADCS = 255; //****
    AD1CON3bits.SAMC = 0b11111; //****
    
    AD1CON4bits.ADDMAEN = 1;
    AD1CON4bits.DMABL = 0;
    
    // CH0SA AN0; CH0SB AN1; CH0NB AVSS; CH0NA AVSS; 
    AD1CHS0bits.CH0NA = 0; // Vrefl
    AD1CHS0bits.CH0SA = 0; // AN0
    AD1CHS0bits.CH0NB = 0; // Vrefl
    AD1CHS0bits.CH0SB = 1; // AN1
    
    // CSS26 disabled; CSS25 disabled; CSS24 disabled; CSS31 disabled; CSS30 disabled; 
    AD1CSSH = 0x0;
    // CSS2 disabled; CSS1 enabled; CSS0 enabled; CSS8 disabled; CSS7 disabled; CSS6 disabled; CSS5 disabled; CSS4 disabled; CSS3 disabled; 
    AD1CSSL = 0x3;
    // CH123SA disabled; CH123SB CH1=OA2/AN0,CH2=AN1,CH3=AN2; CH123NA disabled; CH123NB CH1=VREF-,CH2=VREF-,CH3=VREF-; 
    AD1CHS123 = 0x0;
    
    IFS0bits.AD1IF = 0;                                                         
    IEC0bits.AD1IE = 0;
    ADC_DMA_CHANNEL->mode = PERIPHERAL_TO_RAM;
    ADC_DMA_CHANNEL->attached_interrupt = 0xD;
    ADC_DMA_CHANNEL->padding = (unsigned int) &ADC1BUF0;
    ADC_DMA_CHANNEL->buffA = (unsigned int) adcBuffA;
    ADC_DMA_CHANNEL->buffB = (unsigned int) adcBuffB;
    ADC_DMA_CHANNEL->transfers = 0;
    ADC_DMA_CHANNEL->enableInterrupts = true;
    ADC_DMA_CHANNEL->callback = ADC_Generic_Callback;
    ADC_DMA_CHANNEL->init();
    AD1CON1bits.ADON = 1;    
}

void ADC_Generic_Callback() {
    ADC_CallBack(adcBuffA);
}

void __attribute__ ((weak)) ADC_CallBack(unsigned int (*buff)[1]) {
    
}