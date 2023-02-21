   /*****************************************************************
    *[FILE NAME] 	: SPI_private.h									*
    *																*
    *[AUTHOR(S)]    : OmarAhmed										*
    *																*
    *[DATE CREATED] : Oct 13, 2022									*
    * 																*
    *[DECRIPTION]   :  												*
   	*****************************************************************/

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SPDR (*(volatile uint8 * const)0x2F)
#define SPSR (*(volatile uint8 * const)0x2E)
#define SPCR (*(volatile uint8 * const)0x2D)

#endif /* SPI_PRIVATE_H_ */
