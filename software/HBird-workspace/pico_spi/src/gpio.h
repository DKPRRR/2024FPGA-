/*
 * gpio.h
 *
 *  Created on: 2024年11月7日
 *      Author: admin
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdio.h>

#define gpio_out_0_address 			(*(volatile uint32_t*)0x00008020)
#define gpio_in_0_address 			(*(volatile uint32_t*)0x00008030)
#define gpio_out_1_address 			(*(volatile uint32_t*)0x00008040)
#define gpio_in_1_address 			(*(volatile uint32_t*)0x00008050)

#define set_0   0x01
#define set_1   0x02
#define set_2   0x04
#define set_3   0x08
#define set_4   0x10
#define set_5   0x20
#define set_6   0x40
#define set_7   0x80

#define set_8	0x0100
#define set_9	0x0200
#define set_10	0x0400
#define set_11	0x0800
#define set_12	0x1000
#define set_13	0x2000
#define set_14	0x4000
#define set_15	0x8000

#define set_16  0x010000
#define set_17  0x020000
#define set_18  0x040000
#define set_19  0x080000
#define set_20  0x100000
#define set_21  0x200000
#define set_22  0x400000
#define set_23  0x800000

#define set_24  0x01000000
#define set_25  0x02000000
#define set_26  0x04000000
#define set_27  0x08000000
#define set_28  0x10000000
#define set_29  0x20000000
#define set_30  0x40000000
#define set_31  0x80000000

#define clr_0   0xFE
#define clr_1   0xFD
#define clr_2   0xFB
#define clr_3   0xF7
#define clr_4   0xEF
#define clr_5   0xDF
#define clr_6   0xBF
#define clr_7   0x7F

#define clr_8	0xFEFF
#define clr_9	0xFDFF
#define clr_10  0xFBFF
#define clr_11  0xF7FF
#define clr_12  0xEFFF
#define clr_13  0xDFFF
#define clr_14  0xBFFF
#define clr_15  0x7FFF

#define clr_8	0xFEFF
#define clr_9	0xFDFF
#define clr_10  0xFBFF
#define clr_11  0xF7FF
#define clr_12  0xEFFF
#define clr_13  0xDFFF
#define clr_14  0xBFFF
#define clr_15  0x7FFF

#define clr_8	0xFEFF
#define clr_9	0xFDFF
#define clr_10  0xFBFF
#define clr_11  0xF7FF
#define clr_12  0xEFFF
#define clr_13  0xDFFF
#define clr_14  0xBFFF
#define clr_15  0x7FFF

#define clr_16	0xFEFFFF
#define clr_17	0xFDFFFF
#define clr_18	0xFBFFFF
#define clr_19	0xF7FFFF
#define clr_20	0xEFFFFF
#define clr_21	0xDFFFFF
#define clr_22	0xBFFFFF
#define clr_23	0x7FFFFF

#define clr_24	0xFEFFFFFF
#define clr_25	0xFDFFFFFF
#define clr_26	0xFBFFFFFF
#define clr_27	0xF7FFFFFF
#define clr_28	0xEFFFFFFF
#define clr_29	0xDFFFFFFF
#define clr_30	0xBFFFFFFF
#define clr_31	0x7FFFFFFF

////////////////////////屏幕接口////////////////////////////
#define SPI_SCK_0  gpio_out_0_address &= clr_0        //GPIO_OUT0
#define SPI_SCK_1  gpio_out_0_address |= set_0
#define SPI_SDA_0  gpio_out_0_address &= clr_1        //GPIO_OUT1
#define SPI_SDA_1  gpio_out_0_address |= set_1
#define SPI_RST_0  gpio_out_0_address &= clr_2        //GPIO_OUT2
#define SPI_RST_1  gpio_out_0_address |= set_2
#define SPI_DC_0   gpio_out_0_address &= clr_3           //GPIO_OUT3
#define SPI_DC_1   gpio_out_0_address |= set_3
#define SPI_CS_0   gpio_out_0_address &= clr_4          //GPIO_OUT4
#define SPI_CS_1   gpio_out_0_address |= set_4
#define BL_0       gpio_out_0_address &= clr_5          //GPIO_OUT5//H 有效,背光控制
#define BL_1       gpio_out_0_address |= set_5
////////////////////////示波器数据接口///////////////////////////////////
#define FIFO_CLK_0  gpio_out_0_address &= clr_6        //GPIO_OUT6
#define FIFO_CLK_1  gpio_out_0_address |= set_6

#define FIFO_DATA	(uint8_t)(gpio_in_1_address & 0x0000000F)
////////////////////////逻辑分析仪数据接口///////////////////////////////////
#define RAM_CLK_0  gpio_out_0_address &= clr_6        //GPIO_OUT6
#define RAM_CLK_1  gpio_out_0_address |= set_6

#define RAM_DATA	(uint8_t)(gpio_in_1_address & 0x0000000F)

#define RAM_ADDR0_0 gpio_out_0_address &= clr_7
#define RAM_ADDR0_1 gpio_out_0_address |= set_7

#define RAM_ADDR1_0 gpio_out_0_address &= clr_8
#define RAM_ADDR1_1 gpio_out_0_address |= set_8

#define RAM_ADDR2_0 gpio_out_0_address &= clr_9
#define RAM_ADDR2_1 gpio_out_0_address |= set_9

#define RAM_ADDR3_0 gpio_out_0_address &= clr_10
#define RAM_ADDR3_1 gpio_out_0_address |= set_10

#define RAM_ADDR4_0 gpio_out_0_address &= clr_11
#define RAM_ADDR4_1 gpio_out_0_address |= set_11

#define RAM_ADDR5_0 gpio_out_0_address &= clr_12
#define RAM_ADDR5_1 gpio_out_0_address |= set_12

#define RAM_ADDR6_0 gpio_out_0_address &= clr_13
#define RAM_ADDR6_1 gpio_out_0_address |= set_13

#define RAM_ADDR7_0 gpio_out_0_address &= clr_14
#define RAM_ADDR7_1 gpio_out_0_address |= set_14

#define RAM_ADDR8_0 gpio_out_0_address &= clr_15
#define RAM_ADDR8_1 gpio_out_0_address |= set_15

#define RAM_ADDR9_0 gpio_out_0_address &= clr_16
#define RAM_ADDR9_1 gpio_out_0_address |= set_16

////////////////////////仪器状态信息获取////////////////////////////////

#define INSTRUMENT_MODE         (uint8_t)((gpio_in_1_address & 0x00000003) >> 0)

#define OSP_DISPLAY_MODE        (uint8_t)((gpio_in_1_address & 0x0000000C) >> 2)
#define OSP_AMPLITUDE_RATIO     (uint8_t)((gpio_in_1_address & 0x000000F0) >> 4)
#define OSP_SAMPLE_RATE         (uint8_t)((gpio_in_1_address & 0x00000F00) >> 8)

#define LOGIC_DISPLAY_MODE      (uint8_t)((gpio_in_1_address & 0x00003000) >> 12)
#define LOGIC_TRIGGER_MODE      (uint8_t)((gpio_in_1_address & 0x0001C000) >> 14)
#define LOGIC_TRIGGER_CHANNEL   (uint8_t)((gpio_in_1_address & 0x001E0000) >> 17)

#define DDS_WAVE_CTRL           (uint8_t)((gpio_in_1_address & 0x00600000) >> 21)
#define DDS_FREQ_CTRL           (uint8_t)((gpio_in_1_address & 0x07800000) >> 23)
#define DDS_APD_CTRL            (uint8_t)((gpio_in_1_address & 0x78000000) >> 27)


#endif /* GPIO_H_ */
