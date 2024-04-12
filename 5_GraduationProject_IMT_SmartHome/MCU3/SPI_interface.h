/*
 * SPI_interface.h
 *
 *  Created on: Sep 17, 2019
 *      Author: Z.50
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


void SPI_Void_Init();


u8 SPI_U8_Master_TransRecieve(u8 copy_U8TranmitedByte , u8 * copy_pu8RecievedByte);

void SPI_Void_SlaveSendByte(u8 copy_U8TranmitedByte);

u8 SPI_U8_RecieveByte(u8 * copy_pu8RecievedByte);

#endif /* SPI_INTERFACE_H_ */
