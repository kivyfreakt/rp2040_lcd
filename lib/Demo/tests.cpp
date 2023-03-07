#include "tests.h"

void test_display(LCD* display)
{     

    // full screen colors
    uint8_t color_count = 5;
    uint16_t colors[color_count] = {BLACK, WHITE, RED, GREEN, BLUE};
    for (uint8_t i = 0; i < color_count; i++)
    {
        display->clear(colors[i]);
        display->display();
        DEV_Delay_ms(5000);
    }

    // gradients
    color_count = 8;
    uint16_t gradient_colors[color_count] = {WHITE, BLACK, RED, BLACK, GREEN, BLACK, BLUE, BLACK};
    for (uint8_t i = 0; i < color_count; i += 2)
    {
        display->gradient(0, 0, display->width, display->height, gradient_colors[i], gradient_colors[i+1], 0);
        display->display();
        DEV_Delay_ms(5000);
    }
}