/*
 * main.c
 *
 *  Created on: Feb 3, 2024
 *      Author: Administrator
 */
#include"Master1.h"

void main(void)
{
	Init_Master();


	while(1)
	{
		recieve_order();
	}
}
