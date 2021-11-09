#include "bt.h"
#include "motor.h"
#include "PWM.h"
#include "track.h"
#include "led.h"

extern uchar Serial_Data;
extern int flag;


int bt_move()
{
	uchar order;
	while (1)
	{
		order = Serial_Data;
		if (order == BTFORWORD)
		{
			flag = BTFORWORD;
		}
		else if (order == BTLEFT)
		{
			flag = BTLEFT;
		}
		else if (order == BTRIGHT)
		{
			flag = BTRIGHT;
		}
		else if (order == BTSTOP)
		{
			flag = BTSTOP;
		}
		else if (order == BTSPUP)
		{
			Motor_speed_add();
			while (order == BTSPUP) order = Serial_Data; // 取消连点
		}
		else if (order == BTSPDW)
		{
			Motor_speed_minus();
			while (order == BTSPDW) order = Serial_Data; // 取消连点
		}
		else if (order == BTBACWORD)
		{
			flag = BTBACWORD;
		}
		else if (order == BTEXIT)
		{
			return 0;
		}
		else if (order == BT_LEFT_SPIN)
		{
			flag = BT_LEFT_SPIN;
		}
		else if (order == BT_RIGHT_SPIN)
		{
			flag = BT_RIGHT_SPIN;
		}
	}
}

void bt_ctrl()
{
	uchar order;
	while (1)
	{
		order = Serial_Data;
		if (order == 1)
		{
			led_off();
			bt_move();
		}
		else if (order == 2)
		{
			led_off();
			track_auto();
		}
		led_on();
	}
}