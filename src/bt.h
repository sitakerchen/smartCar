#ifndef __BT_H__
#define __BT_H__
#include <reg52.h>
#define uchar unsigned char
#define uint unsigned int
#define BTFORWORD   1
#define BTBACWORD   2
#define BTLEFT		3
#define BTRIGHT     4
#define BTSTOP		5
#define BTSPUP		6
#define BTSPDW		7
#define BTEXIT		8
#define BT_LEFT_SPIN  9
#define BT_RIGHT_SPIN 0


int bt_move();


void bt_ctrl();


#endif