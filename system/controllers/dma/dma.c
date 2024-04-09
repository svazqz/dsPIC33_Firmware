#include "dma.h"

DMA* getDMA(PERIPHERAL_ID peripheral_id) {
    switch(peripheral_id) {
        case ADC_PERIPHERAL_ID:
            return getDMA0();
            break;
        default:
            return NULL;
            break;
    }
}