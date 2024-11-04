#include <stdio.h>
#include <stdlib.h> 
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "dev_config.h"
#include "lcd.h"
#include "tests.h"

static uint16_t img[LCD_HEIGHT * LCD_WIDTH];

int main(void)
{
    if (dev_module_init() != 0)
        return -1;

    LCD lcd((uint16_t *)&img, RIGHT);

    test_display(&lcd);

    while(true){};

    return 0;
}