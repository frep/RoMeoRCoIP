/*
 * Ps3Rx.cpp
 *
 *  Created on: 21.02.2012
 *      Author: frehnerp
 */

#include "Arduino.h"
#include <Wire.h>
#include "RoMeo.h"
#include "Ps3Rx.h"

void setupPs3()
{
	// Initialise i2c communication (Receiver)
	Wire.begin(2);	// join i2c bus with address 2
	Wire.onReceive(receiveEvent);
	ps3ButtonIsPressed = false;
}

void checkPs3Command()
{
	if(ps3ButtonIsPressed)
	{
		switch (cmd)
		{
			case CMD_STOP:
				stop();
				break;
			case CMD_FORWARD:
				advance(value, value);
				break;
			case CMD_BACKWARD:
				back_off(value, value);
				break;
			case CMD_LEFT:
				turn_L(value, value);
				break;
			case CMD_RIGHT:
				turn_R(value, value);
				break;
			default:
				break;
		}
		ps3ButtonIsPressed = false;
	}
}
