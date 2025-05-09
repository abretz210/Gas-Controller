#ifndef RGB_LED_H
#define RGB_LED_H

#include <msp430.h>
#include <stdint.h>

void initRGBLED(void);
void setRGBLED(uint8_t r, uint8_t g, uint8_t b);

#endif
