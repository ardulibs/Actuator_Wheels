/*
 * RobotWheels
 * Version 0.1 May, 2015
 * Copyright 2015 Diego de los Reyes
 *
 * Basic wheels control.
 */

#include "RobotWheels.h"

   
/** CONSTRUCTORES **/

/**
 * Construct.
 */
RobotWheels::RobotWheels()
{
}

/** PUBLIC METHODS **/

/**
 * Attach the given pins.
 * @param pinLeft: pin where the left servo is connected.
 * @param pinRight: pin where the right servo is connected.
 */
void attach(int pinLeft, int pinRight)
{
	right_servo.attach(pinRight);
	left_servo.attach(pinLeft);
}

/**
 * Starts moving fordward.
 */
void moveFordward(int velocity)
{
	right_servo.write(stop_position+velocity);
	left_servo.write(stop_position+velocity);
}

/**
 * Starts moving backward.
 */
void moveBackward(int velocity)
{
	right_servo.write(stop_position-velocity);
	left_servo.write(stop_position-velocity);
}

/**
 * Rotates left.
 */
void rotateClockwise(int velocity)
{
	right_servo.write(stop_position);
	left_servo.write(stop_position+velocity);
}

/**
 * Rotates Right.
 */
void rotateCounterclockwise(int velocity)
{
	right_servo.write(stop_position+rotate_velocity);
	left_servo.write(stop_position);
}

/**
 * Stops moving.
 */
void stopAdvance()
{
	right_servo.write(stop_position);
	left_servo.write(stop_position);
}