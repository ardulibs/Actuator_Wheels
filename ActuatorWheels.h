/*
 * ActuatorWheels
 * Version 0.1.0 May, 2015
 * Copyright 2015 Diego de los Reyes
 *
 * Basic wheels control.
 */

#ifndef ActuatorWheels_h
#define ActuatorWheels_h
#define LIBRARY_VERSION	 0.1

#include <Servo.h>

// Class ActuatorWheels
class ActuatorWheels {
 
	/** Public elements. **/
	public:
	
		/**
		 * Construct.
		 */
		ActuatorWheels();
	
		/**
		 * Attach the given pins.
		 * @param pinLeft: pin where the left servo is connected.
		 * @param pinRight: pin where the right servo is connected.
		 */
		void attach(int pinLeft, int pinRight);

		/**
		 * Starts moving fordward.
		 */
		void moveFordward(int velocity);

		/**
		 * Starts moving backward.
		 */
		void moveBackward(int velocity);

		/**
		 * Rotates left.
		 */
		void rotateClockwise(int velocity);

		/**
		 * Rotates Right.
		 */
		void rotateCounterclockwise(int velocity);

		/**
		 * Stops moving.
		 */
		void stopAdvance();

	private:

		/** Attributes **/

		//Stop position of the servos.
		int stop_position = 95;

		//Controls the right servo.
		Servo right_servo;

		//Controls the left servo.
		Servo left_servo;
};

#endif

