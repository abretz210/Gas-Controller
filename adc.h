#ifndef ADC_H
#define ADC_H

#include <msp430.h>
#include <stdint.h>

void initADC(void);
uint16_t readADC(uint8_t channel);

#endif
