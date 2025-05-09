#include "servo.h"
#include "system.h"

void initServo(void)
{
    P5SEL0 |= MAIN_VALVE_PIN;
    P5SEL1 &= ~MAIN_VALVE_PIN;
    TB2CCR0 = 20000;
    TB2CCTL1 = OUTMOD_7;
    TB2CCR1 = 500;
    TB2CTL = TBSSEL__SMCLK | MC__UP | TBCLR;
}

void moveServo(uint8_t degrees)
{
    if (degrees > 90) degrees = 90;
    TB2CCR1 = 500 + ((degrees * 1000) / 90);
}
