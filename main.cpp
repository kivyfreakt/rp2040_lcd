﻿#include "lcd.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "DEV_Config.h"
#include "Debug.h"
#include <stdlib.h> 

int main(void)
{

    if (DEV_Module_Init() != 0)
        return -1;

    adc_init();
    adc_gpio_init(29);
    adc_select_input(3);
    
    UDOUBLE Imagesize = LCD_HEIGHT * LCD_WIDTH;
    uint16_t *BlackImage;

    if ((BlackImage = (uint16_t *)malloc(Imagesize)) == NULL)
        return 0;
    
    LCD lcd(BlackImage, HORIZONTAL);
    
    DEV_SET_PWM(60);

    lcd.clear(WHITE);

    lcd.point(50, 41, BLACK, 1);
    lcd.point(50, 46, BLACK, 2);
    lcd.point(50, 51, BLACK, 3);
    lcd.point(50, 56, BLACK, 4);
    lcd.point(50, 61, BLACK, 5);

    lcd.rect(60, 40, 90, 70, RED, 2, 1);
    lcd.rect(100, 40, 130, 70, GREEN, 2, 1);
    lcd.rect(140, 40, 170, 70, BLUE, 2, 1);

    lcd.text(50, 100, "ABC", &Font20, PURPLE, WHITE);
    lcd.text(50, 161, "test string", &Font16, ORANGE, WHITE);

    // Paint_DrawCircle(150, 55, 15, GREEN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    // Paint_DrawCircle(185, 55, 15, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);

    // Paint_DrawNum(50, 80, 9.87654321, &Font20, 3, WHITE, BLACK);

    lcd.display();
    
    DEV_Delay_ms(1000);

    while(true){}

    /* Module Exit */
    free(BlackImage);
    BlackImage = NULL;

    DEV_Module_Exit();
    return 0;
}
