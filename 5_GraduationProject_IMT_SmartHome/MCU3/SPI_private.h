/*
 * SPI_private.h
 *
 *  Created on: Sep 17, 2019
 *      Author: Z.50
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPI_U8_SPCR 	 *((volatile u8*)0x2D)
#define SPI_U8_SPSR 	 *((volatile u8*)0x2E)
#define SPI_U8_SPDR 	 *((volatile u8*)0x2F)


#define SPI_u8_Master_Mode  0
#define SPI_u8_Slave_Mode   1
#endif /* SPI_PRIVATE_H_ */
