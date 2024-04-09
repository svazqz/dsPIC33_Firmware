/* 
 * File:   adc.h
 * Author: Sergio Vazquez
 *
 * Created on January 2, 2018, 8:14 PM
 */



#ifndef ADC_H
#define	ADC_H

#include "../../common.h"
#include "../../controllers/dma/dma.h"

void ADC_Init( void );
void ADC_Generic_Callback( void );
void ADC_CallBack( unsigned int (*b)[1] );

#endif	/* ADC_H */

