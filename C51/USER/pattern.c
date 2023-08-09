#include "pattern.h"
#include <stdlib.h>
//æ¯æ?¡è¿è¡Œå®Œä¹‹åè®°å¾—å°†RAMé‡ç½®ä¸? 0x00
u8 RAM[64] = 
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#if INIT
void init(u8 timecount)
{
	u8 index;
	for(index = 0; index < 64; index++)
	{
		RAM[index] = 0xff;
	}
//	u8 code Init_array[64] = 
//	{
//	//ç¬?ä¸€è¡?-----------------------------------ç¬?å…?è¡?
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,//ç¬?ä¸€å±?
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
//	};
	time_count = timecount;
	while(time_count)		Display(RAM);
	
	for(index = 0; index < 64; index++)	RAM[index] = 0x00;
}
#endif


#if MIE
void mie(u8 timecount)
{
//	u8 code mie[64] = 
//	{
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//	};
	time_count = timecount;
	while(time_count)		Display(RAM);
}
#endif

#if FLOOR_FALL
void floor_fall(u8 timecount)
{
	u8 floor;
	u8 index, i;
	for(floor = 0; floor < 8; floor++)
	{
		for(i = 0; i < 8; i++)
		{
			index = floor<<3 + i;
			RAM[index] = 0xff;
		}
		time_count = timecount;
		while(time_count)	Display(RAM);
		for(i = 0; i < 8; i++)
		{
			index = floor<<3 + i;
			RAM[index] = 0x00;
		}
	}
}
#endif

#if SIDE_MOVE
void side_move(u8 sel, u8 timecount)
{
	u8 index, column, floor, x_bit, i;
	
	if(sel == 0)
	{
		for(column = 0; column < 8; column++)	//µÚÒ»ÁĞ
		{
			for(floor = 0; floor < 8; floor++)
			{
				index = floor*8 + column;
				RAM[index] = 0xff;
			}
			time_count = timecount;
			while(time_count)	Display(RAM);
			for(floor = 0; floor < 8; floor++)
			{
				index = floor*8 + column;
				RAM[index] = 0x00;
			}
		}
	}
	if(sel == 2)
	{
		for(column = 0; column < 8; column++)	//µÚÒ»ÁĞ
		{
			for(floor = 0; floor < 8; floor++)
			{
				index = floor*8 +7 - column;
				RAM[index] = 0xff;
			}
			time_count = timecount;
			while(time_count)	Display(RAM);
			for(floor = 0; floor < 8; floor++)
			{
				index = floor*8 + 7 - column;
				RAM[index] = 0x00;
			}
		}
	}
	if(sel == 1)
	{
		for(i = 0; i < 8; i++)
		{
			x_bit = 0x01 << i;
			for(index = 0; index < 64; index++)	RAM[index] = x_bit;
			time_count = timecount;
			while(time_count)	Display(RAM);
			for(index = 0; index < 64; index++)	RAM[index] = 0x00;
		}

	}
	if(sel == 3)
	{
		for(i = 0; i < 8; i++)
		{
			x_bit = 0x01 << (7-i);
			for(index = 0; index < 64; index++)	RAM[index] = x_bit;
			time_count = timecount;
			while(time_count)	Display(RAM);
			for(index = 0; index < 64; index++)	RAM[index] = 0x00;
		}
	}
}
#endif

// #if SIDE_MOVE2
// void side_move2(u8 sel, u8 timecount)
// {
// 	u8 code side_move2_0[64] =
// 	{
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
// 		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
// 	};
// 	u8 code side_move2_1[64] =
// 	{
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
// 		0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02
// 	};
// 	u8 code side_move2_2[64] =
// 	{
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
// 		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04
// 	};
// 	u8 code side_move2_3[64] =
// 	{
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
// 		0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
// 	};
// 	u8 code side_move2_4[64] =
// 	{
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
// 		0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10
// 	};
// 	u8 code side_move2_5[64] =
// 	{
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
// 		0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
// 	};
// 	u8 code side_move2_6[64] =
// 	{
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
// 		0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40
// 	};
// 	u8 code side_move2_7[64] =
// 	{
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
// 		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80
// 	};
	
