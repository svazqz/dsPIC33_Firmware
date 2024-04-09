#ifndef DMATYPES_H
#define DMATYPES_H
#include "../../common.h"

#define DMA0_ENABLED

typedef enum {
    PERIPHERAL_TO_RAM,
    RAM_TO_PERIPHERAL
} DMA_TRANSFER_MODE;

typedef struct {
    DMA_TRANSFER_MODE mode;
    unsigned int attached_interrupt;
    unsigned int padding;
    unsigned int buffA;
    unsigned int buffB;
    unsigned int transfers;
    bool enableInterrupts;
    void (*init)( void );
    void (*callback)( void );
} DMA;

#endif