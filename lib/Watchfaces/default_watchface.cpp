#include "default_watchface.h"

void DefaultWatchface::draw_arrow(Framebuf* canvas, int16_t angle, int8_t length, uint8_t size, uint16_t color) 
{
    angle -= 90;
    float angleRad = (float) angle * PI / 180;
    int x = cos(angleRad) * length + LCD_W2;
    int y = sin(angleRad) * length + LCD_H2;

    canvas->line(LCD_W2, LCD_H2, x, y, color, size);
}

void DefaultWatchface::draw_clock(Framebuf* canvas, datetime_t* t) 
{
    uint16_t background, risk_color, hour_color, min_color, sec_color;

    background = BLACK;
    risk_color = WHITE;

    hour_color = BLUE;
    min_color = ORANGE;
    sec_color = RED;

    canvas->clear(background);

    uint8_t radius1 = 119;
    for (uint16_t angle = 0; angle <= 360; angle += 6) 
    {
        uint8_t riskSize;
        if (!(angle % 30))
        {
            riskSize = 10;
            risk_color = WHITE;
        }
        else
        {
            riskSize = 2;
            risk_color = DARKGREY;
        }

        uint8_t radius2 = radius1 - riskSize;
        float rad = (float) angle * PI / 180;
        int x1 = cos(rad) * radius1 + LCD_W2;
        int y1 = sin(rad) * radius1 + LCD_H2;
        int x2 = cos(rad) * radius2 + LCD_W2;
        int y2 = sin(rad) * radius2 + LCD_H2;

        canvas->line(x1, y1, x2, y2, risk_color, 2);
    }

    draw_arrow(canvas, t->hour * 30 + t->min / 2, 50, 4, hour_color);
    draw_arrow(canvas, t->min * 6 + t->sec / 10, 75, 2, min_color);
    draw_arrow(canvas, t->sec * 6, 100, 1, sec_color);
    draw_arrow(canvas, t->sec * 6, -25, 1, sec_color); // dirty way to add more len to sec line

    canvas->circle(LCD_W2, LCD_H2, 5, background, 2, 1);
    canvas->circle(LCD_W2, LCD_H2, 5, min_color, 2, 0);
    canvas->circle(LCD_W2, LCD_H2, 2, sec_color, 1, 1);

    canvas->display();

    // sleep_ms(50);
}