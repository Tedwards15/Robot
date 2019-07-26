/*

 * microfunctions.c
 *
 *  Created on: Jan 15, 2015
 *      Author: timothy.edwards
 */


#include <p30f3013.h>
#include "aliases.h"
#include "utilities.h"
#include "definitions.h"

//Functions to turn on and off LEDs.
void turnRedOn()
{
	redLED = ON;
}

void turnRedOff()
{
	redLED = OFF;
}

void turnGreenOn()
{
	greenLED = ON;
}

void turnGreenOff()
{
	greenLED = OFF;
}

void turnAMotorCW()
{
	//Making sure CCW is OFF!!
	motor1b = OFF;

	motor1a = ON;
}

void turnAMotorCCW()
{
	//Making sure CW is OFF!!
	motor1a = OFF;

	motor1b = ON;
}

void turnAMotorOff()
{
	motor1a = OFF;
	motor1b = OFF;
}

void turnBMotorCW()
{
	//Making sure CCW is OFF!!
	motor2b = OFF;

	motor2a = ON;
}

void turnBMotorCCW()
{
	//Making sure CW is OFF!!
	motor2a = OFF;

	motor2b = ON;
}

void turnBMotorOff()
{
	motor2a = OFF;
	motor2b = OFF;
}

//Functions to move/turn the robot.
void moveForward()
{
	printf("Moving forward...\r\n");
	turnRedOn();
	turnGreenOn();

	turnAMotorCW();
	turnBMotorCW();
	pause(905);
	turnAMotorOff();
	turnBMotorOff();

	turnAMotorCW();
	pause(10);
	turnAMotorOff();

	turnRedOff();
	turnGreenOff();
}

void moveBackward()
{
	printf("Moving backward...\r\n");
	turnRedOn();
	turnGreenOn();

	turnAMotorCCW();
	turnBMotorCCW();
	pause(300);

	turnAMotorOff();
	turnBMotorOff();

	//Correction due to cockied-ness.
	turnAMotorCCW();
	pause(10);
	turnAMotorOff();

	turnRedOff();
	turnGreenOff();
}

//Function for turning clockwise.
void turnRight()
{
	printf("Turning right 30 deg...\r\n");
	turnRedOn();

	turnAMotorCW();
	turnBMotorCCW();
	pause(132);

	turnAMotorOff();
	turnBMotorOff();

	turnRedOff();
}

void turnRightMore()
{
	printf("Turning right 45 deg...\r\n");
		turnAMotorCW();
		turnBMotorCCW();
		pause(150);

		turnAMotorOff();
		turnBMotorOff();

		pause(250);
}

//Function for turning counter-clockwise.
void turnLeft()
{
	printf("Turning left 30 deg...\r\n");
	turnGreenOn();

	turnAMotorCCW();
	turnBMotorCW();
	pause(132);

	turnAMotorOff();
	turnBMotorOff();

	turnGreenOff();
}

void turnLeftMore()
{
	printf("Turning left 45 deg...\r\n");
		turnAMotorCCW();
		turnBMotorCW();
		pause(160);

		turnAMotorOff();
		turnBMotorOff();

		pause(250);
}

void resetLatch()
{
	resetPin = ON;
	pause(50);
	resetPin = OFF;
}

///Sees if number is within a number based on "tolerance" (a difference) amount.
int isWithin(int numNeeded, int numGiven, int toleranceAmount)
{
	//What to return
	int isTolerated = 0;

	//If difference between needed and actual is low enough, value's "tolerated".
	if(abs(numNeeded - numGiven) <= toleranceAmount)
	{
		isTolerated = 1;
	}

	return isTolerated;
}
