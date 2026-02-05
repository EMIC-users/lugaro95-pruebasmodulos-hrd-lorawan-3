#ifndef USERFNCFILE_H
#define USERFNCFILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// includes type definitions
#include "streamIn.h"
#include "streamOut.h"

/* Function Prototypes */
void onReset();
void eLWcon();
void eLoRaWANdis();
void eI2C(char* tag, const streamIn_t* const msg);
void eLoRaWAN();
void etOut1();

#endif /* USERFNCFILE_H */

