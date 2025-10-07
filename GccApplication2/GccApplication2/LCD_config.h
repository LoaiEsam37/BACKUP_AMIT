/*
 * LCD_config.h
 *
 * Created: 9/18/2025 7:58:17 PM
 *  Author: loaie
 */ 

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* -------- Environment Selection -------- */
#define ENV_SIMULATION      0
#define ENV_AVR             1

/* -------- Choose Current Environment -------- */
#define ENV                 ENV_AVR

#if ENV == ENV_SIMULATION

    #define LCD_RS_PORT     DIO_PORTC
    #define LCD_RS_PIN      DIO_PIN6

    #define LCD_D0_PORT     DIO_PORTD
    #define LCD_D1_PORT     DIO_PORTD
    #define LCD_D2_PORT     DIO_PORTD
    #define LCD_D3_PORT     DIO_PORTD
    #define LCD_D4_PORT     DIO_PORTD
    #define LCD_D5_PORT     DIO_PORTD
    #define LCD_D6_PORT     DIO_PORTD
    #define LCD_D7_PORT     DIO_PORTD

    #define LCD_D0          DIO_PIN0
    #define LCD_D1          DIO_PIN1
    #define LCD_D2          DIO_PIN2
    #define LCD_D3          DIO_PIN3
    #define LCD_D4          DIO_PIN4
    #define LCD_D5          DIO_PIN5
    #define LCD_D6          DIO_PIN6
    #define LCD_D7          DIO_PIN7

    #define LCD_E_PORT      DIO_PORTC
    #define LCD_E_PIN       DIO_PIN7

#elif ENV == ENV_AVR

    #define LCD_RS_PORT     DIO_PORTB
    #define LCD_RS_PIN      DIO_PIN1

    #define LCD_D4_PORT     DIO_PORTA
    #define LCD_D5_PORT     DIO_PORTA
    #define LCD_D6_PORT     DIO_PORTA
    #define LCD_D7_PORT     DIO_PORTA

    #define LCD_D4          DIO_PIN4
    #define LCD_D5          DIO_PIN5
    #define LCD_D6          DIO_PIN6
    #define LCD_D7          DIO_PIN7

    #define LCD_E_PORT      DIO_PORTB
    #define LCD_E_PIN       DIO_PIN2

#endif

/* -------- LCD Mode Selection -------- */
#define LCD_MODE            LCD_FOUR_BIT_MODE
// #define LCD_MODE         LCD_EIGHT_BIT_MODE   // Uncomment if using 8-bit

#endif /* LCD_CONFIG_H_ */
