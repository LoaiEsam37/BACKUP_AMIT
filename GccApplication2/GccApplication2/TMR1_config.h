/*
 * TMR1_config.h
 *
 * Created: 10/16/2025 8:29:06 PM
 * Author: Loaie
 */

#ifndef TMR1_CONFIG_H_
#define TMR1_CONFIG_H_

/*--------------------------------------------------------
 *  NORMAL MODE CONFIGURATION
 *--------------------------------------------------------*/
#define TMR1_PRELOAD_VALUE        60720
#define TMR1_OVERFLOW_COUNTER     19

/*--------------------------------------------------------
 *  CTC MODE CONFIGURATION
 *--------------------------------------------------------*/
#define TMR1_COMPARE_MATCH_VALUE  62499   // for 1 second at 16MHz, prescaler=256
#define TMR1_CTC_COUNTER          3       // 3 * 1s = 3 seconds

/*--------------------------------------------------------
 *  SELECT TIMER1 MODE
 *--------------------------------------------------------*/
#define TMR1_MODE   TMR1_CTC_MODE   // or TMR1_NORMAL_MODE

#endif /* TMR1_CONFIG_H_ */
