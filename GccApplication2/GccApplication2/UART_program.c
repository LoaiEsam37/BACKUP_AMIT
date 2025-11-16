#include "UART_interface.h"
#include "UART_register.h"

void UART_voidInit(void)
{
	/* Set baud rate */
	UBRRL = 51;                // 9600 baud @ 8MHz

	/* UCSRC setup: URSEL must be 1 when writing */
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);   // 8-bit data, 1 stop bit, no parity

	/* Enable TX and RX */
	UCSRB = (1 << TXEN) | (1 << RXEN);
}

void UART_voidTXChar(u8 copy_u8Data)
{
	/* Wait until transmit buffer is empty */
	while ((UCSRA & (1 << UDRE)) == 0);

	/* Put data into buffer */
	UDR = copy_u8Data;
}

void UART_charRXChar(u8* pu8Data)
{
	if (pu8Data == 0)
	return;

	/* Wait until data is received */
	while ((UCSRA & (1 << RXC)) == 0);

	/* Read received data */
	*pu8Data = UDR;
}
