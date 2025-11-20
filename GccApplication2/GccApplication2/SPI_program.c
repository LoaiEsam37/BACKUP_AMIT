/*
 * SPI_program.c
 *
 * Created: 11/20/2025 7:24:15 PM
 *  Author: loaie
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_config.h"

#include "DIO_interface.h"     // because SPI pins must be configured
                               // MOSI, MISO, SCK, SS
                               
/***********************************
 *        MASTER INIT
 ***********************************/
void SPI_voidInitMaster(void)
{
    /* Set Master pins direction */
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);  // SS
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);  // MOSI
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);  // SCK
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);   // MISO

    /* Enable SPI */
    SET_BIT(SPCR, SPCR_SPE);

    /* Master mode */
    SET_BIT(SPCR, SPCR_MSTR);

    /* Clock polarity */
#if SPI_CLOCK_POLARITY == 1
    SET_BIT(SPCR, SPCR_CPOL);
#else
    CLR_BIT(SPCR, SPCR_CPOL);
#endif

    /* Clock phase */
#if SPI_CLOCK_PHASE == 1
    SET_BIT(SPCR, SPCR_CPHA);
#else
    CLR_BIT(SPCR, SPCR_CPHA);
#endif

    /* Clock rate selection */
#if SPI_CLOCK_RATE == 0
    CLR_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
#elif SPI_CLOCK_RATE == 1
    SET_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
#elif SPI_CLOCK_RATE == 2
    CLR_BIT(SPCR, SPCR_SPR0);
    SET_BIT(SPCR, SPCR_SPR1);
#elif SPI_CLOCK_RATE == 3
    SET_BIT(SPCR, SPCR_SPR0);
    SET_BIT(SPCR, SPCR_SPR1);
#endif
}

/***********************************
 *        SLAVE INIT
 ***********************************/
void SPI_voidInitSlave(void)
{
    /* Set Slave pins direction */
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);   // SS
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);   // MOSI
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);   // SCK
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);  // MISO

    /* Enable SPI */
    SET_BIT(SPCR, SPCR_SPE);

    /* Slave mode (MSTR = 0) */
    CLR_BIT(SPCR, SPCR_MSTR);
}

/***********************************
 *        SEND & RECEIVE
 ***********************************/
void SPI_voidTransceive(u8 copy_u8Data, u8* pu8ReceivedData)
{
    SPDR = copy_u8Data;  // Load data into SPI shift register

    /* Wait for transmission complete */
    while(GET_BIT(SPSR, SPSR_SPIF) == 0);

    if(pu8ReceivedData != NULL)
        *pu8ReceivedData = SPDR;
}
