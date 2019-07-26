/*
 * robotOS.c
 *
 *  Created on: Feb 3, 2015
 *      Author: timothy.edwards
 */

//Project #8

#include <p30f3013.h>
#include "aliases.h"
#include "utilities.h"
#include "definitions.h"

void runRobotOS();
void detectHit();

void runRobotOS() {
	printf('Running Robot OS...\r\nTurning everything off...\r\n');

	//Turning pins off initially (for LE-4)
	motor1a = OFF;
	motor1b = OFF;
	motor2a = OFF;
	motor2b = OFF;

	//Makes whole robot go for 5-10 feet and then makes it stop.
	/*turnAMotorCW();
'	turnBMotorCW();
	pause(8000);
	turnAMotorOff();
	turnBMotorOff();*/ //DON'T NEED THIS (FOR PROJECT 5 LAB REPORT)

	//Testing functions individually:
	/*turnLeft();
	pause(700);
	turnLeft();
	pause(700);
	turnLeft();*/

	//Project 6 "Sign Off" Procedure:
	//True until robot's stopped.
	int robotRunning = 1;

	//Keeps moving forward until it hits a wall
	//and then turns appropriately.
	while(robotRunning)
	{
		//Comment out this just for Project 8:
		//detectHit();

		SetUpSensing();
		detectLightDiversion();
		detectHit();
		pause(150);
	}
}

//Detects if bumper's been hit, and returns whether or not it has (1=true; 0=false)
void detectHit()
{
		//Just left bumper hit.
		if(leftBumper == 1 && rightBumper == 0)
		{
			//Backs up in order to turn.
			pause(150);
			moveBackward();
			pause(150);

			//To turn right 90 degrees.
			int i;
			for(i=0; i < 1; i++)
			{
				turnRight();
				pause(150);
			}

			resetLatch();
			moveForward();
		}

		//Just right bumper hit.
		if(rightBumper == 1 && leftBumper == 0)
		{
			//Backs up in order to turn.
			pause(150);
			moveBackward();
			pause(150);

			//To turn left 90 degrees.
			int i;
			for(i=0; i < 2; i++)
			{
				turnLeft();
				pause(150);
			}

			resetLatch();
			moveForward();
		}

		//Both bumpers hit.
		if(rightBumper == 1 && leftBumper == 1)
		{
			//Backs up in order to turn.
			pause(150);
			moveBackward();
			pause(150);

			//Turn 180 degrees.
			int i;
			for(i = 0; i < 1; i++)
			{
				turnRight();
				pause(150);
			}
			resetLatch();
			moveForward();
		}
}

//See if robot's pointing too far away from light to be going right way.
void detectLightDiversion()
{
	//Current light sensor values to be dealt with.
	int currentLeft = abs(readPinTimer12());
	int currentRight = abs(readPinTimer11()) + 350;

	//JUST BASIC+ logical thought (probably will change):
	//If light seems brighter on one side, just turn that way.
	//If not, move forward.

	//Robot should only do stuff if it's far enough from light.
	if(!((currentLeft < 609) && (currentRight < 609)))
	{
		//If left light's closer, turn left
			if( (currentLeft < currentRight) && !isWithin(currentLeft, currentRight, 700) )
			{
				turnLeft();
				moveForward();
			}

			//If right light's closer, turn right.
			if( (currentLeft > currentRight) && !isWithin(currentLeft, currentRight, 700) )
			{
				turnRight();
				moveForward();
			}

			//If both light's are same distance, do nothing (will accomodate for going away from light
			//later)
			if(isWithin(currentLeft, currentRight, 900))
			{
				moveForward();

				//Could have driven directly away from light by mistake.  Checking value change:
				SetUpSensing();
				if((abs(readPinTimer12()) > currentLeft) && (abs(readPinTimer11()) + 350 > currentRight))
				{
					//Makes sure robot's definitely not facing away from light
					//to "avoid confusion".
					turnLeft();
				}
			}
	}
}

//Gets light sensors prepared to yield values.
void SetUpSensing()
{
	pin11Direction = OUTPUT;  // make this output
			pin12Direction = OUTPUT;
			digOutput11 = 1;		// ready the RC Circuit!
			digOutput12 = 1;
			pause(5);		// wait for it….
			pin11Direction = INPUT;	// Go! Change to input pin type
			pin12Direction = INPUT;

			startPinTimer11();	// start the timer
			startPinTimer12();
			pause(5);		// let the capacitor charge
			/*  Print the values.. Just use them as integers */
			printf("Right Light: %d\r\n", readPinTimer11());
			printf("Left Light:  %d\r\n", readPinTimer12());
			printf("                \r\n");
			pause(150);  // wait one second to slow down the UART Display
}
