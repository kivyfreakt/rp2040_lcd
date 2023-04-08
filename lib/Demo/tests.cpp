#include "tests.h"
#include "clock.h"

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
    display->point(50, 41, WHITE, 1);
    display->point(50, 46, WHITE, 2);
    display->point(50, 51, WHITE, 3);
    display->point(50, 56, WHITE, 4);
    display->point(50, 61, WHITE, 5);

    display->line(60, 40, 90, 70, MAGENTA, 2);
    display->line(60, 70, 90, 40, MAGENTA, 2);

    display->rect(60, 40, 90, 70, RED, 2, 0);
    display->rect(100, 40, 130, 70, BLUE, 2, 1);

    display->hline(135, 55, 30, CYAN, 1);
    display->vline(150, 40, 30, CYAN, 1);

    display->circle(67, 100, 14, MAROON, 2, 0);
    display->circle(107, 100, 14, YELLOW, 1, 1);

    display->arc(67, 140, 0, 90, 10, ORANGE, 1);
    display->arc(107, 140, 0, 180, 10, PINK, 1);
    display->arc(147, 140, 0, 270, 10, PURPLE, 1);

    display->display();
    DEV_Delay_ms(TEST_DELAY);

    // fonts demo
    display->clear(BLACK);
    display->text(30, 54, "ABCxyz123", &font12, WHITE, BLACK);
    display->text(30, 98, "ABCxyz123", &font16, RED, BLACK);
    display->text(30, 142, "ABCxyz123", &font20, WHITE, GREEN);
    display->text(30, 186, "ABCxyz123", &font24, BLUE, WHITE);
    display->display();
    DEV_Delay_ms(TEST_DELAY);

    // apps demo
    draw_clock(display, 0, 24, 47);
    DEV_Delay_ms(TEST_DELAY);
    draw_status(display, 249, 124, 38);
    DEV_Delay_ms(TEST_DELAY);
}