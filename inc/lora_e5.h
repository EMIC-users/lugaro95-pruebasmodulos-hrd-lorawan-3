
#ifndef _LORAWAN_E5_H_
#define _LORAWAN_E5_H_

#include <stdarg.h>
#include <stdint.h>

/*==================[inclusions]=============================================*/
//Default UART configuration "9600, 8, n,1" (8 bits data, no parity, 1 stop bit);
/*==================[macros]=================================================*/

#define LW_MAX_LENGHT_MSG 64

#define LORAWAN_KEY_SIZE        16 

#define LORAWAN_EUI_SIZE        8 


#define LORAWAN_ADDR_SIZE       4  

extern char devEUI[17];
extern char appEUI[LORAWAN_EUI_SIZE*8];
extern char appKey[LORAWAN_KEY_SIZE*8];

extern uint8_t devADDR[LORAWAN_ADDR_SIZE*8];

extern uint8_t appsKey[LORAWAN_KEY_SIZE*8];

extern uint8_t nwsKey[LORAWAN_KEY_SIZE*8];

extern uint8_t lorawan_receive_payload;

/*==================[typedef]================================================*/

typedef enum lw_state {
    LW_UART_TEST_CONN,
    LW_LOWPOWER,
    LW_LOWPOWER_AUTO_MODE,
    LW_SET_POWER,
    LW_READ_DEVADDR,
    LW_READ_DEVEUI,
    LW_READ_APPEUI,
    LW_SET_DEVADDR,
    LW_SET_DEVEUI,
    LW_SET_APPEUI,
    LW_BAND_CONF,
    LW_SCHEME_CONF,
    LW_CHANNEL_CONF,
    LW_CLASS_CONF,
    LW_MODE_CONF,
    LW_OTAA_CONNECT,
    LW_ABP_CONNECT,
    LW_TEST_CONNECT,
    LW_CONNECTED,
    LW_SEND_DATA,
    LW_RECEIVE_DATA,
    LW_BEACON_CONF,
    LW_RESET,   
    LW_IDLE,
    LW_WAIT_FOR_AWAKE,
    LW_STATE_NULL

}lw_state_t ;  

typedef enum lw_state_classB {
    LW_S0,                      // Beacon timing request
    LW_S1,                      // Beacon searching
    LW_S2,                      // Ping slot information request    
    LW_S3,                      // Failed
    LW_S4,                      // Not synced
    LW_S5,                      // Network not joined    
    LW_S6,                      // LoRaWAN is busy
    LW_S7                       // Send dummy uplink
}lw_state_classB_t ;

typedef enum lw_error_code_type {
    PARAMETERS_INVALID          = -1,
    COMMAND_UNKNOW              = -10,
    COMMAND_WRONG_FORMAT        = -11,
    COMMAND_UNAVAILABLE         = -12,
    TOO_MANY_PARAMETERS         = -20,
    LENGTH_COMMAND_TOO_LONG     = -21,
    RECEIVE_SYMBOL_TIMEOUT      = -22,
    INVALID_CHARACTER_RECEIVED  = -23,    
    EITHER                      = -24
}lw_error_code_t ;

typedef enum lw_error_status_type {
    STATUS_BUSY,
    STATUS_NO_NETWORK_JOINED,
    STATUS_ALREADY_JOINED_PREVIOUSLY_NETWORK,
    STATUS_NO_FREE_CHANNEL_FOUND,
    STATUS_DUTYCYCLE_RESTRICTED,
    STATUS_DATARATE_INVALID,
    STATUS_LENGTH_ERROR
}lw_error_status_t ;

typedef enum lw_activation_type {
    LW_MODE_TEST,
    LW_MODE_OTAA,
    LW_MODE_ABP
}lw_activation_t ;

typedef enum lw_class_type {
    LW_CLASS_A,
    LW_CLASS_B,
    LW_CLASS_C
}lw_class_type_t ;

typedef enum lw_band_plan {
    EU868,
    US915,
    CN779,
    EU433,
    AU915,
    CN470,
    AS923,
    KR920,
    IN865,
    RU864,
    US915HYBRID,
    AU915OLD
}lw_band_t ;

typedef enum lw_dr_scheme {
    DR_0,  
    DR_1,
    DR_2,
    DR_3,
    DR_4,
    DR_5,
    DR_6,
    DR_7,
    DR_8,
    DR_9,
    DR_10,
    DR_11,
    DR_12,
    DR_13
}lw_dr_t ;

typedef enum lw_channel_num {
    LW_NUM,
    LW_SINGLE
}lw_channel_t ;

typedef enum lw_log_level {
    LW_DEBUG,
    LW_INFO,
    LW_WARN,
    LW_ERROR,
    LW_FATAL,
    LW_PANIC,
    LW_QUIET
}lw_log_t ;

typedef enum lw_low_power_mode {
    LW_WK_BY_UART,
    LW_UNTIL_TIMEOUT,
    LW_ENTER_EXTREM_LWP,
    LW_EXIT_EXTREM_LWP
}lw_low_power_mode_t ;

typedef struct {
    lw_activation_t activationMode;
    lw_class_type_t modemClass;
    lw_band_t       bandPlan;
    lw_dr_t         dataRate;
    lw_channel_t    typeChannel;
    char            numChannel[5];
    uint8_t         powerTx;
    char            dataRatePinSlot;
    char            dataRateBeacon;
    uint8_t         periodicity;
    char            pSFreq;
    char            bFreq;
} lw_param_t;


extern lw_param_t lwConfig;

extern lw_state_t lw_state;

extern uint8_t lorawan_connection_state;
/*==================[external functions declaration]=========================*/ 

void default_Config(void);

void loraE5_init(void);

void loraE5_start(void);

void loraE5_checkAnswer(void);

void loraE5_lowPower();

void loraE5_awake(void);

void loraE5_updateState(char * answer);

uint8_t Poll_loraE5(void);

void sendCommand(const char *str,uint32_t);

void loraE5_sendPacket(char *buffer, uint16_t len);

char lw_payload_pop(void);

uint8_t lw_payload_is_empty(void);

uint16_t lw_payload_count(void);

void lw_payload_reset_read(void);

void ISR_UART1_CALLBACK(char d);

/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef _LORAWAN_E5_H_ */
