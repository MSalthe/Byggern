#ifndef CAN_H
#define CAN_H

#include "mcp2515.h"

#define CAN_BAUD 125000 // Baud rate
#define TQ 800 // Time quanta in ns
#define F_OSC 4915200 // Oscillation frequency

typedef struct
{
    uint16_t id;
    char data_length;
    char data[8];
} can_frame_t;


void can_init();

void can_transmit(const can_frame_t* msg);

can_frame_t can_read();

#endif // CAN_H