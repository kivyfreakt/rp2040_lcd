#include <stdio.h>
#include <stdlib.h> 
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/rtc.h"
#include "pico/util/datetime.h"
#include "DEV_Config.h"
#include "lcd.h"
#include "turtle.h"
#include "clock.h"

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

    // CLOCK EXAMPLE
    
    // char datetime_buf[256];
    // char *datetime_str = &datetime_buf[0];

    // // Start on Friday 5th of June 2020 15:45:00
    // datetime_t t = {
    //         .year  = 2020,
    //         .month = 06,
    //         .day   = 05,
    //         .dotw  = 5, // 0 is Sunday, so 5 is Friday
    //         .hour  = 15,
    //         .min   = 45,
    //         .sec   = 00
    // };

    // // Start the RTC
    // rtc_init();
    // rtc_set_datetime(&t);

    // DEV_Delay_ms(1000);

    // while(true)
    // {
    //     rtc_get_datetime(&t);
    //     draw_clock(&lcd, t.hour, t.min, t.sec);
    //     sleep_ms(100);
    // }

    DEV_Module_Exit();

    return 0;
}


// CLOCK EXAMPLE

// TURTLE EXAMPLE

    // Turtle turtle(&lcd);

    // turtle.pendown();
    
    // uint8_t benzsize = LCD_H2;

    // uint16_t colors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

    // for (int i = 0; i < benzsize; i++)
    // {   
    //     turtle.set_color(colors[i % 6]);
    //     turtle.move(i);
    //     turtle.left(59);
    // }
