/*
 * RoMeo.cpp
 *
 *  Created on: 19.01.2012
 *      Author: frehnerp
 */


#include <Arduino.h>
#define DEFINE_ROMEO_VARIABLES	// global used ROMEO-variables are defined here
#include "RoMeo.h"
#include <RCRx.h>

void checkRoMeoButtons()
{
	// check if a button is already pressed
	if(buttonIsPressed)
	{
		// check if the pressed button is released again
		if(analogRead(AnalogInputButtonPin) > thresholdButtonIsPressed)
		{
			// use the following switch, if you want to detect the release of a button
			switch (buttonIsPressed)
			{
				case Button1:
					button1IsReleased();
					break;
				case Button2:
					button2IsReleased();
					break;
				case Button3:
					button3IsReleased();
					break;
				case Button4:
					button4IsReleased();
					break;
				case Button5:
					button5IsReleased();
					break;
				default:
					Serial.println("illegal switch value: button release");
					break;
			}
			buttonIsPressed = 0;	// button was released
		}
	}
	else
	{
		// check if a button is pressed now
		if(analogRead(AnalogInputButtonPin) <= thresholdButtonIsPressed)
		{
			// wait for debounce time
			delay(50);

			// identify the pressed key
			buttonIsPressed = getButton(analogRead(AnalogInputButtonPin));

			// use the following switch, if you want to detect the press of a button
			switch (buttonIsPressed)
			{
				case Button1:
					button1IsPressed();
					break;
				case Button2:
					button2IsPressed();
					break;
				case Button3:
					button3IsPressed();
					break;
				case Button4:
					button4IsPressed();
					break;
				case Button5:
					button5IsPressed();
					break;
				default:
					Serial.println("illegal switch value: could not identiy pressed button");
					break;
			}
		}
	}
}

int getButton(unsigned int input)
{
	int k;
	for (k = 0; k < NUM_KEYS; k++)
	{
		if (input < adc_key_val[k])
		{
			return k+1;		// number of the pressed button
		}
	}
	// if you come so far, no valid key could be identified -> return -1
	return -1;
}

void button1IsPressed()
{
	// implement actions for pressed button
	//Serial.println("button 1 is pressed");
}

void button2IsPressed()
{
	// implement actions for pressed button
	//Serial.println("button 2 is pressed");
}

void button3IsPressed()
{
	// implement actions for pressed button
	//Serial.println("button 3 is pressed");
}

void button4IsPressed()
{
	// implement actions for pressed button
	//Serial.println("button 4 is pressed");
}

void button5IsPressed()
{
	// implement actions for pressed button
	//Serial.println("button 5 is pressed");
}




// stop movement
void stop(void)
{
	digitalWrite(pinLeftSpeed,LOW);
    digitalWrite(pinRightSpeed,LOW);
    sendUDPMessage("cmd STOP");
}

// move forward
void advance(int a,int b)
{
	analogWrite (pinLeftSpeed,a);      		//PWM Speed Control
    digitalWrite(pinLeftDirection,HIGH);
    analogWrite (pinRightSpeed,b);
    digitalWrite(pinRightDirection,HIGH);
    sendUDPMessage("cmd VOR");
}

// move backward
void back_off(int a,int b)
{
	analogWrite (pinLeftSpeed,a);
    digitalWrite(pinLeftDirection,LOW);
    analogWrite (pinRightSpeed,b);
    digitalWrite(pinRightDirection,LOW);
    sendUDPMessage("cmd RUECK");
}

// turn Left
void turn_L(int a,int b)
{
	analogWrite (pinLeftSpeed,a);
    digitalWrite(pinLeftDirection,LOW);
    analogWrite (pinRightSpeed,b);
    digitalWrite(pinRightDirection,HIGH);
    sendUDPMessage("cmd LINKS");
}

// turn Right
void turn_R(int a,int b)
{
	analogWrite (pinLeftSpeed,a);
    digitalWrite(pinLeftDirection,HIGH);
    analogWrite (pinRightSpeed,b);
    digitalWrite(pinRightDirection,LOW);
    sendUDPMessage("cmd RECHTS");
}

