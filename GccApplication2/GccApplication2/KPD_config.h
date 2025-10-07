/*
 * KPD_config.h
 *
 * Created: 9/28/2025 7:18:20 PM
 *  Author: loaie
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_ROW_PORT     DIO_PORTA
#define KPD_ROW0_PIN     DIO_PIN1
#define KPD_ROW1_PIN     DIO_PIN2
#define KPD_ROW2_PIN     DIO_PIN3

#define KPD_COL_PORT     DIO_PORTD
#define KPD_COL0_PIN     DIO_PIN2
#define KPD_COL1_PIN     DIO_PIN3
#define KPD_COL2_PIN     DIO_PIN7

#define KPD_KEYS   { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} }

#endif /* KPD_CONFIG_H_ */