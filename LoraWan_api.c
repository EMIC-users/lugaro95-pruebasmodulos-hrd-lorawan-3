
/*==================[inclusions]=============================================*/
#include "inc/LoraWan_api.h"
#include "inc/lora_e5.h"
#include <stdarg.h>
#include "inc/streamOut.h"
#include "inc/streamIn.h"
#include <string.h>
#include "inc/userFncFile.h"

/*==================[internal data definition]===============================*/
// Buffer auxiliar para construcción del mensaje LoRaWAN
static char lw_buffer[128];
static uint16_t lw_buffer_idx = 0;

extern char devEUI[17];
extern char appEUI[LORAWAN_EUI_SIZE*8];
extern char appKey[LORAWAN_KEY_SIZE*8];

extern uint8_t devADDR[LORAWAN_ADDR_SIZE*8];

extern uint8_t appsKey[LORAWAN_KEY_SIZE*8];

extern uint8_t nwsKey[LORAWAN_KEY_SIZE*8];

uint8_t lorawan_connection_state = 0;
extern uint8_t lorawan_receive_payload;

uint8_t event_connected_flag = 0;

/*==================[internal functions declaration]=========================*/

static void lw_buffer_put(char c)
{
    if (lw_buffer_idx < sizeof(lw_buffer))
    {
        lw_buffer[lw_buffer_idx++] = c;
    }
}

static uint16_t lw_buffer_available(void)
{
    return sizeof(lw_buffer) - lw_buffer_idx;
}

static const streamOut_t streamOut_LoRaWAN_buffer = {
    lw_buffer_put,
    lw_buffer_available
};

const streamIn_t streamIn_LoRaWAN = {
    lw_payload_pop,
    lw_payload_is_empty,
    lw_payload_count
};

/*==================[public functions definition]============================*/

void modeLW(uint16_t mode)
{
    switch (mode)
    {
    case 0:// case mode TEST
        lwConfig.activationMode=LW_MODE_TEST;
        break;
    case 1:// case mode OTAA
        lwConfig.activationMode=LW_MODE_OTAA;
        break;
    case 2:// case mode ABP
        lwConfig.activationMode=LW_MODE_ABP;
        break;
    default:// default OTAA
        lwConfig.activationMode=LW_MODE_OTAA;
        break;
    }

}

void classLW(uint16_t class)
{
    switch (class)
    {
    case 0:
        lwConfig.modemClass=LW_CLASS_A;
        break;
    case 1:
        lwConfig.modemClass=LW_CLASS_B;
        break;
    case 2:
        lwConfig.modemClass=LW_CLASS_C;
        break;
    default:
        lwConfig.modemClass=LW_CLASS_A;
        break;
    }

}

void powerLW(uint16_t power)
{
    lwConfig.powerTx = power;
}

void bandLW(uint16_t bandPlan)
{
    switch (bandPlan)
    {
    case 0:
        lwConfig.bandPlan=EU868;
        break;
    case 1:
        lwConfig.bandPlan=US915;
        break;
    case 2:
        lwConfig.bandPlan=CN779;
        break;
    case 3:
        lwConfig.bandPlan=EU433;
        break;
    case 4:
        lwConfig.bandPlan=AU915;
        break;
    case 5:
        lwConfig.bandPlan=AS923;
        break;
    case 6:
        lwConfig.bandPlan=KR920;
        break;
    case 7:
        lwConfig.bandPlan=IN865;
        break;
    case 8:
        lwConfig.bandPlan=RU864;
        break;
    case 9:
        lwConfig.bandPlan=US915HYBRID;
        break;
    case 10:
        lwConfig.bandPlan=AU915OLD;
        break;
    default:
        lwConfig.bandPlan=AU915;
        break;
    }
}

