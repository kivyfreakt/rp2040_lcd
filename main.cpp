#include <stdio.h>
#include <stdlib.h> 
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/rtc.h"
#include "pico/util/datetime.h"
#include "DEV_Config.h"
#include "Debug.h"
#include "lcd.h"
#include "turtle.h"
#include "clock.h"

int main(void)
{

    if (DEV_Module_Init() != 0)
        return -1;

    adc_init();
    adc_gpio_init(29);
    adc_select_input(3);
    
    uint16_t img[LCD_HEIGHT * LCD_WIDTH];

    LCD lcd((uint16_t *)&img, HORIZONTAL);
    
    DEV_SET_PWM(60);
    
    char datetime_buf[256];
    char *datetime_str = &datetime_buf[0];

    // Start on Friday 5th of June 2020 15:45:00
    datetime_t t = {
            .year  = 2020,
            .month = 06,
            .day   = 05,
            .dotw  = 5, // 0 is Sunday, so 5 is Friday
            .hour  = 15,
            .min   = 45,
            .sec   = 00
    };

    // Start the RTC
    rtc_init();
    rtc_set_datetime(&t);

    DEV_Delay_ms(1000);

    while(true)
    {
        rtc_get_datetime(&t);
        draw_clock(&lcd, t.hour, t.min, t.sec);
        sleep_ms(100);
    }

    DEV_Module_Exit();

    return 0;
}


    // // lcd.clear(WHITE);

    // // lcd.point(50, 41, BLACK, 1);
    // // lcd.point(50, 46, BLACK, 2);
    // // lcd.point(50, 51, BLACK, 3);
    // // lcd.point(50, 56, BLACK, 4);
    // // lcd.point(50, 61, BLACK, 5);

    // lcd.rect(60, 40, 90, 70, RED, 2, 1);
    // lcd.rect(100, 40, 130, 70, GREEN, 2, 1);
    // lcd.rect(140, 40, 170, 70, BLUE, 2, 1);

    // lcd.text(50, 100, "ABC", &Font20, PURPLE, WHITE);
    // // lcd->text(50, 161, "test string", &Font16, ORANGE, WHITE);
    
    // lcd.display();

    // Turtle turtle(&lcd);

    // turtle.pendown();
    
    // for (int i = 0; i < 4; i++)
    // {
    //     turtle.move(25);
    //     turtle.left(90);
    // }
