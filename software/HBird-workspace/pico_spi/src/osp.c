#include "osp.h"
#include "gpio.h"
unsigned char OSP_READ(){

	unsigned char temp_data;
	temp_data = gpio_in_0_address;


	FIFO_CLK_0;
	FIFO_CLK_1;

	return temp_data;
}

