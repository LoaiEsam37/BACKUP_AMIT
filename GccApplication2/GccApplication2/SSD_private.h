/*
 * SSD_private.h
 *
 * Created: 9/16/2025 5:15:20 PM
 *  Author: loaie
 */ 


#ifndef SSD_PRIVATE_H_
#define SSD_PRIVATE_H_


#define SSD_ZERO   0b00111111
#define SSD_ONE    0b00000110
#define SSD_TWO    0b01011011
#define SSD_THREE  0b01001111
#define SSD_FOUR   0b01100110
#define SSD_FIVE   0b01101101
#define SSD_SIX    0b01111101
#define SSD_SEVEN  0b00000111
#define SSD_EIGHT  0b01111111
#define SSD_NINE   0b01101111

static const u8 PRV_u8Number[10] =
{
	SSD_ZERO,
	SSD_ONE,
	SSD_TWO,
	SSD_THREE,
	SSD_FOUR,
	SSD_FIVE,
	SSD_SIX,
	SSD_SEVEN,
	SSD_EIGHT,
	SSD_NINE
};


#endif /* SSD_PRIVATE_H_ */