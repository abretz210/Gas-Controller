#include "flame.h"
#include "adc.h"
#include "system.h"

void initOpAmpPGA(void)
{
    SAC0DAC = DACSREF_1 | DACLSEL_2 | DACEN;
    SAC0DAT = 0x0000;
    SAC0OA = NMUXEN | PMUXEN | OAPM;
    SAC0PGA = 16;
    SAC0OA |= SACEN | OAEN;
}

uint16_t readFlameSensor(void)
{
    return readADC(FLAME_ADC_CH);
}
