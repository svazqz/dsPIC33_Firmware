#include <assert.h>
#include <stdio.h>
#include "system/system.h"

enum { NONE, CLOCK, ADC };
static int initialization_steps[2];
static size_t initialization_count;
static DMA fake_adc_dma;

extern int firmware_main(void);

void Clock_Init(void)
{
    assert(initialization_count < 2);
    initialization_steps[initialization_count++] = CLOCK;
}

void ADC_Init(void)
{
    assert(initialization_count < 2);
    initialization_steps[initialization_count++] = ADC;
}

DMA* getDMA0(void)
{
    return &fake_adc_dma;
}

int main(void)
{
    assert(firmware_main() == 0);
    assert(initialization_count == 2);
    assert(initialization_steps[0] == CLOCK && initialization_steps[1] == ADC);
    assert(getDMA(ADC_PERIPHERAL_ID) == &fake_adc_dma);
    assert(getDMA((PERIPHERAL_ID) 42) == NULL);
    puts("dsPIC33 initialization and DMA dispatch tests passed.");
    return 0;
}
