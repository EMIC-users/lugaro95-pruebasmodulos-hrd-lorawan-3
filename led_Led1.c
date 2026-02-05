#include <xc.h>
#include "inc/led_Led1.h"
#include "inc/gpio.h"
#include "inc/systemTimer.h"

void LEDs_Led1_init (void)
{
	HAL_GPIO_PinCfg(Led1, GPIO_OUTPUT);
}


static uint16_t blkLed_timerOn = 0; 
static uint16_t blkLed_period = 0; 
static uint16_t blkLed_times = 0; 
static uint32_t blkLed_tStamp;
 
void LEDs_Led1_blink(uint16_t timeOn, uint16_t period, uint16_t times)
{
	HAL_GPIO_PinSet(Led1, GPIO_HIGH);
	blkLed_timerOn = timeOn; 
	blkLed_period = period; 
	blkLed_times = times;
	blkLed_tStamp = getSystemMilis();
}

void LEDs_Led1_poll ()
{
	if (blkLed_period > 0)
	{
		if ( getSystemMilis() - blkLed_tStamp > blkLed_period )
		{
			if (blkLed_times > 0)
			{
				blkLed_times--;
				if (blkLed_times == 0)
				{
					blkLed_period = 0;
				}
			}
			if (blkLed_period > 0)
			{
				HAL_GPIO_PinSet(Led1, GPIO_HIGH);
				blkLed_tStamp = getSystemMilis();
			}
		}
		else if ( getSystemMilis() - blkLed_tStamp > blkLed_timerOn )
		{
			HAL_GPIO_PinSet(Led1, GPIO_LOW);
		}
	}
}

