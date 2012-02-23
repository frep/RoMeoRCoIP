/*
 * RoMeo.h
 *
 *	Contains the RoMeo - board specific informations, such as
 *	pin definitions, usage of the buttons, etc.
 *
 *  Created on: 19.01.2012
 *      Author: frehnerp
 */

#ifndef ROMEO_H_
#define ROMEO_H_

#ifdef DEFINE_ROMEO_VARIABLES
#define EXTERN_ROMEO				// nothing
#define INIT_ROMEO_SIMPLE(x)		= x
#define INIT_ROMEO_COMPLEX(x, ...)	= x, __VA_ARGS__
#else
#define EXTERN_ROMEO				extern
#define INIT_ROMEO_SIMPLE(x)		// nothing
#define INIT_ROMEO_COMPLEX(x, ...)	// nothing
#endif


// Used pins:
// ----------
// Digital pins
#define pinLeftSpeed       		6	// Motor 2 speed control
#define pinRightSpeed      		5	// Motor 1 speed control
#define pinLeftDirection   		7	// Motor 2 direction control
#define pinRightDirection  		4	// Motor 1 direction control
#define LED_PIN_1         		13	// LED1
// Analog pins
#define AnalogInputButtonPin	7	// Buttons 1 - 5

// function declarations:
// ----------------------
void stop(void);					// used to test the steering of the motors
void advance(int a,int b);			// used to test the steering of the motors
void back_off(int a,int b);			// used to test the steering of the motors
void turn_L(int a,int b);			// used to test the steering of the motors
void turn_R(int a,int b);			// used to test the steering of the motors

// usage of the buttons 1-5:
// -------------------------

// number of keys
#define NUM_KEYS	5

#define Button1 	1
#define Button2 	2
#define Button3 	3
#define Button4 	4
#define Button5 	5

// Indicates if a button is pressed:
// Values: 0 = No button is pressed
//         x = button x is pressed, where 1 <= x <= 5
//        -1 = an error occured
EXTERN_ROMEO int buttonIsPressed;

// a value smaller than thresholdButtonIsPressed indicates, that a button is pressed
#define thresholdButtonIsPressed 900

EXTERN_ROMEO unsigned int adc_key_val[5] INIT_ROMEO_COMPLEX({50, 180, 360, 620, 900 });

void checkRoMeoButtons();
int getButton(unsigned int input);

// Implement these functions, if you want to detect the press of a button
void button1IsPressed();
void button2IsPressed();
void button3IsPressed();
void button4IsPressed();
void button5IsPressed();

// Implement these functions, if you want to detect the release of a button
void button1IsReleased();
void button2IsReleased();
void button3IsReleased();
void button4IsReleased();
void button5IsReleased();

void stop(void);
void advance(int a,int b);
void back_off(int a,int b);
void turn_L(int a,int b);
void turn_R(int a,int b);

extern void sendUDPMessage(char msg[64]);

#endif /* ROMEO_H_ */
