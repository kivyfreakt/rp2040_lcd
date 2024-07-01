#include <stdio.h>
#include <stdlib.h> 
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "DEV_Config.h"
#include "lcd.h"
#include "tests.h"

static uint16_t img[LCD_HEIGHT * LCD_WIDTH];

int main(void)
{

    if (DEV_Module_Init() != 0)
        return -1;

    LCD lcd((uint16_t *)&img, HORIZONTAL);
    
    DEV_SET_PWM(60);

    test_display(&lcd);

    while(true){};

    DEV_Module_Exit();

    return 0;
}