/*
 * definitions.h
 *
 *  Created on: Jan 15, 2015
 *      Author: timothy.edwards
 */

#ifndef DEFINITIONS_H_
#define DEINITIONS_H_

//Definitions for LEDs
#define greenLED		digOutput5
#define redLED			digOutput6

//Definitions for "test pins" (pins that control things).
#define testPin3        digInput3
#define testPin4        digInput4

//Definitions for motors
#define motor1a         digOutput21
#define motor1b		    digOutput22
#define motor2a         digOutput23
#define motor2b		    digOutput24

//Defintions for bumpers
#define rightBumper		digInput25
#define leftBumper		digInput26

//Definitions for light sensors
#define rightLight		digOutput11
#define leftLight		digOutput12

#define resetPin		digOutput14

#define OFF 			0
#define ON				1

//Prototypes
void turnRedOn();
void turnGreenOn();
void turnRedOff();
void turnGreenOff();
void SetupPins();

#endif /* DEFINITIONS_H_ */
