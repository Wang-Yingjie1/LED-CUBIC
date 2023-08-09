#include <reg52.h>
#include "bsp_ledcubic.h"
#include "pattern.h"

u8 time_count = 0x00;

int main(void)
{
	u8 display_count = 0;
	TMOD = 0x01;	//��ʱ��0Ϊ������ʽ1��16λ����
	TH0 = (65536-10000)/256;	//50ms��ʱ
	TL0 = (65536-10000)%256;
	EA = 1; //���ж�
	ET0 = 1; //��ʱ��0�ж�
	TR0 = 1; //������ʱ��0
	
	while(1)
	{
		#if INIT
			init(100);
		#endif
		
		#if FLOOR_FALL
			floor_fall(10);
		#endif

		#if SIDE_MOVE
			side_move(0,5);
			side_move(1,5);
			side_move(2,5);
			side_move(3,5);
		#endif

		#if HEART
			Heart(0,30);
			Heart(1,30);
		#endif

		#if STAR
			Star();
		#endif
		
		#if MIE
			mie(100);
		#endif
		
		#if LITGHT_1_BY_1
			light_1_by_1(1);
		#endif
		
		#if TURN_OFF_1_BY_1
			turn_off_1_by_1(1);
		#endif
		
		#if FIREWORKS
			fireworks(10);
		#endif

		#if CUBIC
			Cubic(5);
		#endif
	}

}

void T0_time() interrupt 1
{	
	//����װ�س�ֵ
	TL0 = 240; //(65536-10000)%256;
	TH0 = 216; //(65536-10000)/256;	//10ms��ʱ
	time_count--;
}