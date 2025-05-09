#include "system.h"
#include "rgb_led.h"
#include "servo.h"
#include "adc.h"
#include "flame.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 &= ~LOCKLPM5;

    gpio_Init();
    initRGBLED();
    initServo();
    initOpAmpPGA();
    initADC();
    moveServo(0);
    setRGBLED(0, 0, 255);

    while (1)
    {
        uint16_t pot = readADC(POT_PIN);
        uint16_t therm = readADC(THERM_PIN);

        switch (currentState)
        {
            case IDLE:
                setRGBLED(0, 0, 255);
                if (P1IN & CALL_FOR_HEAT)
                    goToState(STAGE_1_IGNITION);
                break;

            case STAGE_1_IGNITION:
                setRGBLED(255, 0, 0);
                P2OUT |= SOLENOID_PIN;
                P2OUT |= IGNITER_LED;
                {
                    unsigned char flame = 0;
                    for (int i = 0; i < 10; i++) {
                        if (readFlameSensor() > FLAME_THRESHOLD) {
                            flame = 1;
                            break;
                        }
                        __delay_cycles(1000000);
                    }
                    if (flame)
                        goToState(STAGE_2_MAIN_LIGHT);
                    else
                        goToState(FAILURE);
                }
                break;

            case STAGE_2_MAIN_LIGHT:
                setRGBLED(255, 255, 0);
                P2OUT &= ~IGNITER_LED;
                moveServo(45);
                delay_seconds(5);
                goToState(STAGE_3_HEATING);
                break;

            case STAGE_3_HEATING:
                setRGBLED(0, 255, 0);
                moveServo(90);
                delay_seconds(5);
                P2OUT &= ~SOLENOID_PIN;
                while (readADC(THERM_PIN) < readADC(POT_PIN))
                    __delay_cycles(100000);
                moveServo(0);
                setRGBLED(0, 0, 255);
                goToState(IDLE);
                break;

            case FAILURE:
                setRGBLED(255, 0, 0);
                while (1) __delay_cycles(500000);
        }

        __delay_cycles(50000);
    }
}
