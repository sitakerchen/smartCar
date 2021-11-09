#include<reg52.h>
#include "PWM.h"
#include "bt.h"
#define TH0_TL0 (65536-1000)//�趨�жϵļ��ʱ��
unsigned char count0 = 50;//�͵�ƽ��ռ�ձ�
unsigned char count1 = 0;//�ߵ�ƽ��ռ�ձ�

unsigned char count0_turn = 50; // ת��͵�ƽռ�ձ�
unsigned char count1_turn = 0; // ת��ߵ�ƽռ�ձ�

int flag = BTSTOP;

sbit Key_add = P3 ^ 3; //�������
sbit Key_dec = P3 ^ 4; //�������

//B: left wheel
sbit PWM1 = P0 ^ 0;//PWM ͨ�� 1����ת���� counter clockwise
sbit PWM2 = P0 ^ 1;//PWM ͨ�� 2����ת���� clock wise

//A: right wheel
sbit PWM3 = P0 ^ 2;//PWM ͨ�� 3����ת���� counter clockwise
sbit PWM4 = P0 ^ 3;//PWM ͨ�� 4����ת���� clock wise

unsigned char Time_delay;


/****************��ʱ����**********************/
void Delay(unsigned char x)
{
	Time_delay = x;
	while (Time_delay != 0);//�ȴ��жϣ��ɼ���PWM���ʱ����
}

/*******���������pwmռ�ձȣ��������**********/
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
		while (!Key_add);//�ȴ����ɿ�
	}
}

/******���������pwmռ�ձȣ��������*****/
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

/*******bluetooth�����pwmռ�ձȣ��������**********/
void Motor_speed_add(void)
{

	count0 += 5;

	if (count0 >= 100)
	{
		count0 = 100;
	}

}

/*******bluetooth�����pwmռ�ձȣ��������**********/
void Motor_speed_minus(void)
{
	count0 -= 5;

	if (count0 <= 10)	//	count0 is uchar type the which can't be negative, if set to 0 may result in out of control
	{
		count0 = 10;
	}
}



/***********��ʱ��0��ʼ��***********/
void Timer0_init(void)
{
	TMOD = 0x01; //��ʱ��0�����ڷ�ʽ1
	TH0 = TH0_TL0 / 256;
	TL0 = TH0_TL0 % 256;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
}

/**************��ʱ0�жϴ���******************/
void Timer0_int(void) interrupt 1 using 1
{
	TR0 = 0;//���ö�ʱ����ֵ�ڼ䣬�رն�ʱ��
	TL0 = TH0_TL0 % 256;
	TH0 = TH0_TL0 / 256;//��ʱ��װ��ֵ
	TR0 = 1;

	if (Time_delay != 0)//��ʱ������
	{
		Time_delay--;
	}

	if (flag == BTFORWORD)//�����ת
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