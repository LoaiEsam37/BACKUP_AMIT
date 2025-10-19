/*
 * TMR1_private.h
 *
 * Created: 10/16/2025 8:28:47 PM
 * Author: Loaie
 */

#ifndef TMR1_PRIVATE_H_
#define TMR1_PRIVATE_H_

/*--------------------------------------------------------
 *  TIMER1 MODES
 *--------------------------------------------------------*/
#define TMR1_NORMAL_MODE   0
#define TMR1_CTC_MODE      1

/*--------------------------------------------------------
 *  TIMER1 REGISTER BITS (for reference)
 *--------------------------------------------------------*/
/*
WGM13:WGM12:WGM11:WGM10 bits define mode:
------------------------------------------
0000 ? Normal Mode
0100 ? CTC Mode (TOP = OCR1A)
1110 ? Fast PWM (TOP = ICR1)
1111 ? Fast PWM (TOP = OCR1A)
*/

#endif /* TMR1_PRIVATE_H_ */
