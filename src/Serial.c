#include <reg52.h>
#include "Serial.h"

uchar Serial_Data; 

void Serial_Init()
{
	//定时器设置        提供波特率
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TH1 = 0xfd;		//初值计算 9600 = (2的SMOD次方/32)*(T1溢出率) = (1/32)*(11059200/(256-X)*12)
	TL1 = 0xfd;
	TR1 = 1;
	//Serial 设置
	SCON = 0x50;	  //工作方式1，波特率9600bps，允许接收
	PCON &= ~0x80;		//波特率不加倍
	EA = 1;//总中断
	ES = 1;//串口中断
}
void Serial_SendMsg(unsigned char Msg)
{
	ES = 0;//关闭串口中断 
	SBUF = Msg;
	while(0 == TI);//等待数据传输完成
	//恢复中断
	TI = 0;
	ES = 1;
	
}

void Serial_GetMsg() interrupt 4
{
	RI = 0;
	Serial_Data = SBUF;
}










