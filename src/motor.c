#include <reg52.h>
#include "motor.h"
#include "delay.h"

sbit B2A = P0 ^ 0; // B wheel 2A port
sbit B1A = P0 ^ 1; // B wheel 1A port
sbit A1A = P0 ^ 2; // A wheel 1A port
sbit A1B = P0 ^ 3; // A wheel 1B port

void motor_reset()
{
	A1A = A1B = B1A = B2A = 1;
}

void motor_forword()
{
	A1A = 1;
	A1B = 0;
	B1A = 1;
	B2A = 0;
}

void motor_backword()
{
	A1A = 0;
	A1B = 1;
	B1A = 0;
	B2A = 1;
}


void motor_turn(uint x)
{
	switch (x)
	{
	case 0: // clockwise spin
		A1A = B2A = 0;
		A1B = B1A = 1;
		break;
	case 1: // left
		A1A = 1;
		B2A = 1;
		B1A = 1;
		A1B = 0;
		break;
	case 2:	// right
		B1A = 1;
		A1B = 1;
		A1A = 1;
		B2A = 0;
		break;
	case 3:	// counter clockwise spin
		A1A = B2A = 1;
		A1B = B1A = 0;
		break;
	default:
		break;
	}
}