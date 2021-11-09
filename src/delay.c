#include <reg52.h>
#include "delay.h"

void Delay_ms(int time)
{
    int i = 0;
	int fix = One_MS_Cycle * 2.0 / 3.0;
    while(time--)
    {
        for(i = 0;i < fix;i ++);
    }
}
//µ÷ÓÃº¯Êý2Î¢Ãë ÍË³ö2Î¢Ãë i-- 1Î¢Ãë
void Delay_10us()
{
	int i;
	i--;
	i--;
	i--;
	i--;
	i--;
	i--;
}