void schemeLW(uint16_t dataRate)
{
    switch (dataRate)
    {
    case 0:
        lwConfig.dataRate=DR_0;
        break;
    case 1:
        lwConfig.dataRate=DR_1;
        break;
    case 2:
        lwConfig.dataRate=DR_2;
        break;
    case 3:
        lwConfig.dataRate=DR_3;
        break;
    case 4:
        lwConfig.dataRate=DR_4;
        break;
    case 5:
        lwConfig.dataRate=DR_5;
        break;
    case 6:
        lwConfig.dataRate=DR_6;
        break;
    case 7:
        lwConfig.dataRate=DR_7;
        break;
    case 8:
        lwConfig.dataRate=DR_8;
        break;
    case 9:
        lwConfig.dataRate=DR_9;
        break;
    case 10:
        lwConfig.dataRate=DR_10;
        break;
    case 11:
        lwConfig.dataRate=DR_11;
        break;
    case 12:
        lwConfig.dataRate=DR_12;
        break;
    case 13:
        lwConfig.dataRate=DR_13;
        break;
    default:
        lwConfig.dataRate=DR_0;
        break;
    }

}

void channelLW(uint16_t typeChannel,char* numChannel)
{
    switch (typeChannel)
    {
    case 0:
        lwConfig.typeChannel = LW_NUM;
        strcpy(lwConfig.numChannel,numChannel);
        break;
    case 1:
        lwConfig.typeChannel = LW_SINGLE;
        strcpy(lwConfig.numChannel,numChannel);
        break;
    }
}

void readCredLW(uint16_t lw_state_)
{
    switch (lw_state_)
    {
        case 0:
            lw_state = LW_READ_DEVADDR;
            break;
        case 1:
            lw_state = LW_READ_DEVEUI;
            break;
        case 2:
            lw_state = LW_READ_APPEUI;
            break;
    }
}

void LoRaWAN_init(void)
{
    loraE5_init();
}

void connLW(void)
{
    event_connected_flag = 0;
    loraE5_start();
}

void pLoRaWAN(char* format, ...)
{
    va_list arg;

    // Resetear el buffer
    lw_buffer_idx = 0;

    // Formatear los datos al buffer usando sendDataToStream()
    va_start(arg, format);
    sendDataToStream(&streamOut_LoRaWAN_buffer, format, arg);
    va_end(arg);

    // Enviar el buffer completo al driver LoRa E5
    if (lw_buffer_idx > 0)
    {
        loraE5_sendPacket(lw_buffer, lw_buffer_idx);
    }
}





uint8_t hex_to_int(char c)
{
    uint8_t first = (c >> 4) - 3;
    uint8_t second = c % 16;
    uint8_t result = first*10 + second;
    if(result > 9) result--;
    return result;
}

uint8_t hex_to_ascii(char c, char d)
{
    uint8_t high = hex_to_int(c) << 4;
    uint8_t low = hex_to_int(d);
    return high+low;
}


void sleepLW()
{
    loraE5_lowPower();

}

void awakeLW(void)
{
    loraE5_awake();
}

void beaconLW(int16_t periodicity,char* dataRatePinSlot,char* pSFreq,char* dataRateBeacon,char*  bFreq)
{
    lw_state = LW_BEACON_CONF;
    lwConfig.periodicity = periodicity;
    lwConfig.dataRatePinSlot = *dataRatePinSlot;
    lwConfig.pSFreq = *pSFreq;
    lwConfig.dataRateBeacon = *dataRateBeacon;
    lwConfig.bFreq = *bFreq;
}

void Poll_LoRaWAN(void)
{
    
    uint8_t status;
    status = Poll_loraE5();

    if(status == 1)
    {
        if(event_connected_flag == 0)
        {
            event_connected_flag = 1;
            eLWcon();
            //gpio_pinSet(PORT_Led1, GPIO_TOGGLE);
        }
        if(lorawan_receive_payload == 1 && event_connected_flag == 1)
        {
            lorawan_receive_payload = 0;
            lw_payload_reset_read();
            eLoRaWAN(&streamIn_LoRaWAN);
        }
    }
    else
    {
        if(event_connected_flag == 1)
        {
            eLoRaWANdis();
            event_connected_flag = 0;
        }
    }
    //Poll_loraE5();
}

/** @} doxygen end group definition */
/*==================[end of file]============================================*/  
