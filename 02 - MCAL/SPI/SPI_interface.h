   /*****************************************************************
    *[FILE NAME] 	: SPI_interface.h								*
    *																*
    *[AUTHOR(S)]    : OmarAhmed										*
    *																*
    *[DATE CREATED] : Oct 13, 2022									*
    * 																*
    *[DECRIPTION]   :  												*
   	*****************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "std_types.h"
/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

#define DUMMY_DATA 0xFF
typedef enum{
	POLLING,INTRRUPT
}SPI_Polling_Or_Intrrupt;

typedef enum{
	SPI_SLAVE,SPI_MASTER
}SPI_Slave_Or_Master;

typedef enum{
	RISING_EDGE_HIGH,RISING_EDGE_LOW,FALLING_EDGE_LOW,FALLING_EDGE_HIGH
}CLK_POLARITY_PHASE;

typedef enum{
	CLK_DIV_4,CLK_DIV_16,CLK_DIV_64,CLK_DIV_128,CLK_DIV_2,CLK_DIV_8,CLK_DIV_32
}SPI_Freqency;

typedef struct{
	SPI_Polling_Or_Intrrupt SPI_Polling_Or_Intrrupt;
	SPI_Slave_Or_Master SPI_Slave_Or_Master;
	CLK_POLARITY_PHASE CLK_POLARITY_PHASE;
	SPI_Freqency SPI_Freqency;
}SPI_Config;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void SPI_init(SPI_Config * ptr);

uint8 SPI_sendReceiveByte(uint8 const data);

void SPI_sendString(const uint8 *str);

void SPI_receiveString(uint8 *str);

#endif /* SPI_INTERFACE_H_ */
