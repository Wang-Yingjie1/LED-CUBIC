#include "bsp_ledcubic.h"

void delay_us(unsigned int t)
{
	while(--t);
}

static u8 bit_revert(u8 rowdata)
{
	u8 result = 0x00;
	u8 temp;
	
	temp = 0x01 & rowdata;	result = result | (temp<<7);
	temp = 0x02 & rowdata;	result = result | (temp<<5);
	temp = 0x04 & rowdata;	result = result | (temp<<3);
	temp = 0x08 & rowdata;	result = result | (temp<<1);
	temp = 0x10 & rowdata;	result = result | (temp>>1);
	temp = 0x20 & rowdata;	result = result | (temp>>3);
	temp = 0x40 & rowdata;	result = result | (temp>>5);
	temp = 0x80 & rowdata;	result = result | (temp>>7);
	
	return result;
}
// 将一层的显示数据送入到74HC574中锁存
void display_floor(u8* p, u8 floor)
{
	u8 rowdata;
	MOS = 0x00;//关闭所有LED灯
	OE = 1;
	CLK = 0x00; //拉低74HC574的时钟
	// 将每一行的数据锁存至8个74HC574中
	DATA = (u8)*p;	CLK0 = 1;		p++;
	DATA = (u8)*p;	CLK1 = 1;		p++;
	DATA = (u8)*p;	CLK2 = 1;		p++;
	DATA = (u8)*p;	CLK3 = 1;		p++;
	DATA = (u8)*p;	CLK4 = 1;		p++;
	// 硬件中线序取反了
	#if revert
		rowdata = (u8)*p;	DATA = bit_revert(rowdata);		CLK5 = 1;		p++;
		rowdata = (u8)*p;	DATA = bit_revert(rowdata);		CLK6 = 1;		p++;
		rowdata = (u8)*p;	DATA = bit_revert(rowdata);		CLK7 = 1;		p++;
	#else
		DATA = (u8)*p;	CLK5 = 1;		p++;
		DATA = (u8)*p;	CLK6 = 1;		p++;
		DATA = (u8)*p;	CLK7 = 1;
	#endif
	
	OE = 0;		//使能输出
	MOS = (0x01<<floor); //将一层点亮
}

void Display(u8* imag)
{
		u8 floor = 0; //表示层数
		u8* p = imag;
		for(floor = 0; floor < 8; floor++)
		{
			display_floor(&(imag[floor<<3]),floor);
		}
}

// x,y,z ~ [0,7]
void Draw_point(u8 x, u8 y, u8 z, u8 clear)
{
	u8 x_bit = 0x01<<x;

	MOS = 0x00;//关闭所有LED灯
	OE = 0;

	if(clear)
	{
		// 将其他的都锁存0
		DATA = 0x00;
		CLK = 0x00;
		CLK = 0xff;
	}
	#if revert
			if(y >= 5)
				DATA = bit_revert(x_bit);
			else
				DATA = x_bit;
	#else
			DATA = x_bit;
	#endif
	switch(y)
	{
		case 0: CLK0 = 0; CLK0 = 1;break;
		case 1: CLK1 = 0; CLK1 = 1;break;
		case 2: CLK2 = 0; CLK2 = 1;break;
		case 3: CLK3 = 0; CLK3 = 1;break;
		case 4: CLK4 = 0; CLK4 = 1;break;
		case 5: CLK5 = 0; CLK5 = 1;break;
		case 6: CLK6 = 0; CLK6 = 1;break;
		case 7: CLK7 = 0; CLK7 = 1;break;
		default: break;
	}
	
	MOS = (0x01<<z);
}

void Draw_points(u8* x, u8* y, u8* z, u8 points_num)
{
	u8 i;
	for(i = 0; i < points_num; i++)
	{
		Draw_point( *x, *y, *z, CLEAR);
		x++; y++; z++;
	}
}