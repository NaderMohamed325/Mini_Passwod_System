
#include "app.h"

// Global variables
Std_ReturnType ret = E_OK;
uint8 password[] = {'x', 'x', 'x', 'x', '\0'};
uint8 userinput[] = {'x', 'x', 'x', 'x', '\0'};
uint8 tries = 3;
uint8 i = 0;
button_state_t p = BUTTON_RELEASED;

// Function prototypes
void Application_initialize(void);
Std_ReturnType Password_Set_Window(lcd_4bit_mode const *lcd, Keypad_t const *key, uint8 *Password);
Std_ReturnType Password_Enter_Window(lcd_4bit_mode const *lcd, Keypad_t const *key, uint8 tries, uint8 const *Password, uint8 *Userinput);

int main(void) {
    // Initialize the application
    Application_initialize();

    // Set the password
    ret = Password_Set_Window(&lcd, &key, password);

    // Reset counter for password entry
    i = 0;

    // Enter password window
    ret = Password_Enter_Window(&lcd, &key, 3, password, userinput);

    // Return 0 to indicate successful execution
    return 0;
}
















// Function to initialize the application

void Application_initialize(void) {
    ecu_layer_initailize();
}

// Function to set the password
// @param lcd: Pointer to the LCD structure
// @param key: Pointer to the Keypad structure
// @param Password: Pointer to the array where the password will be stored
// @return: Status of the operation (E_OK if successful, E_NOT_OK if there is an error)

Std_ReturnType Password_Set_Window(lcd_4bit_mode const *lcd, Keypad_t const *key, uint8 *Password) {
    Std_ReturnType ret = E_OK;

    // Check if any of the required pointers are NULL
    if (NULL == lcd || NULL == key || NULL == Password) {
        ret = E_NOT_OK;
    } else {
        // Clear the LCD display
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_string(lcd, " Enter your Pass ");
        __delay_ms(1000);
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);

        // Loop to read each digit of the password
        while (i != 4) {
            // Get user input from the keypad
            ret = keypad_get_value(key, &Password[i]);

            // Check if the entered character is not 'x'
            if (Password[i] != 'x') {
                // Display the entered character on the LCD
                ret = lcd_4bit_send_char_data(lcd, Password[i]);
                i++;
                __delay_ms(300);
            }
        }

        // Display a message indicating that the password has been set
        ret = lcd_4bit_send_string_pos(lcd, 2, 1, " Password Done ");
        __delay_ms(1500);

        // Clear the LCD display after setting the password
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
    }

    // Return the status
    return ret;
}

// Function to handle the password entry window
// @param lcd: Pointer to the LCD structure
// @param key: Pointer to the Keypad structure
// @param tries: Number of allowed attempts
// @param Password: Pointer to the correct password
// @param Userinput: Pointer to the array where user input will be stored
// @return: Status of the operation (E_OK if successful, E_NOT_OK if there is an error)

Std_ReturnType Password_Enter_Window(lcd_4bit_mode const *lcd, Keypad_t const *key, uint8 tries, uint8 const *Password, uint8 *Userinput) {
    Std_ReturnType ret = E_OK;

    // Check if any of the required pointers are NULL or invalid tries count
    if (NULL == lcd || NULL == key || tries <= 0 || NULL == Password || NULL == Userinput) {
        ret = E_NOT_OK;
    } else {
        // Local flag to indicate if the correct password is entered
        uint8 flag = 0;

        // Main loop for password entry attempts
        while (tries > 0 && !flag) {

            // Loop to read each digit of the password
            i = 0;
            userinput[0] = 'x';
            userinput[1] = 'x';
            userinput[2] = 'x';
            userinput[3] = 'x';
            userinput[4] = '\0';
            ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
            ret = lcd_4bit_send_string(lcd, " INPUT :   ");
            while (i != 4) {
                // Get user input from the keypad

                ret = keypad_get_value(key, &Userinput[i]);

                // Check if the entered character is not 'x'
                if (Userinput[i] != 'x') {
                    // Display the entered character on the LCD
                    ret = lcd_4bit_send_char_data(lcd, Userinput[i]);
                    i++;
                    __delay_ms(300);
                }
            }

            // Compare the entered password with the expected password
            if (strcmp((char*) Password, (char*) Userinput) == 0) {
                // Display "RIGHT" on the LCD for a correct password
                ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
                ret = lcd_4bit_send_string(lcd, " RIGHT  ");
                __delay_ms(1000);
                flag = 1; // Set flag to exit the loop
                break;
            } else {
                // Display "WRONG" on the LCD for an incorrect password
                ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
                ret = lcd_4bit_send_string(lcd, " WRONG  ");
                ret = lcd_4bit_send_string_pos(lcd, 2, 1, "Tries ");
                ret = lcd_4bit_send_char_data_pos(lcd, 2, 7, (tries - 1) + '0'); // Display the remaining tries
                __delay_ms(1000);
            }

            tries--; // Decrease the number of remaining attempts
        }

        // Clear the LCD display after all attempts
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
    }

    // Return the status
    return ret;
}

