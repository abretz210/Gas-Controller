#include "system.h"

SystemState currentState = IDLE;

void gpio_Init(void)
{
    P2DIR |= SOLENOID_PIN | IGNITER_LED;
    P2OUT &= ~(SOLENOID_PIN | IGNITER_LED);
    P5DIR |= MAIN_VALVE_PIN;
    P1DIR &= ~CALL_FOR_HEAT;
    P1REN |= CALL_FOR_HEAT;
    P1OUT |= CALL_FOR_HEAT;
}

void delay_seconds(unsigned int s)
{
    while (s--) __delay_cycles(1000000);
}

void goToState(SystemState nextState)
{
    currentState = nextState;
}
