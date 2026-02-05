#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_Led1.h"
#include "inc/led_Led2.h"
#include "inc/led_Led3.h"
#include "inc/timer_api1.h"
#include "inc/LoraWan_api.h"
#include "inc/EMICBus.h"

void onReset()
{
    LEDs_Led1_blink(125, 250, 3);
    LEDs_Led2_blink(125, 250, 3);
    LEDs_Led3_blink(125, 250, 3);
    setTime1(20000, 'T');
}


void eLWcon()
{
    LEDs_Led3_state(1);
}


void eLoRaWANdis()
{
    LEDs_Led3_state(0);
}


void eI2C(char* tag, const streamIn_t* const msg)
{
    pLoRaWAN("$s\t$r", tag, msg);
    LEDs_Led1_blink(125, 250, 1);
}


void eLoRaWAN()
{
    pI2C("HOLA\tMUNDO");
    LEDs_Led2_blink(125, 250, 1);
}


void etOut1()
{
    connLW();
}



