#ifndef __LED_H__
#define __LED_H__
#define uint unsigned int

//LED onOff
#define LED_ON 0
#define LED_OFF 1

//LED±àºÅ
#define LED_D1 1
#define LED_D2 2
#define LED_D3 3
#define LED_D4 4
#define LED_D5 5
#define LED_D6 6
#define LED_D7 7
#define LED_D8 8

/*
*brief:
*param: times(how many times per run), speed(the last time of each time /ms)
*
*/
void led_flow(uint times, uint speed); 

void led_on();

void led_off();

void led_flashing(uint times);

void led_Ctrl(int Led_id, int OnOff);

#endif