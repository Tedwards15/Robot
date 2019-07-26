/* * testSuite.c
 *
 *  Created on: Feb 3, 2015
 *      Author: timothy.edwards
 */

#include <p30f3013.h>
#include "utilities.h"
#include "definitions.h"
#include "aliases.h"

void runTestSuite();
void testMotor();
void runBumperTest();
void runLightTest();

void runTestSuite()
{
	printf("Seeing test suite...");
	//Test for BC-4
	//if(testPin3 && !testPin4)
	//{
		//printf("Running motor test...");
		//runMotorTest();
	//}
	//else if(!testPin3 && testPin4)
	//{
		//printf("Running bumper test...");
		//runBumperTest();
	//}
	//else
	//{
		//printf("Running light test...");
		//runLightTest();
	//}

	//Test for "Project 4 Signoff"
	//testMotor();
	runLightTest();
	//runBumperTest();

	//Lab Excersize #9:
	if((testPin4 == 1) && (testPin3 == 0))
	{
		testMotor();
	}
	else if((testPin3 == 1) && (testPin4 == 0))
	{
		runBumperTest();
	}
	else if((testPin3 == 1) && (testPin4 == 1))
	{
		runLightTest();
	}
}

//Test all possible spinning/off combinations of both motors.
void testMotor()
{
	//Turns all motors off initially (LE-4)
	printf('Turning all motors off...\r\n');
	turnAMotorOff();
	turnBMotorOff();

	//Performs set of motor runs and turns (LE-4 and "SignOff #4")
	printf("Turning Motor A on CW and green LED...\r\n");
	turnAMotorCW();
	turnGreenOn();

	pause(1000);

	printf("Turning off Motor A and green LED...\r\n");
	turnAMotorOff();
	turnGreenOff();
	//
	pause(1000);;
	//
	printf("Turning Motor A on CCW and green LED...\r\n");
	turnAMotorCCW();
	turnGreenOn();

	pause(1000);

	printf("Turning Motor A off and green LED...\r\n");
	turnAMotorOff();
	turnGreenOff();
	//
	pause(1000);;
	//
	printf("Turning Motor B on CW and red LED...\r\n");
	turnBMotorCW();
	turnRedOn();

	pause(1000);

	printf("Turning Motor B off and red LED...\r\n");
	turnBMotorOff();
	turnRedOff();
	//
	pause(1000);;
	//
	printf("Turning Motor B on CCW and red LED...\r\n");
	turnBMotorCCW();
	turnRedOn();

	pause(1000);

	printf("Turning Motor B off and red LED...\r\n");
	turnBMotorOff();
	turnRedOff();

	pause(1000);;

	///
	printf("Turning A Motor and B Motor both CW and turning on both LEDs...\r\n");
	turnAMotorCW();
	turnBMotorCW();
	turnRedOn();
	turnGreenOn();

	pause(1000);

	printf("Turning motor A, motor B, and turning off both LEDs...\r\n");
	turnAMotorOff();
	turnBMotorOff();
	turnRedOff();
	turnGreenOff();

	pause(1000);;

	///
	printf("Turning A Motor and B Motor both CCW and turning on both LEDs...\r\n");
	turnAMotorCCW();
		turnBMotorCCW();
		turnRedOn();
		turnGreenOn();

		pause(1000);

		printf("Turning motor A, motor B, and red LED...\r\n");turnRedOff();
		turnAMotorOff();
		turnBMotorOff();
		turnRedOff();
		turnGreenOff();

		pause(1000);;

		///
		printf("Turning A Motor CW, B Motor both CCW, and turning on both LEDs...\r\n");
			turnAMotorCW();
				turnBMotorCCW();
				turnRedOn();
				turnGreenOn();

				pause(1000);

				printf("Turning motor A, motor B, and red LED...\r\n");turnRedOff();
				turnAMotorOff();
				turnBMotorOff();
				turnRedOff();
				turnGreenOff();

				pause(1000);;

				///
				printf("Turning A Motor CCW, B Motor both CW, and turning on both LEDs...\r\n");
							turnAMotorCCW();
								turnBMotorCW();
								turnRedOn();
								turnGreenOn();

								pause(1000);

								printf("Turning motor A, motor B, and red LED...\r\n");turnRedOff();
								turnAMotorOff();
								turnBMotorOff();
								turnRedOff();
								turnGreenOff();

								pause(1000);

}

void runBumperTest()
{
	//Required switch state for bumper test to run.
	if(testPin3 == 1 && testPin4 == 0)
	{
		//Runs test as long as testPin4 is on.
		while(testPin3 == 1)
		{
			pause(400);

			if((leftBumper == 0) && (rightBumper == 0))
			{
				printf("Neither bumper's on.\r\n");
			}

			//Is left bumper on?
			if(leftBumper == 1)
			{
				printf("Left bumper's on.\r\n");
				turnGreenOn();
				pause(500);
				turnGreenOff();
				resetLatch();
			}

			//Is right bumper on?
			if(rightBumper == 1)
			{
				printf("Right bumper's on.\r\n");
				turnRedOn();
				pause(500);
				resetLatch();
				turnRedOff();
			}

			//If neither bumper is on:
			//if((rightBumper == 0) && (leftBumper == 0))
			//{
			//	printf("Neither bumper's on.\r\n");
			//}
		}
	}
}

void runLightTest()
{
	printf("Running light test...\r\n");
	//Both test pins should be on.
	while((testPin3 == ON) && (testPin4 == ON))
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
		pause(500);  // wait one second to slow down the UART Display
	}
}
