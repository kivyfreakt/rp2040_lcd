#include "default_watchface.h"

void DefaultWatchface::draw_date(Framebuf* canvas, datetime_t* t)
{   
    char buf[7]; 
    get_day_month(t->day, t->month, buf);

    canvas->text(LCD_W2+20, LCD_H2-13, get_day_name(t->dotw), &font12, TEXT_COLOR, BACKGROUND);
    canvas->text(LCD_W2+20, LCD_H2-1, buf, &font12, TEXT_COLOR, BACKGROUND);
}

void DefaultWatchface::draw_arrow(Framebuf* canvas, int16_t angle, int8_t length, uint8_t size, uint16_t color) 
{
    angle -= 90;
    float angleRad = (float) angle * PI / 180;
    int x = cos(angleRad) * length + LCD_W2;
    int y = sin(angleRad) * length + LCD_H2;

    // canvas->line(LCD_W2, LCD_H2, x, y, color, size);
    canvas->smoothline(LCD_W2, LCD_H2, x, y, size, color, BACKGROUND);
}

void DefaultWatchface::draw_clock(Framebuf* canvas, datetime_t* t) 
{
    uint16_t risk_color;

    risk_color = WHITE;

    canvas->clear(BACKGROUND);

    uint8_t radius1 = 119;
    for (uint16_t angle = 0; angle <= 360; angle += 6) 
    {
        uint8_t riskSize;
        if (!(angle % 30))
        {
            riskSize = 10;
            risk_color = RISK_COLOR;
        }
        else
        {
            riskSize = 2;
            risk_color = SMALL_RISK_COLOR;
        }

        uint8_t radius2 = radius1 - riskSize;
        float rad = (float) angle * PI / 180;
        int x1 = cos(rad) * radius1 + LCD_W2;
        int y1 = sin(rad) * radius1 + LCD_H2;
        int x2 = cos(rad) * radius2 + LCD_W2;
        int y2 = sin(rad) * radius2 + LCD_H2;

        canvas->smoothline(x1, y1, x2, y2, 2, risk_color, BACKGROUND);
    }

    // draw date
    draw_date(canvas, t);

    // draw arrows
    draw_arrow(canvas, t->hour * 30 + t->min / 2, 50, 4, HOUR_COLOR);
    draw_arrow(canvas, t->min * 6 + t->sec / 10, 75, 2, MIN_COLOR);
    draw_arrow(canvas, t->sec * 6, 100, 1, SEC_COLOR);
    draw_arrow(canvas, t->sec * 6, -25, 1, SEC_COLOR); // dirty way to add more len to sec line

    // prettify
    canvas->circle(LCD_W2, LCD_H2, 5, BACKGROUND, 2, 1);
    canvas->circle(LCD_W2, LCD_H2, 5, MIN_COLOR, 2, 0);
    canvas->circle(LCD_W2, LCD_H2, 2, SEC_COLOR, 1, 1);

    canvas->display();

    // sleep_ms(50);
}