/*
 * Ps3Rx.h
 *
 *  Created on: 21.02.2012
 *      Author: frehnerp
 */

#ifndef PS3RX_H_
#define PS3RX_H_

#ifdef DEFINE_PS3RX_VARIABLES
#define EXTERN_PS3RX				// nothing
#define INIT_PS3RX_SIMPLE(x)		= x
#define INIT_PS3RX_COMPLEX(x, ...)	= x, __VA_ARGS__
#else
#define EXTERN_PS3RX				extern
#define INIT_PS3RX_SIMPLE(x)		// nothing
#define INIT_PS3RX_COMPLEX(x, ...)	// nothing
#endif

#define CMD_STOP     0
#define CMD_FORWARD  1
#define CMD_BACKWARD 2
#define CMD_LEFT     3
#define CMD_RIGHT    4

EXTERN_PS3RX bool ps3ButtonIsPressed;
EXTERN_PS3RX uint8_t value;
EXTERN_PS3RX uint8_t cmd;

EXTERN_PS3RX void receiveEvent(int howMany);

void setupPs3();

void checkPs3Command();

#endif /* PS3RX_H_ */
