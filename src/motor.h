#ifndef __MOTOR_H__
#define __MOTOR_H__
#define uint unsigned int
#define LEFT 1
#define RIGHT 2
#define CSPIN 0
#define CCSPIN 3
//void __motor_forBackWord(uint dir, uint time);

void motor_reset();

void motor_forword();

void motor_backword();

void motor_turn(uint x);


#endif