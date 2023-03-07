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
        DEV_Delay_ms(TEST_DELAY);
    }

    // gradients
    color_count = 8;
    uint16_t gradient_colors[color_count] = {WHITE, BLACK, RED, BLACK, GREEN, BLACK, BLUE, BLACK};
    for (uint8_t i = 0; i < color_count; i += 2)
    {
        display->gradient(0, 0, display->width, display->height, gradient_colors[i], gradient_colors[i+1], 0);
        display->display();
        DEV_Delay_ms(TEST_DELAY);
    }

    // graph primitives demo
    display->clear(BLACK);
    display->point(50, 41, BLACK, 1);
    display->point(50, 46, BLACK, 2);
    display->point(50, 51, BLACK, 3);
    display->point(50, 56, BLACK, 4);
    display->point(50, 61, BLACK, 5);

    display->line(60, 40, 90, 70, MAGENTA, 2);
    display->line(60, 70, 90, 40, MAGENTA, 2);

    display->rect(60, 40, 90, 70, RED, 2, 0);
    display->rect(100, 40, 130, 70, BLUE, 2, 1);

    display->hline(135, 55, 30, CYAN, 1);
    display->vline(150, 40, 30, CYAN, 1);

    display->display();
    DEV_Delay_ms(TEST_DELAY);

    // fonts demo
    display->clear(BLACK);
    display->text(30, 54, "ABCxyz123", &font12, WHITE, BLACK);
    display->text(30, 98, "ABCxyz123", &font16, RED, BLACK);
    display->text(30, 142, "ABCxyz123", &font20, WHITE, GREEN);
    display->text(30, 186, "ABCxyz123", &font24, BLUE, WHITE);
    display->display();
}