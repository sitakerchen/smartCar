#include <reg52.h>
#include "delay.h"
#include "led.h"
#include "motor.h"
#include "track.h"
#include "PWM.h"
#include "Serial.h"
#include "bt.h"
#define uint unsigned int
#define TIME 2000
// 2k ms == 2 s

sbit B2A = P0 ^ 0; // B wheel 2A port
sbit B1A = P0 ^ 1; // B wheel 1A port
sbit A1A = P0 ^ 2; // A wheel 1A port
sbit A1B = P0 ^ 3; // A wheel 1B port

int main()
{
	Timer0_init();
	Serial_Init();
	while (1)
	{
		bt_ctrl();
	}
	return 0;
}