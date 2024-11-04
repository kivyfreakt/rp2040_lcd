#include <stdio.h>
#include <stdlib.h> 
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
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

    // loop
    while(true)
    {
        default_clock->draw_clock(&lcd, 0, 24, 47);
        lcd.display();
        sleep_ms(100);
    };

    delete default_clock;
    return 0;
}