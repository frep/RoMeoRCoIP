// RCoIP.cpp
// =========
//
// Receives RCOIP commmands on a RedFly-shield and uses them to set analog and digital pins
// of the RoMeo board
// Original Sample RCRx RCOIP receiver by: Copyright (C) 2010 Mike McCauley

#include "Arduino.h"			// Every program has to include this file
#include "RoMeo.h"				// RoMeo - board specific commands
//#include <RedFly.h>				// Needed to work with the RedFly-Shield
//#include <RCRx.h>
#include "AnalogSetter.h"
#include "DigitalSetter.h"
#include <Wire.h>				// needed for i2c - communication
#include "I2C_functions.h"
#define DEFINE_PS3RX_VARIABLES
#include "Ps3Rx.h"

void sendUDPMessage(char msg[64]);

// Declare the receiver object
//RCRx rcrx;

#define NUM_OUTPUTS 5

// definitions of the used pins are in the board specific file: RoMeo.h
// There are 5 outputs for 5 channels:
DigitalSetter led1(LED_PIN_1);
DigitalSetter leftDirection(pinLeftDirection);
DigitalSetter rightDirection(pinRightDirection);
AnalogSetter  leftSpeed(pinLeftSpeed);
AnalogSetter  rightSpeed(pinRightSpeed);

// This array of all the outputs is in channel-number-order so RCRx knows which
// Setter to call for each channel received.
Setter* outputs[NUM_OUTPUTS] = {&led1, &leftDirection, &rightDirection, &leftSpeed, &rightSpeed};

void setup()
{

	// Define all the used pins as outputs:
	pinMode(LED_PIN_1, OUTPUT);
	pinMode(pinLeftSpeed, OUTPUT);
	pinMode(pinRightSpeed, OUTPUT);
	pinMode(pinLeftDirection, OUTPUT);
	pinMode(pinRightDirection, OUTPUT);

	// specific setup for Control over Ps3-controller
	setupPs3();

	// Initialise the receiver
	//rcrx.init();

	// Tell the receiver where to send the 5 channels
	//rcrx.setOutputs((Setter**)&outputs, NUM_OUTPUTS);

}

void loop()
{
	checkRoMeoButtons();
	//rcrx.run();	// And do it
	checkPs3Command();
}

void receiveEvent(int howMany)
{
	while(Wire.available() > 1)
	{
		cmd = Wire.read();
	}
	value = Wire.read();
	ps3ButtonIsPressed = true;
}


void sendUDPMessage(char msg[64])
{

	uint8_t length = 0;
	uint8_t message[64];
	while(msg[length] != '\0' && length < 63)
	{
		message[length] = (uint8_t)msg[length];
		length++;
	}
	//rcrx.sendMessage(message, length);

}


void button1IsReleased()
{
	// implement actions for released button
	sendUDPMessage("test");
}

void button2IsReleased()
{
	// implement actions for released button
	//rcrx.debugoutln("button 2 is released");
}

void button3IsReleased()
{
	// implement actions for released button
	//rcrx.debugoutln("button 3 is released");
}

void button4IsReleased()
{
	// implement actions for released button
	//rcrx.debugoutln("button 4 is released");
}

void button5IsReleased()
{
	// implement actions for released button
	//rcrx.debugoutln("button 5 is released");
}