// 	u8 TIME_COUNT = timecount;
	
// 	if(sel == 1)
// 	{
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_0);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_1);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_2);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_3);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_4);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_5);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_6);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_7);
// 	}
// 	if(sel == 0)
// 	{
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_7);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_6);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_5);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_4);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_3);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_2);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_1);
// 		time_count = TIME_COUNT;
// 		while(time_count)		Display(side_move2_0);
// 	}
// }
// #endif

#if HEART
void Heart(u8 sel, u8 timecount)
{
	u8 code cubic0[64] = 
	{
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0, 24, 24,  0,  0,  0,
		0,  0,  0, 24, 24,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0
	};
	
	u8 code cubic1[64] = 
	{
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0, 60, 60, 60, 60,  0,  0,
		0,  0, 60, 36, 36, 60,  0,  0,
		0,  0, 60, 36, 36, 60,  0,  0,
		0,  0, 60, 60, 60, 60,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0,
		0,  0,  0,  0,  0,  0,  0,  0
	};

	u8 code cubic2[64] = 
	{
		0,  0,  0,  0,  0,  0,  0,  0,
		0,126,126,126,126,126,126,  0,
		0,126, 66, 66, 66, 66,126,  0,
		0,126, 66, 66, 66, 66,126,  0,
		0,126, 66, 66, 66, 66,126,  0,
		0,126, 66, 66, 66, 66,126,  0,
		0,126,126,126,126,126,126,  0,
		0,  0,  0,  0,  0,  0,  0,  0
	};
	
	u8 code cubic3[64] = 
	{
		255,255,255,255,255,255,255,255,
		255,129,129,129,129,129,129,255,
		255,129,129,129,129,129,129,255,
		255,129,129,129,129,129,129,255,
		255,129,129,129,129,129,129,255,
		255,129,129,129,129,129,129,255,
		255,129,129,129,129,129,129,255,
		255,255,255,255,255,255,255,255,
	};
	
	u8 TIME_COUNT = timecount;
	if(sel == 0)
	{
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic0);
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic1);
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic2);
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic3);
	}
	if(sel == 1)
	{
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic3);
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic2);
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic1);
		time_count = TIME_COUNT;
		while(time_count)		Display(cubic0);
	}
}
#endif

#if STAR
void Star(void)
{
	u8 star_count, star_num, STAR_NUM;
	u8 pos_x, pos_y, pos_z, index;
	u8 x_bit;
	u8 opcode;
	u8 temp;

	for(star_count = 1; star_count > 0; star_count--)
	{
		for(index = 0; index < 64; index++)	RAM[index] = 0x00;
		// ä¸€æ¬¡åœºæ™?æ•?
		STAR_NUM = rand() % 50 + 20;
		for(star_num = 0; star_num < STAR_NUM; star_num++)
		{
			pos_x = rand() % 8;
			pos_y = rand() % 8;
			pos_z = rand() % 8;
			x_bit = 0x01 << pos_x;
			index = pos_y + pos_z * 8;
			RAM[index] |= x_bit;
		}
		temp = 100;
		while(temp--)
		{
			time_count = rand()%5+8;
			while(time_count)  Display(RAM);
			//time_count = rand()%4;
			opcode = temp % 4;
			for(index = 0; index < 64; index++)
			{
				switch(opcode)
				{
					case 0:	RAM[index] ^= temp; break;
					case 1: RAM[index] |= temp; break;
					case 2: RAM[index] += temp; break;
					case 3: RAM[index] -= temp; break;
				}
				
			}
		}
		
	}
	
}
#endif

