
#ifndef _LORAWAN_API_H_
#define _LORAWAN_API_H_

/*==================[inclusions]=============================================*/
#include <stdarg.h>
#include <stdint.h>

/*==================[macros]=================================================*/


/*==================[typedef]================================================*/


/*==================[external data declaration]==============================*/


/*==================[external functions declaration]=========================*/

void modeLW(uint16_t mode);

void classLW(uint16_t class);

void powerLW(uint16_t power);

void bandLW(uint16_t bandPlan);

void schemeLW(uint16_t dataRate);

void channelLW(uint16_t typeChannel,char* numChannel);

void connLW(void);

void readCredLW(uint16_t lw_state_);

void sleepLW();

void awakeLW(void);

void beaconLW(int16_t periodicity,char* dataRatePinSlot,char* pSFreq,char* dataRateBeacon,char*  bFreq);

void pLoRaWAN(char* format,...);

//void gLoRaWAN(void);

void LoRaWAN_init(void);

void Poll_LoRaWAN(void);
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif
