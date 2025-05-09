#ifndef FLAME_H
#define FLAME_H

#include <msp430.h>
#include <stdint.h>

void initOpAmpPGA(void);
uint16_t readFlameSensor(void);

#endif