#if LITGHT_1_BY_1 || TURN_OFF_1_BY_1
u8 code random[256] = 
{
	60, 75, 101, 68, 63, 5, 226, 208, 211, 49, 222, 254, 11, 40, 31, 137, 10, 244,
	20, 55, 154, 129, 140, 253, 164, 215, 138, 184, 162, 235, 34, 202, 81, 86, 78,
	130, 67, 189, 248, 192, 77, 243, 176, 28, 163, 252, 188, 38, 139, 229, 4, 83, 198,
	167, 247, 134, 16, 39, 52, 44, 127, 221, 9, 85, 42, 242, 146, 0, 214, 29, 239,
	117, 212, 100, 236, 15, 114, 178, 87, 1, 2, 3, 17, 6, 7, 8, 48, 121, 14, 12, 18,
	19, 231, 21, 22, 23, 24, 25, 26, 27, 159, 109, 33, 35, 36, 37, 108, 41, 110, 32,
	183, 96, 46, 47, 50, 51, 53, 54, 56, 190, 58, 59, 62, 64, 65, 66, 61, 69, 92, 93,
	72, 73, 74, 13, 91, 193, 79, 80, 98, 123, 161, 71, 90, 76, 70, 89, 94, 95, 106,
	97, 99, 124, 102, 103, 104, 105, 133, 107, 30, 112, 115, 143, 230, 120, 232, 122, 82, 207, 
	126, 186, 128, 131, 132, 191, 196, 135, 136, 168, 141, 142, 177, 240, 145, 147,
	233, 149, 150, 151, 152, 153, 155, 156, 157, 160, 223, 165, 166, 57, 210, 169, 170, 171, 172, 173, 174, 
	175, 111, 179, 180, 182, 43, 113, 185, 209, 250, 88, 194, 195, 197, 199, 200, 158, 203, 204, 205, 206,
	187, 125, 213, 216, 217, 218, 219, 220, 84, 224, 181, 227, 228, 118, 201, 148, 234,
	144, 237, 238, 225, 241, 45, 245, 246, 249, 119, 251, 116, 255
};

#endif

#if LITGHT_1_BY_1
void light_1_by_1(u8 timecount)
{
	u8 pos_x, pos_y, pos_z, rand,index;
	u8 x_bit;
	u16 count;
	for(count = 0; count < 256; count++)
	{
		//ä¸Šä¸‹åŠåŒºåˆ?
			rand = random[count];
			pos_x = rand & 0x07;	//0b0000_0111
			pos_y = (rand & 0x38)>>3;	//0b0011_1000
			pos_z = (rand & 0xc0)>>6;	//0b1100_0000
			x_bit = 0x01<<pos_x;
			index = pos_y + pos_z * 8;
			RAM[index] |= x_bit;
			time_count = timecount;
			while(time_count)	Display(RAM);

			rand = random[255-count];
			pos_x = rand & 0x07;	//0b0000_0111
			pos_y = (rand & 0x38)>>3;	//0b0011_1000
			pos_z = (rand & 0xc0)>>6;	//0b1100_0000
			x_bit = 0x01<<pos_x;
			index = pos_y + pos_z * 8 + 32;
			RAM[index] |= x_bit;
			time_count = timecount;
			while(time_count)	Display(RAM);
	}
	//			while(1) Display(RAM);
	#if !TURN_OFF_1_BY_1
		for(count = 0; count < 64; count++)	RAM[count] = 0x00;
	#endif
}
#endif

#if TURN_OFF_1_BY_1
void turn_off_1_by_1(u8 timecount)
{
	u8 pos_x, pos_y, pos_z, rand,index;
	u8 x_bit;
	u16 count;
	for(count = 0; count < 256; count++)
	{
		//ä¸Šä¸‹åŠåŒºåˆ?
			rand = random[count];
			pos_x = rand & 0x07;	//0b0000_0111
			pos_y = (rand & 0x38)>>3;	//0b0011_1000
			pos_z = (rand & 0xc0)>>6;	//0b1100_0000
			x_bit = ~(0x01 << pos_x);
			index = pos_y + pos_z * 8 + 32;
			RAM[index] &= x_bit;
			time_count = timecount;
			while(time_count)	Display(RAM);

			rand = random[255-count];
			pos_x = rand & 0x07;	//0b0000_0111
			pos_y = (rand & 0x38)>>3;	//0b0011_1000
			pos_z = (rand & 0xc0)>>6;	//0b1100_0000
			x_bit = ~(0x01 << pos_x);
			index = pos_y + pos_z * 8;
			RAM[index] &= x_bit;
			time_count = timecount;
			while(time_count)	Display(RAM);
	}
	for(count = 0; count < 64; count++)	RAM[count] = 0x00;
}
#endif

