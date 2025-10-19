/*
 * TMR0_config.h
 *
 * Created: 10/16/2025 6:46:09 PM
 * Author: Loaie
 */

#ifndef TMR0_CONFIG_H_
#define TMR0_CONFIG_H_

/*--------------------------------------------------------
 *  TIMER0 MODE SELECTION
 *  Options:
 *     1- TMR0_NORMAL_MODE
 *     2- TMR0_CTC_MODE
 *--------------------------------------------------------*/
// #define TMR0_MODE                TMR0_NORMAL_MODE	// Uncomment to use Normal mode
#define TMR0_MODE             TMR0_CTC_MODE   // Uncomment to use CTC mode

/*--------------------------------------------------------
 *  NORMAL MODE CONFIGURATION
 *--------------------------------------------------------*/
#define TMR0_PRELOAD_VALUE       112
#define TMR0_OVERFLOW_COUNTER    977

/*--------------------------------------------------------
 *  CTC MODE CONFIGURATION
 *--------------------------------------------------------*/
#define TMR0_COMPARE_MATCH_VALUE 125   // adjust for your timing (0–255)
#define TMR0_CTC_COUNTER         1000  // optional counter for CTC if needed

#endif /* TMR0_CONFIG_H_ */
