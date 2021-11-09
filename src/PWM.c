#include<reg52.h>
#include "PWM.h"
#include "bt.h"
#define TH0_TL0 (65536-1000)//设定中断的间隔时长
unsigned char count0 = 50;//低电平的占空比
unsigned char count1 = 0;//高电平的占空比

unsigned char count0_turn = 50; // 转弯低电平占空比
unsigned char count1_turn = 0; // 转弯高电平占空比

int flag = BTSTOP;

sbit Key_add = P3 ^ 3; //电机减速
sbit Key_dec = P3 ^ 4; //电机加速

//B: left wheel
sbit PWM1 = P0 ^ 0;//PWM 通道 1，反转脉冲 counter clockwise
sbit PWM2 = P0 ^ 1;//PWM 通道 2，正转脉冲 clock wise

//A: right wheel
sbit PWM3 = P0 ^ 2;//PWM 通道 3，反转脉冲 counter clockwise
sbit PWM4 = P0 ^ 3;//PWM 通道 4，正转脉冲 clock wise

unsigned char Time_delay;


/****************延时处理**********************/
void Delay(unsigned char x)
{
	Time_delay = x;
	while (Time_delay != 0);//等待中断，可减少PWM输出时间间隔
}

/*******按键处理加pwm占空比，电机加速**********/
void Motor_speed_high(void)
{
	if (Key_add == 0)
	{
		Delay(10);
		if (Key_add == 0)
		{
			count0 += 5;

			if (count0 >= 100)
			{
				count0 = 100;
			}
		}
		while (!Key_add);//等待键松开
	}
}

/******按键处理减pwm占空比，电机减速*****/
void Motor_speed_low(void)
{
	if (Key_dec == 0)
	{
		Delay(10);
		if (Key_dec == 0)
		{
			count0 -= 5;

			if (count0 <= 0)
			{
				count0 = 0;
			}
		}
		while (!Key_dec);
	}
}

/*******bluetooth处理加pwm占空比，电机加速**********/
void Motor_speed_add(void)
{

	count0 += 5;

	if (count0 >= 100)
	{
		count0 = 100;
	}

}

/*******bluetooth处理加pwm占空比，电机减速**********/
void Motor_speed_minus(void)
{
	count0 -= 5;

	if (count0 <= 10)	//	count0 is uchar type the which can't be negative, if set to 0 may result in out of control
	{
		count0 = 10;
	}
}



/***********定时器0初始化***********/
void Timer0_init(void)
{
	TMOD = 0x01; //定时器0工作于方式1
	TH0 = TH0_TL0 / 256;
	TL0 = TH0_TL0 % 256;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
}

/**************定时0中断处理******************/
void Timer0_int(void) interrupt 1 using 1
{
	TR0 = 0;//设置定时器初值期间，关闭定时器
	TL0 = TH0_TL0 % 256;
	TH0 = TH0_TL0 / 256;//定时器装初值
	TR0 = 1;

	if (Time_delay != 0)//延时函数用
	{
		Time_delay--;
	}

	if (flag == BTFORWORD)//电机正转
	{
		PWM1 = 0;
		PWM4 = 0;

		if (++count1 < count0)
		{
			PWM2 = 1;
			PWM3 = 1;
		}
		else
		{
			PWM2 = 0;
			PWM3 = 0;
		}
		if (count1 >= 100)
		{
			count1 = 0;
		}
	}
	else if (flag == BTLEFT) //  turn left
	{
		PWM4 = 0;
		PWM1 = PWM2 = 1;

		if (++count1 < count0)
		{
			PWM3 = 1;
		}
		else
		{
			PWM3 = 0;
		}
		if (count1 >= 100)
		{
			count1 = 0;
		}
	}
	else if (flag == BTRIGHT) // turn right
	{
		PWM1 = 0;
		PWM3 = PWM4 = 0;

		if (++count1 < count0)
		{
			PWM2 = 1;
		}
		else
		{
			PWM2 = 0;
		}
		if (count1 >= 100)
		{
			count1 = 0;
		}
	}
	else if (flag == BTBACWORD)
	{
		PWM2 = 0;
		PWM3 = 0;

		if (++count1 < count0)
		{
			PWM1 = 1;
			PWM4 = 1;
		}
		else
		{
			PWM1 = 0;
			PWM4 = 0;
		}
		if (count1 >= 100)
		{
			count1 = 0;
		}
	}
	else if (flag == BT_LEFT_SPIN)
	{
		PWM2 = 0; // left
		PWM4 = 0; // right

		if (++count1 < count0)
		{
			PWM1 = 1;
			PWM3 = 1;
		}
		else
		{
			PWM1 = 0;
			PWM3 = 0;
		}
		if (count1 >= 100)
		{
			count1 = 0;
		}
	}
	else if (flag == BT_RIGHT_SPIN)
	{
		PWM1 = 0;
		PWM3 = 0;

		if (++count1 < count0)
		{
			PWM2 = 1;
			PWM4 = 1;
		}
		else
		{
			PWM2 = 0;
			PWM4 = 0;
		}
		if (count1 >= 100)
		{
			count1 = 0;
		}
	}
	else if (flag == BTSTOP)
	{
		PWM1 = PWM2 = PWM3 = PWM4 = 1;
	}
}