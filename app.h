/* 
 * File:   app.h
 * Author: xcite
 *
 * Created on November 14, 2023, 8:33 PM
 */
#ifndef APP_H
#define APP_H

/*----------------INCLUDES-------------------*/
#include "ECU_LAYER/ecu_layer_init.h"
/*-----------------MACROS--------------------*/



/*--------------MACROS_FUNCTIONS-----------*/


/*------------DATA_TYPES-------------------*/
extern lcd_4bit_mode lcd;
extern Keypad_t key;
extern button_t button;
/*------------FUNCTIONS_DECLARATION--------*/
void Application_initialize(void);


#endif	/* APP_H */

