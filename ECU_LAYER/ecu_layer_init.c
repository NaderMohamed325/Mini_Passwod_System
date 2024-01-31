
/* 
 * File:   ecu_layer_init.c
 * Author: xcite
 *
 * Created on January 6, 2024, 1:13 AM
 */
#include "ecu_layer_init.h"
button_t button = {
    .button_active = BUTTON_ACTVE_HIGH,
    .button_state = BUTTON_RELEASED,
    .pin_config.direction = GPIO_INPUT,
    .pin_config.logic = GPIO_LOW,
    .pin_config.pin = PIN6,
    .pin_config.port = PORTD_INDEX,
};
lcd_4bit_mode lcd = {
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_en.pin = PIN0,
    .lcd_en.port = PORTD_INDEX,

    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_rs.pin = PIN1,
    .lcd_rs.port = PORTD_INDEX,

    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[0].pin = PIN2,
    .lcd_data[0].port = PORTD_INDEX,

    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[1].pin = PIN3,
    .lcd_data[1].port = PORTD_INDEX,

    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[2].pin = PIN4,
    .lcd_data[2].port = PORTD_INDEX,

    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[3].pin = PIN5,
    .lcd_data[3].port = PORTD_INDEX,
};
Keypad_t key = {
    .keypad_col_pins[0].direction = GPIO_INPUT,
    .keypad_col_pins[0].logic = GPIO_LOW,
    .keypad_col_pins[0].pin = PIN4,
    .keypad_col_pins[0].port = PORTC_INDEX,

    .keypad_col_pins[1].direction = GPIO_INPUT,
    .keypad_col_pins[1].logic = GPIO_LOW,
    .keypad_col_pins[1].pin = PIN5,
    .keypad_col_pins[1].port = PORTC_INDEX,

    .keypad_col_pins[2].direction = GPIO_INPUT,
    .keypad_col_pins[2].logic = GPIO_LOW,
    .keypad_col_pins[2].pin = PIN6,
    .keypad_col_pins[2].port = PORTC_INDEX,

    .keypad_col_pins[3].direction = GPIO_INPUT,
    .keypad_col_pins[3].logic = GPIO_LOW,
    .keypad_col_pins[3].pin = PIN7,
    .keypad_col_pins[3].port = PORTC_INDEX,


    .keypad_row_pins[0].direction = GPIO_OUTPUT,
    .keypad_row_pins[0].logic = GPIO_LOW,
    .keypad_row_pins[0].pin = PIN0,
    .keypad_row_pins[0].port = PORTC_INDEX,

    .keypad_row_pins[1].direction = GPIO_OUTPUT,
    .keypad_row_pins[1].logic = GPIO_LOW,
    .keypad_row_pins[1].pin = PIN1,
    .keypad_row_pins[1].port = PORTC_INDEX,

    .keypad_row_pins[2].direction = GPIO_OUTPUT,
    .keypad_row_pins[2].logic = GPIO_LOW,
    .keypad_row_pins[2].pin = PIN2,
    .keypad_row_pins[2].port = PORTC_INDEX,

    .keypad_row_pins[3].direction = GPIO_OUTPUT,
    .keypad_row_pins[3].logic = GPIO_LOW,
    .keypad_row_pins[3].pin = PIN3,
    .keypad_row_pins[3].port = PORTC_INDEX,



};

void ecu_layer_initailize(void) {
    Std_ReturnType ret = E_OK;
    ret = lcd_4bit_initailize(&lcd);
    ret = keypad_initialize(&key);

}
