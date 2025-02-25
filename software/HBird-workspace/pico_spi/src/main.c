#include "uart.h"
#include "gpio.h"
#include "gmt024_spi.h"
#include "osp.h"



#define SYSTEM_CNT_M			125										//????�统时钟单位：MHz
#define SYSTEM_CLOCK			SYSTEM_CNT_M*1000000UL
#define BAUND_9600				((SYSTEM_CLOCK)/9600)
#define BAUND_115200			(SYSTEM_CLOCK/115200)
#define GPIO_DATA				0xaa55
#define LED_DELAY				5000000UL

unsigned char temp_data = 0;

///////////SPI��Ļ
//GPIO_OUT0--SCK   ,  GPIO_OUT1--SDA   ,  GPIO_OUT2--RES  ,   GPIO_OUT3--DC  ,  GPIO_OUT4--CS    ,  GPIO_OUT5--BLK   ,

///////////OSPʾ��????
//GPIO_IN0-7--FIFO_Data
//GPIO_OUT6--FIFO_Trigger

///////////���͸���λ������ʾ��Ļģʽѡ��
//GPIO_OUT7--MODE0 ,  GPIO_OUT8--MODE1
//
int main(void)
{
	uint8_t clear_flag = 99;
	IO_init();
	SPI_SCK_0;
	TFT_init();
	BL_1;
	TFT_full(WHITE);

	FIFO_CLK_0;
	FIFO_CLK_1;
	while(1)
	{
		switch(INSTRUMENT_MODE)
		{
			case 0://CLOSE
				if(clear_flag != 0){
					TFT_full(WHITE);
					//��Яʽ�๦������
					display_char16_16(100+16*0,212-16*0 ,RED,0);
					display_char16_16(100+16*0,212-16*1 ,RED,1);
					display_char16_16(100+16*0,212-16*2 ,RED,2);
					display_char16_16(100+16*0,212-16*3 ,RED,3);
					display_char16_16(100+16*0,212-16*4 ,RED,4);
					display_char16_16(100+16*0,212-16*5 ,RED,5);
					display_char16_16(100+16*0,212-16*6 ,RED,6);
					display_char16_16(100+16*0,212-16*7 ,RED,7);
					//ʾ�������߼������ǣ��źŷ�����
					display_char16_16(100+16*1,260-16*0 ,RED,8 );
					display_char16_16(100+16*1,260-16*1 ,RED,9 );
					display_char16_16(100+16*1,260-16*2 ,RED,10);
					display_char16_16(100+16*1,260-16*3 ,RED,23);//:
					display_char16_16(100+16*1,260-16*4 ,RED,11);
					display_char16_16(100+16*1,260-16*5 ,RED,12);
					display_char16_16(100+16*1,260-16*6 ,RED,13);
					display_char16_16(100+16*1,260-16*7 ,RED,14);
					display_char16_16(100+16*1,260-16*8 ,RED,15);
					display_char16_16(100+16*1,260-16*9 ,RED,23);//:
					display_char16_16(100+16*1,260-16*10,RED,16);
					display_char16_16(100+16*1,260-16*11,RED,17);
					display_char16_16(100+16*1,260-16*12,RED,18);
					display_char16_16(100+16*1,260-16*13,RED,19);
					display_char16_16(100+16*1,260-16*14,RED,20);
					//����һ������ģʽ�л�
					display_char16_16(100+16*2,212-16*0 ,RED,21);
					display_char16_16(100+16*2,212-16*1 ,RED,22);
					display_char16_16(100+16*2,212-16*2 ,RED,26);
					display_char16_16(100+16*2,212-16*3 ,RED,23);//:
					display_char16_16(100+16*2,212-16*4 ,RED,6 );
					display_char16_16(100+16*2,212-16*5 ,RED,7 );
					display_char16_16(100+16*2,212-16*6 ,RED,75);
					display_char16_16(100+16*2,212-16*7 ,RED,76);
					display_char16_16(100+16*2,212-16*8 ,RED,77);
					display_char16_16(100+16*2,212-16*9 ,RED,78);
					clear_flag = 0;
				}
				break;
			case 1://OSP
				switch(OSP_DISPLAY_MODE)
				{
					case 1://SCREEN
						if(clear_flag != 1){
							TFT_full(WHITE);
							clear_flag = 1;
						}
						TFT_show(WHITE, RED);
						break;
					case 2://UPPER_COMPUTER
						if(clear_flag != 2){
							TFT_full(WHITE);
							//OSP
							display_char16_16(80+16*0,200-16*0 ,RED,8 );
							display_char16_16(80+16*0,200-16*1 ,RED,9 );
							display_char16_16(80+16*0,200-16*2 ,RED,10);
							//UPPER_COMPUTER
							display_char16_16(80+16*1,200-16*0 ,RED,37);
							display_char16_16(80+16*1,200-16*1 ,RED,38);
							display_char16_16(80+16*1,200-16*2 ,RED,39);
							display_char16_16(80+16*1,200-16*3 ,RED,75);
							display_char16_16(80+16*1,200-16*4 ,RED,76);
							clear_flag = 2;
						}

						break;
					default:
						if(clear_flag != 3){
							TFT_full(WHITE);
							//OSP
							display_char16_16(80+16*0,200-16*0 ,RED,8 );
							display_char16_16(80+16*0,200-16*1 ,RED,9 );
							display_char16_16(80+16*0,200-16*2 ,RED,10);
							//3
							display_char16_16(80+16*1,200-16*0 ,RED,21);
							display_char16_16(80+16*1,200-16*1 ,RED,22);
							display_char16_16(80+16*1,200-16*2 ,RED,27);
							display_char16_16(80+16*1,200-16*3 ,RED,23);//:
							display_char16_16(80+16*1,200-16*4 ,RED,35);
							display_char16_16(80+16*1,200-16*5 ,RED,36);
							display_char16_16(80+16*1,200-16*6 ,RED,23);//:
							display_char16_16(80+16*1,200-16*7 ,RED,37);
							display_char16_16(80+16*1,200-16*8 ,RED,38);
							display_char16_16(80+16*1,200-16*9 ,RED,39);
							//4
							display_char16_16(80+16*2,200-16*0 ,RED,21);
							display_char16_16(80+16*2,200-16*1 ,RED,22);
							display_char16_16(80+16*2,200-16*2 ,RED,28);
							display_char16_16(80+16*2,200-16*3 ,RED,23);//:
							display_char16_16(80+16*2,200-16*4 ,RED,40);
							display_char16_16(80+16*2,200-16*5 ,RED,41);
							//5
							display_char16_16(80+16*3,200-16*0 ,RED,21);
							display_char16_16(80+16*3,200-16*1 ,RED,22);
							display_char16_16(80+16*3,200-16*2 ,RED,29);
							display_char16_16(80+16*3,200-16*3 ,RED,23);//:
							display_char16_16(80+16*3,200-16*4 ,RED,42);
							display_char16_16(80+16*3,200-16*5 ,RED,43);
							clear_flag = 3;
						}
						break;
				}
				break;
			case 2://LOGIC
				switch(LOGIC_DISPLAY_MODE)
				{
					case 1://SCREEN
							
						break;
					case 2:
						//UPPER_COMPUTER
						if(clear_flag != 4){
							TFT_full(WHITE);
							//LOGIC
							display_char16_16(20+16*0,200-16*0 ,RED,11);
							display_char16_16(20+16*0,200-16*1 ,RED,12);
							display_char16_16(20+16*0,200-16*2 ,RED,13);
							display_char16_16(20+16*0,200-16*3 ,RED,14);
							display_char16_16(20+16*0,200-16*4 ,RED,15);
							//UPPER_COMPUTER
							display_char16_16(20+16*1,200-16*0 ,RED,37);
							display_char16_16(20+16*1,200-16*1 ,RED,38);
							display_char16_16(20+16*1,200-16*2 ,RED,39);
							display_char16_16(20+16*1,200-16*3 ,RED,75);
							display_char16_16(20+16*1,200-16*4 ,RED,76);
							//4
							display_char16_16(20+16*2,200-16*0 ,RED,21);
							display_char16_16(20+16*2,200-16*1 ,RED,22);
							display_char16_16(20+16*2,200-16*2 ,RED,28);
							display_char16_16(20+16*2,200-16*3 ,RED,23);//:
							display_char16_16(20+16*2,200-16*4 ,RED,44);
							display_char16_16(20+16*2,200-16*5 ,RED,45);
							display_char16_16(20+16*2,200-16*6 ,RED,75);
							display_char16_16(20+16*2,200-16*7 ,RED,76);
							display_char16_16(20+16*2,200-16*8 ,RED,77);
							display_char16_16(20+16*2,200-16*9 ,RED,78);
							
							//5
							display_char16_16(20+16*4,200-16*0 ,RED,21);
							display_char16_16(20+16*4,200-16*1 ,RED,22);
							display_char16_16(20+16*4,200-16*2 ,RED,29);
							display_char16_16(20+16*4,200-16*3 ,RED,23);//:
							display_char16_16(20+16*4,200-16*4 ,RED,44);
							display_char16_16(20+16*4,200-16*5 ,RED,45);
							display_char16_16(20+16*4,200-16*6 ,RED,55);
							display_char16_16(20+16*4,200-16*7 ,RED,56);
							display_char16_16(20+16*4,200-16*8 ,RED,77);
							display_char16_16(20+16*4,200-16*9 ,RED,78);
							
							//6
							display_char16_16(20+16*6,200-16*0 ,RED,21);
							display_char16_16(20+16*6,200-16*1 ,RED,22);
							display_char16_16(20+16*6,200-16*2 ,RED,30);
							display_char16_16(20+16*6,200-16*3 ,RED,23);//:
							display_char16_16(20+16*6,200-16*4 ,RED,57);
							display_char16_16(20+16*6,200-16*5 ,RED,58);
							display_char16_16(20+16*6,200-16*6 ,RED,59);
							display_char16_16(20+16*6,200-16*7 ,RED,60);
							display_char16_16(20+16*6,200-16*8 ,RED,44);
							display_char16_16(20+16*6,200-16*9 ,RED,45);
							clear_flag = 4;
						}
						//NOW_MODE
							display_char16_16(20+16*3,250-16*0 ,RED,82);
							display_char16_16(20+16*3,250-16*1 ,RED,83);
							display_char16_16(20+16*3,250-16*2 ,RED,23);//:
							switch(LOGIC_TRIGGER_MODE)
							{
								case 0:
									display_char16_16(20+16*3,250-16*3 ,RED,47);
									display_char16_16(20+16*3,250-16*4 ,RED,48);
									display_char16_16(20+16*3,250-16*5 ,RED,49);
									break;
								case 1:
									display_char16_16(20+16*3,250-16*3 ,RED,46);
									display_char16_16(20+16*3,250-16*4 ,RED,48);
									display_char16_16(20+16*3,250-16*5 ,RED,49);
									break;
								case 2:
									display_char16_16(20+16*3,250-16*3 ,RED,50);
									display_char16_16(20+16*3,250-16*4 ,RED,51);
									display_char16_16(20+16*3,250-16*5 ,RED,54);
									break;
								case 3:
									display_char16_16(20+16*3,250-16*3 ,RED,52);
									display_char16_16(20+16*3,250-16*4 ,RED,53);
									display_char16_16(20+16*3,250-16*5 ,RED,54);
									break;
								case 4:
									display_char16_16(20+16*3,250-16*3 ,RED,50);
									display_char16_16(20+16*3,250-16*4 ,RED,52);
									display_char16_16(20+16*3,250-16*5 ,RED,54);
									break;
								case 5:
									display_char16_16(20+16*3,250-16*3 ,RED,80);
									display_char16_16(20+16*3,250-16*4 ,RED,81);
									display_char16_16(20+16*3,250-16*5 ,RED,44);
									break;
							}
							//NOW_CHANNEL
							display_char16_16(20+16*5,250-16*0 ,RED,82);
							display_char16_16(20+16*5,250-16*1 ,RED,83);
							display_char16_16(20+16*5,250-16*2 ,RED,23);//:
							switch(LOGIC_TRIGGER_CHANNEL)
							{
								case 0:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,25);
									break;
								case 1:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,26);
									break;
								case 2:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,27);
									break;
								case 3:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,28);
									break;
								case 4:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,29);
									break;
								case 5:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,30);
									break;
								case 6:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,31);
									break;
								case 7:
									display_char16_16(20+16*5,250-16*3 ,RED,55);
									display_char16_16(20+16*5,250-16*4 ,RED,56);
									display_char16_16(20+16*5,250-16*5 ,RED,32);
									break;
							}
						break;
					default:
						if(clear_flag != 5){
							TFT_full(WHITE);
							//LOGIC
							display_char16_16(20+16*0,200-16*0 ,RED,11);
							display_char16_16(20+16*0,200-16*1 ,RED,12);
							display_char16_16(20+16*0,200-16*2 ,RED,13);
							display_char16_16(20+16*0,200-16*3 ,RED,14);
							display_char16_16(20+16*0,200-16*4 ,RED,15);
							//3
							display_char16_16(20+16*1,200-16*0 ,RED,21);
							display_char16_16(20+16*1,200-16*1 ,RED,22);
							display_char16_16(20+16*1,200-16*2 ,RED,27);
							display_char16_16(20+16*1,200-16*3 ,RED,23);//:
							display_char16_16(20+16*1,200-16*4 ,RED,35);
							display_char16_16(20+16*1,200-16*5 ,RED,36);
							display_char16_16(20+16*1,200-16*6 ,RED,23);
							display_char16_16(20+16*1,200-16*7 ,RED,37);
							display_char16_16(20+16*1,200-16*8 ,RED,38);
							display_char16_16(20+16*1,200-16*9 ,RED,39);
							//4
							display_char16_16(20+16*2,200-16*0 ,RED,21);
							display_char16_16(20+16*2,200-16*1 ,RED,22);
							display_char16_16(20+16*2,200-16*2 ,RED,28);
							display_char16_16(20+16*2,200-16*3 ,RED,23);//:
							display_char16_16(20+16*2,200-16*4 ,RED,44);
							display_char16_16(20+16*2,200-16*5 ,RED,45);
							display_char16_16(20+16*2,200-16*6 ,RED,75);
							display_char16_16(20+16*2,200-16*7 ,RED,76);
							display_char16_16(20+16*2,200-16*8 ,RED,77);
							display_char16_16(20+16*2,200-16*9 ,RED,78);
							//MODE1
							display_char16_16(20+16*3,250-16*0 ,RED,47);
							display_char16_16(20+16*3,250-16*1 ,RED,48);
							display_char16_16(20+16*3,250-16*2 ,RED,49);
							display_char16_16(20+16*3,250-16*3 ,RED,23);//:
							display_char16_16(20+16*3,250-16*4 ,RED,46);
							display_char16_16(20+16*3,250-16*5 ,RED,48);
							display_char16_16(20+16*3,250-16*6 ,RED,49);
							display_char16_16(20+16*3,250-16*7 ,RED,23);//:
							display_char16_16(20+16*3,250-16*8 ,RED,50);
							display_char16_16(20+16*3,250-16*9 ,RED,51);
							display_char16_16(20+16*3,250-16*10,RED,54);
							//MODE2
							display_char16_16(20+16*4,220-16*0 ,RED,52);
							display_char16_16(20+16*4,220-16*1 ,RED,53);
							display_char16_16(20+16*4,220-16*2 ,RED,54);
							display_char16_16(20+16*4,220-16*3 ,RED,23);//:
							display_char16_16(20+16*4,220-16*4 ,RED,50);
							display_char16_16(20+16*4,220-16*5 ,RED,52);
							display_char16_16(20+16*4,220-16*6 ,RED,54);
							display_char16_16(20+16*4,220-16*7 ,RED,23);//:
							display_char16_16(20+16*4,220-16*8 ,RED,80);
							display_char16_16(20+16*4,220-16*9 ,RED,81);
							//5
							display_char16_16(20+16*5,200-16*0 ,RED,21);
							display_char16_16(20+16*5,200-16*1 ,RED,22);
							display_char16_16(20+16*5,200-16*2 ,RED,29);
							display_char16_16(20+16*5,200-16*3 ,RED,23);//:
							display_char16_16(20+16*5,200-16*4 ,RED,44);
							display_char16_16(20+16*5,200-16*5 ,RED,45);
							display_char16_16(20+16*5,200-16*6 ,RED,55);
							display_char16_16(20+16*5,200-16*7 ,RED,56);
							display_char16_16(20+16*5,200-16*8 ,RED,77);
							display_char16_16(20+16*5,200-16*9 ,RED,78);
							//CHANNEL
							display_char16_16(20+16*6,200-16*0 ,RED,55);
							display_char16_16(20+16*6,200-16*1 ,RED,56);
							display_char16_16(20+16*6,200-16*2 ,RED,25);
							display_char16_16(20+16*6,200-16*3 ,RED,23);//:
							display_char16_16(20+16*6,200-16*4 ,RED,32);
							//6
							display_char16_16(20+16*7,200-16*0 ,RED,21);
							display_char16_16(20+16*7,200-16*1 ,RED,22);
							display_char16_16(20+16*7,200-16*2 ,RED,30);
							display_char16_16(20+16*7,200-16*3 ,RED,23);//:
							display_char16_16(20+16*7,200-16*4 ,RED,57);
							display_char16_16(20+16*7,200-16*5 ,RED,58);
							display_char16_16(20+16*7,200-16*6 ,RED,59);
							display_char16_16(20+16*7,200-16*7 ,RED,60);
							display_char16_16(20+16*7,200-16*8 ,RED,44);
							display_char16_16(20+16*7,200-16*9 ,RED,45);
							clear_flag = 5;
						}
						break;
				}
				break;
			case 3://DDS
				if(clear_flag != 6){
					TFT_full(WHITE);
					//DDS
					display_char16_16(80+16*0,200-16*0 ,RED,16);
					display_char16_16(80+16*0,200-16*1 ,RED,17);
					display_char16_16(80+16*0,200-16*2 ,RED,18);
					display_char16_16(80+16*0,200-16*3 ,RED,19);
					display_char16_16(80+16*0,200-16*4 ,RED,20);
					//3
					display_char16_16(80+16*1,200-16*0 ,RED,21);
					display_char16_16(80+16*1,200-16*1 ,RED,22);
					display_char16_16(80+16*1,200-16*2 ,RED,27);
					display_char16_16(80+16*1,200-16*3 ,RED,23);//:
					display_char16_16(80+16*1,200-16*4 ,RED,77);
					display_char16_16(80+16*1,200-16*5 ,RED,78);
					display_char16_16(80+16*1,200-16*6 ,RED,68);
					display_char16_16(80+16*1,200-16*7 ,RED,79);
					//4
					display_char16_16(80+16*2,200-16*0 ,RED,21);
					display_char16_16(80+16*2,200-16*1 ,RED,22);
					display_char16_16(80+16*2,200-16*2 ,RED,28);
					display_char16_16(80+16*2,200-16*3 ,RED,23);//:
					display_char16_16(80+16*2,200-16*4 ,RED,77);
					display_char16_16(80+16*2,200-16*5 ,RED,78);
					display_char16_16(80+16*2,200-16*6 ,RED,42);
					display_char16_16(80+16*2,200-16*7 ,RED,43);
					//5
					display_char16_16(80+16*3,200-16*0 ,RED,21);
					display_char16_16(80+16*3,200-16*1 ,RED,22);
					display_char16_16(80+16*3,200-16*2 ,RED,29);
					display_char16_16(80+16*3,200-16*3 ,RED,23);//:
					display_char16_16(80+16*3,200-16*4 ,RED,77);
					display_char16_16(80+16*3,200-16*5 ,RED,78);
					display_char16_16(80+16*3,200-16*6 ,RED,40);
					display_char16_16(80+16*3,200-16*7 ,RED,41);
					clear_flag = 6;
				}
				break;
			default:
				break;
		}
//		TFT_show(WHITE, RED);
	}
	return 0;
}






