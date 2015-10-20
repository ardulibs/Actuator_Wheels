/*
 * ActuatorWheels
 * Version 0.1.0 May, 2015
 * Copyright 2015 Diego de los Reyes
 *
 * Basic wheels control.
 */

#include "ActuatorWheels.h"

   
/** CONSTRUCTORS **/

/**
 * Construct.
 */
ActuatorWheels::ActuatorWheels()
{
}

/** PUBLIC METHODS **/

/**
 * Attach the given pins.
 * @param pinLeft: pin where the left servo is connected.
 * @param pinRight: pin where the right servo is connected.
 */
void ActuatorWheels::attach(int pinLeft, int pinRight)
{
	right_servo.attach(pinRight);
	left_servo.attach(pinLeft);
}

/**
 * Starts moving fordward.
 */
void ActuatorWheels::moveFordward(int velocity)
{
	right_servo.write(stop_position-velocity);
	left_servo.write(stop_position-velocity);
}

/**
 * Starts moving backward.
 */
void ActuatorWheels::moveBackward(int velocity)
{
	right_servo.write(stop_position+velocity);
	left_servo.write(stop_position+velocity);
}

/**
 * Rotates left.
 */
void ActuatorWheels::rotateClockwise(int velocity)
{
	right_servo.write(stop_position);
	left_servo.write(stop_position-velocity);
}

/**
 * Rotates Right.
 */
void ActuatorWheels::rotateCounterclockwise(int velocity)
{
	right_servo.write(stop_position-velocity);
	left_servo.write(stop_position);
}

/**
 * Stops moving.
 */
void ActuatorWheels::stopAdvance()
{
	right_servo.write(stop_position);
	left_servo.write(stop_position);
}