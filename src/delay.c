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
//���ú���2΢�� �˳�2΢�� i-- 1΢��
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


