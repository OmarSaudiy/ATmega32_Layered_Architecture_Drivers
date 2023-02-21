   /*****************************************************************
    *[FILE NAME] 	: SPI_prog.c									*
    *																*
    *[AUTHOR(S)]    : OmarAhmed										*
    *																*
    *[DATE CREATED] : Oct 13, 2022									*
    * 																*
    *[DECRIPTION]   :  												*
   	*****************************************************************/


#include "std_types.h"
#include "common_macros.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
#include "GPIO_interface.h"


void SPI_init(SPI_Config * ptr){
	SPCR = ((ptr->SPI_Polling_Or_Intrrupt)<<7);
	SIT_BIT(SPCR,6);
	SPCR = ((SPCR) & 0xEF) | ((ptr->SPI_Slave_Or_Master)<<4);
	if((ptr->SPI_Slave_Or_Master) ==SPI_MASTER){
		GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_INPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);
	}
	else if((ptr->SPI_Slave_Or_Master) ==SPI_SLAVE){
		GPIO_setupPinDirection(PORTB_ID,PIN4_ID,PIN_INPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_INPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_OUTPUT);
		GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_INPUT);
	}
	else{
		/*RETURN ERROR*/
	}
	SPCR = ((SPCR) & 0xF3) | (((ptr->CLK_POLARITY_PHASE) & 0x03) <<2);
	SPCR = ((SPCR) & 0xFC) | (((ptr->SPI_Freqency) & 0x03));
	SPSR = ((SPSR) & 0xFE) | (((ptr->SPI_Freqency) & 0x04));
}

uint8 SPI_sendReceiveByte(uint8 const data){
	SPDR = data;
	while(BIT_IS_CLEAR(SPSR,7));
	return SPDR;
}

void SPI_sendString(const uint8 *str)
{
	uint8 i = 0;
	uint8 received_data = 0;
	while(str[i] != '\0'){
		received_data = SPI_sendReceiveByte(str[i]);
		i++;
	}
}

void SPI_receiveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = SPI_sendReceiveByte(DUMMY_DATA);
	while(str[i] != '#'){
		i++;
		str[i] = SPI_sendReceiveByte(DUMMY_DATA);
	}
	str[i] = '\0';
}
