#include <stdio.h>
#include <stdlib.h> 
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/rtc.h"
#include "pico/util/datetime.h"
#include "DEV_Config.h"
#include "lcd.h"

#include "turtle.h"
#include "tests.h"

static uint16_t img[LCD_HEIGHT * LCD_WIDTH];

int main(void)
{

    if (DEV_Module_Init() != 0)
        return -1;

    adc_init();
    adc_gpio_init(29);
    adc_select_input(3);

    LCD lcd((uint16_t *)&img, HORIZONTAL);
    
    DEV_SET_PWM(60);

    test_display(&lcd);

    while(true){};

    DEV_Module_Exit();

    return 0;
}