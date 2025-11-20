/*
 * SPI_config.h
 *
 * Created: 11/20/2025 7:25:20 PM
 *  Author: loaie
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/* Clock Polarity: 0 or 1 */
#define SPI_CLOCK_POLARITY   0    // 0 = Idle Low, 1 = Idle High

/* Clock Phase */
#define SPI_CLOCK_PHASE      0    // 0 = Read first, 1 = Write first

/* Clock Rate (for Master): Choose one
 * 0 -> Fosc/4
 * 1 -> Fosc/16
 * 2 -> Fosc/64
 * 3 -> Fosc/128
 */
#define SPI_CLOCK_RATE       1

#endif /* SPI_CONFIG_H_ */