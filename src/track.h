#ifndef __TRACK_H__
#define __TRACK_H__
#define uint unsigned int
#define uchar unsigned char
#define IN1_DETECTED 1
#define IN3_DETECTED 2
#define ALL_DETECTED 3
#define NOT_DETECTED 4
#define BLACK 1
#define WHITE 0
// WHITE exist object
// BLACK not exist object

uint track_detect();

int track_auto();


#endif // !__TRACK_H__
