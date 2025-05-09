#include "adc.h"

void initADC(void)
{
    P1SEL0 |= BIT3 | BIT4 | BIT5;
    P1SEL1 |= BIT3 | BIT4 | BIT5;
    ADCCTL0 = ADCSHT_2 | ADCON;
    ADCCTL1 = ADCSHP | ADCCONSEQ_0;
    ADCCTL2 = ADCRES_2;
}

uint16_t readADC(uint8_t channel)
{
    ADCMCTL0 = channel;
    ADCCTL0 |= ADCENC | ADCSC;
    while (ADCCTL1 & ADCBUSY);
    return ADCMEM0;
}
