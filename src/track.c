#include <reg52.h>
#include "track.h"
#include "motor.h"
#include "delay.h"
#include "PWM.h"
#include "Serial.h"
#include "led.h"
#include "bt.h"

sbit in1 = P2 ^ 1;	// left
sbit in3 = P2 ^ 3;	// right

extern int flag;
extern int Serial_Data;

uint track_detect()
{
	if (in1 == 0 && in3 == 1) return IN1_DETECTED;
	else if (in1 == 1 && in3 == 0) return IN3_DETECTED;
	else if (in1 == 0 && in3 == 0) return ALL_DETECTED;
	else if (in1 == 1 && in3 == 1) return NOT_DETECTED;
	return -1;
}


int track_auto()
{
	int signal;
	while (1)
	{
		signal = Serial_Data;
		if (signal == BTEXIT)
		{
			return 0;	// �˳��Զ�Ѱ��
		}

		if (in1 == WHITE && in3 == WHITE)
		{
			//motor_forword();
			flag = BTFORWORD;
			//if (Serial_Data == BTEXIT) return 0;
		}
		else if (in1 == BLACK && in3 == WHITE)
		{
			//flag = BTRIGHT;
			flag = BT_RIGHT_SPIN;
			//if (Serial_Data == BTEXIT) return 0;
			//motor_turn(RIGHT);
		}
		else if (in1 == WHITE && in3 == BLACK)
		{
			//flag = BTLEFT;
			flag = BT_LEFT_SPIN;
			//if (Serial_Data == BTEXIT) return 0;
			//motor_turn(LEFT);
		}
		else
		{
			flag = BTSTOP;
			//if (Serial_Data == BTEXIT) return 0;
			//motor_reset();
		}
	}
		
}