#include <reg52.h>
#include "led.h"
#include "delay.h"


sbit LED_0 = P1 ^ 0;
sbit LED_1 = P1 ^ 1;
sbit LED_2 = P1 ^ 2;
sbit LED_3 = P1 ^ 3;
sbit LED_4 = P1 ^ 4;
sbit LED_5 = P1 ^ 5;
sbit LED_6 = P1 ^ 6;
sbit LED_7 = P1 ^ 7;



void led_Ctrl(int Led_id, int OnOff)
{
	int LedOnOff;
	if (OnOff == LED_ON)
	{
		LedOnOff = LED_ON;
	}
	else
	{
		LedOnOff = LED_OFF;
	}
	switch (Led_id)
	{
	case LED_D1:
		LED_0 = LedOnOff;
		break;
	case LED_D2:
		LED_1 = LedOnOff;
		break;
	case LED_D3:
		LED_2 = LedOnOff;
		break;
	case LED_D4:
		LED_3 = LedOnOff;
		break;
	case LED_D5:
		LED_4 = LedOnOff;
		break;
	case LED_D6:
		LED_5 = LedOnOff;
		break;
	case LED_D7:
		LED_6 = LedOnOff;
		break;
	case LED_D8:
		LED_7 = LedOnOff;
		break;
	}
}

void led_flow(uint times, uint last)
{
	uint t = 0x01, i, k;
	uint tt = 1;
	for (k = 0 ; k < times ; ++ k)
	{
		tt = -tt;
		for (i = 0; i < 8; ++i)
		{
			if (tt == 1)
			{
				P1 = ~(t << i);
				Delay_ms(last); 
			}
			else
			{
				P1 = ~(t << (7 - i));
				Delay_ms(last); 
			}
		}
	}
}

void led_on()
{
	P1 = 0x00;
}

void led_off()
{
	P1 = 0xff;
}

void led_flashing(uint times)
{
	uint i;
	for (i = 0; i < times; ++i)
	{
		led_on();
		Delay_ms(20);
		led_off();
		Delay_ms(20);
	}
}
