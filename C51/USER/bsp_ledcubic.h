#ifndef _BSP_LEDCUBIC_H_
#define _BSP_LEDCUBIC_H_

#include <reg52.h>
#define u8 unsigned char
#define u16 unsigned int
#define revert 	1		//硬件线序是否取反了
// Draw_points();
#define CLEAR		1
#define REMAIN	0

sfr  CLK	= 0x80;		//即P0
sfr  DATA = 0x90;		//即P1，表示一行的数据
sfr	 MOS 	= 0xA0;		//即P2

// 74HC574的时钟信号，上升沿有效
sbit CLK0 = CLK^0;
sbit CLK1 = CLK^1;
sbit CLK2 = CLK^2;
sbit CLK3 = CLK^3;
sbit CLK4 = CLK^4;
sbit CLK5 = CLK^5;
sbit CLK6 = CLK^6;
sbit CLK7 = CLK^7;

sbit MOS0 = MOS^0;
sbit MOS1 = MOS^1;
sbit MOS2 = MOS^2;
sbit MOS3 = MOS^3;
sbit MOS4 = MOS^4;
sbit MOS5 = MOS^5;
sbit MOS6 = MOS^6;
sbit MOS7 = MOS^7;

sbit OE = P3^5;			//74HC574的输出使能，低电平有效，无效时输出高阻
void display_floor(u8* p, u8 floor);
void Display(u8* imag);
void delay_us(unsigned int t);
void Draw_point(u8 x, u8 y, u8 z, u8 clear);
void Draw_points(u8* x, u8* y, u8* z, u8 points_num);

#endif