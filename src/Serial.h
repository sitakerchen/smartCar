#ifndef __SERIAL_H__
#define	__SERIAL_H__
#define uchar unsigned char
/*
*brier:串口初始化
*param:
*return:
*warning:
*/
void Serial_Init();
/*
*brier:发送一个byte的无符号数据
*param:
*return:
*warning:
*/
void Serial_SendMsg(unsigned char Msg);
/*
*brier:串口中断 用于接受串口信息
*param:
*return:
*warning:这只是模板，按需求修改
*funciont:void Serial_GetMsg();
*/

#endif