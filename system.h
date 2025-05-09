#ifndef SYSTEM_H
#define SYSTEM_H

#include <msp430.h>
#include <stdint.h>

#define IGNITER_LED    BIT0
#define SOLENOID_PIN   BIT5
#define MAIN_VALVE_PIN BIT0
#define CALL_FOR_HEAT  BIT2
#define THERM_PIN      BIT4
#define POT_PIN        BIT5
#define FLAME_ADC_CH   3
#define FLAME_THRESHOLD 620

typedef enum {
    IDLE,
    STAGE_1_IGNITION,
    STAGE_2_MAIN_LIGHT,
    STAGE_3_HEATING,
    FAILURE
} SystemState;

extern SystemState currentState;

void gpio_Init(void);
void delay_seconds(unsigned int s);
void goToState(SystemState nextState);

#endif
