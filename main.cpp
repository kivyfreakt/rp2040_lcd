#include <stdio.h>
#include <stdlib.h> 
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "hardware/rtc.h"
#include "dev_config.h"
#include "lcd.h"
#include "default_watchface.h"

static uint16_t img[LCD_HEIGHT * LCD_WIDTH];

int main(void)
{   
    // init
    if (dev_module_init() != 0)
        return -1;

    LCD lcd((uint16_t *)&img, RIGHT);
    Watchface *default_clock = new DefaultWatchface();

    datetime_t t = {
            .year  = 2024,
            .month = 11,
            .day   = 05,
            .dotw  = 2, // 0 is Sunday, so 5 is Friday
            .hour  = 01,
            .min   = 22,
            .sec   = 00
    };

    rtc_init();
    rtc_set_datetime(&t);

    // clk_sys is >2000x faster than clk_rtc, so datetime is not updated immediately when rtc_get_datetime() is called.
    // The delay is up to 3 RTC clock cycles (which is 64us with the default clock settings)
    sleep_us(64);

    // loop
    while(true)
    {
        rtc_get_datetime(&t);
        default_clock->draw_clock(&lcd, &t);
        sleep_ms(100);
    };

    delete default_clock;
    return 0;
}