#if FIREWORKS
void fireworks(u8 timecount)
{
	u8 pos_x, pos_y, pos_z, count;
	u8 x_arr[9], y_arr[9], z_arr[9];
	for(count = 0; count < 30; count++)
	{
		pos_x = rand() % 8;
		pos_y = rand() % 8;
		
		x_arr[0] = pos_x; x_arr[1] = pos_x; x_arr[2] = pos_x; x_arr[3] = pos_x-1; x_arr[4] = pos_x+1;
		x_arr[5] = pos_x; x_arr[6] = pos_x; x_arr[7] = pos_x+2; x_arr[8] = pos_x-2;
		
		y_arr[0] = pos_y; y_arr[1] = pos_y+1; y_arr[2] = pos_y-1; y_arr[3] = pos_y; y_arr[4] = pos_y;
		y_arr[5] = pos_y+2; y_arr[6] = pos_y-2; y_arr[7] = pos_y; y_arr[8] = pos_y;
		
		z_arr[0] = 0; z_arr[1] = 0;	z_arr[2] = 0; z_arr[3] = 0; z_arr[4] = 0; z_arr[5] = 0;
		z_arr[6] = 1; z_arr[7] = 1; z_arr[8] = 1; z_arr[9] = 1;
		
		for(pos_z = 0; pos_z < 10; pos_z++)
		{
			time_count = timecount;
			while(time_count){ 
				if(pos_z >= 7) //æœ€é«˜ç‚¹ç»½æ”¾
				{
					switch(pos_z)
					{
						case 7: Draw_points(x_arr, y_arr, z_arr, 1); break;
						case 8: Draw_points(x_arr, y_arr, z_arr, 5); break;
						case 9:	Draw_points(x_arr, y_arr, z_arr, 9); break;
						//default: break;
					}
				
				}
				else
				{
					Draw_point(pos_x,pos_y,7-pos_z, CLEAR); 
				}
			}
		}
	}

}
#endif

#ifdef CUBIC

static void SetPoint(u8 x, u8 y, u8 z)
{
	u8 x_bit, index;
	x_bit = 0x01<<x;
	index = y + z * 8;
	RAM[index] |= x_bit;
}

static void CubicCal(u8 length, u8 mode)
{
	u8 x,y,z;
	u8 temp = 0;

	for(x = 0; x < length; x++)
	{
		for(y = 0; y < length; y++)
		{
			for(z = 0; z < length; z++)
			{
				temp = 0;
				if(x == 0 || x == length-1)	temp++;
				if(y == 0 || y == length-1) temp++;
				if(z == 0 || z == length-1) temp++;
				if(temp > 1)
				{
					switch (mode)
					{
					case 0:
						SetPoint(x,y,z);
						break;
					case 1:
						SetPoint(7-x,y,z);
						break;
					case 2:
						SetPoint(x,7-y,z);
						break;
					case 3:
						SetPoint(7-x,7-y,z);
						break;
					case 4:
						SetPoint(x,y,7-z);
						break;
					case 5:
						SetPoint(7-x,y,7-z);
						break;
					case 6:
						SetPoint(x,7-y,7-z);
						break;
					case 7:
						SetPoint(7-x,7-y,7-z);
						break;
					default:
						break;
					}
				}	
			}
		}
	}
}

void Cubic(u8 timecount)
{
	u8 side; //±ß³¤
	u8 index;
	u8 i;

	for(i = 0; i < 8; i++)
	{
		for(side = 1; side <= 8; side++)
		{
			CubicCal(side,i);
			time_count = timecount;
			while(time_count) Display(RAM);
			MOS = 0x00;
			for(index = 0; index < 64; index++)	RAM[index] = 0x00;
		}
		for(side = 7; side >0; side--)
		{
			CubicCal(side,i);
			time_count = timecount;
			while(time_count) Display(RAM);
			MOS = 0x00;
			for(index = 0; index < 64; index++)	RAM[index] = 0x00;
		}
	}
}
#endif