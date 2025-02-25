/*
 * gmt024_spi.h
 *
 *  Created on: 2024��10��28��
 *      Author: zhangyuhe
 *
 *      ***** GPIO_OUT0  SCK   ,  GPIO_OUT1  SDA   ,  GPIO_OUT2   RES
	          GPIO_OUT3   DC   ,  GPIO_OUT4  CS    ,  GPIO_OUT5  BLK   ,
 */

#ifndef GMT024_SPI_H_
#define GMT024_SPI_H_

#include <stdio.h>
#define gpio_out_address 			(*(volatile uint32_t*)0x00008020)


/**********SPI���ŷ��䣬����oled��������ʵ������޸�*********/

#define     RED          0XF800	  //��ɫ
#define     GREEN        0X07E0	  //��ɫ
#define     BLUE         0X001F	  //��ɫ
#define     WHITE        0XFFFF	  //��ɫ

#define TFT_COLUMN_NUMBER 240
#define TFT_LINE_NUMBER 320
#define TFT_COLUMN_OFFSET 0

#define PIC_NUM 28800			//ͼƬ���ݴ�С


void delay_us(unsigned int _us_time);

void Delay_ms(unsigned int _ms_time);

void SPI_SendByte(unsigned  char byte);

void TFT_SEND_CMD(unsigned char o_command);

void TFT_SEND_DATA(unsigned  char o_data);

void TFT_clear(void);

void TFT_full(unsigned int color);

void TFT_init(void);

void display_char16_16(unsigned int x,unsigned int y,unsigned long color,unsigned char word_serial_number);

void IO_init(void);

void TFT_show(unsigned int color, unsigned int colorn);



#endif /* GMT024_SPI_H_ */
