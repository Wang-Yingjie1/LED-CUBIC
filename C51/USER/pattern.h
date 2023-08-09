#ifndef _PATTERN_H_
#define _PATTERN_H_


#define INIT 				1
#define MIE					1
#define FLOOR_FALL	        0
#define SIDE_MOVE	        0
#define	HEART				0
#define STAR				0
#define LITGHT_1_BY_1		0
#define TURN_OFF_1_BY_1	    0
#define	FIREWORKS		    0
#define CUBIC               1

#include "bsp_ledcubic.h"
#include <stdlib.h>

extern u8 time_count;

void init(u8 timecount);	//È«ÁÁ
void mie(u8 timecount);		//È«Ãð
void floor_fall(u8 timecount);	//Ò»²ã½µÂä
void side_move(u8 sel, u8 timecount);	//²à±ßÒÆ¶¯1
void Heart(u8 sel, u8 timecount);
void Star(void);
void light_1_by_1(u8 timecount);
void turn_off_1_by_1(u8 timecount);
void fireworks(u8 timecount);
void Cubic(u8 timecount);
#endif