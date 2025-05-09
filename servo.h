#ifndef SERVO_H
#define SERVO_H

#include <msp430.h>
#include <stdint.h>

void initServo(void);
void moveServo(uint8_t degrees);

#endif
