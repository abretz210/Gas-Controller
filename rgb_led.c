#include "rgb_led.h"

void initRGBLED(void)
{
    P6DIR |= BIT0 | BIT1 | BIT2;
    P6SEL0 |= BIT0 | BIT1 | BIT2;
    P6SEL1 &= ~(BIT0 | BIT1 | BIT2);
    TB3CTL = TBSSEL__SMCLK | MC__UP | TBCLR;
    TB3CCR0 = 1023;
    TB3CCTL1 = TB3CCTL2 = TB3CCTL3 = OUTMOD_7;
}

void setRGBLED(uint8_t r, uint8_t g, uint8_t b)
{
    TB3CCR1 = 1023 - (r << 2);
    TB3CCR2 = 1023 - (g << 2);
    TB3CCR3 = 1023 - (b << 2);
}
