/* main.c - main routine goes here
 * Author:
 * Purpose: Project # 5 Signoff ("Project #5")
 * date:
 */

#include <p30f3013.h>
#include "definitions.h"
#include "aliases.h"
#include "utilities.h"

void SetupPins()
{
   printf("Setting up pins... Project 7 SignOff");

   //Pins for LED lights (Project 3):
   pin5Type = DIGITAL;
   pin6Type = DIGITAL;

   pin5Direction = OUTPUT;
   pin6Direction = OUTPUT;

   //Pins for Boot Camp #4
   pin2Direction = OUTPUT;
   pin3Direction = INPUT;
   pin4Direction = INPUT;

   pin2Type = DIGITAL;
   pin3Type = DIGITAL;
   pin4Type = DIGITAL;

   pin3Direction = INPUT;
   pin4Direction = INPUT;

   //Pins Lab Excersize #4
   pin21Direction = OUTPUT;
   pin22Direction = OUTPUT;
   pin23Direction = OUTPUT;
   pin24Direction = OUTPUT;

   //Pins for Boot Camp #6
   pin7Direction = INPUT;
   pin10Direction = INPUT;
   pin7Type = OUTPUT;

   //Pins for Lab Excersize 7 and SignOff #7
   pin14Direction = OUTPUT;
   pin25Direction = INPUT;
   pin26Direction = INPUT;

   pin25Type = DIGITAL;
   pin26Type = DIGITAL;

   //Set up pins for Project 8 (for light sensor)
   pin11Direction = OUTPUT;
   pin12Direction = OUTPUT;
}

int main() {
  /* initialize the ability to send messages to the
   * PICKit 2 using printf.
   */
  initializeUART();

  //Sets all pins to digital.
  SetupPins();

  if(testPin3 || testPin4)
  {
	  runTestSuite();
  }
  else
  {
	  runRobotOS();
  }

  halt();

  return(0);
}
