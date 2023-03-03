#include "clock.h"

void draw_arrow(Framebuf* canvas, int16_t angle, uint8_t length, uint8_t size, uint16_t color) 
{
    angle -= 90;
    float angleRad = (float) angle * PI / 180;
    int x = cos(angleRad) * length + LCD_W2;
    int y = sin(angleRad) * length + LCD_H2;

    canvas->line(LCD_W2, LCD_H2, x, y, color, size);
}

void draw_clock(Framebuf* canvas, uint8_t hour, uint8_t min, uint8_t sec) 
{
    uint16_t background, risk_color, riskdigit_color, arrow_color, sec_color;

    background = BLACK;
    risk_color = riskdigit_color = arrow_color = WHITE;
    sec_color = RED;

    canvas->clear(background);

    uint8_t radius1 = 119;
    for (uint16_t angle = 0; angle <= 360; angle += 6) 
    {
        uint8_t riskSize;
        if (!(angle % 90))
            riskSize = 13;
        else if (!(angle % 30))
            riskSize = 10;
        else
            riskSize = 6;

        uint8_t radius2 = radius1 - riskSize;
        float rad = (float) angle * PI / 180;
        int x1 = cos(rad) * radius1 + LCD_W2;
        int y1 = sin(rad) * radius1 + LCD_H2;
        int x2 = cos(rad) * radius2 + LCD_W2;
        int y2 = sin(rad) * radius2 + LCD_H2;

        canvas->line(x1, y1, x2, y2, risk_color, 2);
    }

    canvas->text(165, 30, "1", &Font16, riskdigit_color, background);
    canvas->text(200, 63, "2", &Font16, riskdigit_color, background);
    canvas->text(207, 106, "3", &Font24, riskdigit_color, background);
    canvas->text(200, 160, "4", &Font16, riskdigit_color, background);
    canvas->text(165, 193, "5", &Font16, riskdigit_color, background);
    canvas->text(112, 195, "6", &Font24, riskdigit_color, background);
    canvas->text(65, 193, "7", &Font16, riskdigit_color, background);
    canvas->text(32, 160, "8", &Font16, riskdigit_color, background);
    canvas->text(17, 106, "9", &Font24, riskdigit_color, background);
    canvas->text(32, 63, "10", &Font16, riskdigit_color, background);
    canvas->text(65, 30,"11", &Font16, riskdigit_color, background);
    canvas->text(106, 14,"12", &Font24, riskdigit_color, background);

    draw_arrow(canvas, sec * 6, 100, 1, sec_color);
    draw_arrow(canvas, min * 6 + sec / 10, 75, 2, arrow_color);
    draw_arrow(canvas, hour * 30 + min / 2, 50, 4, arrow_color);

    canvas->display();

    DEV_Delay_ms(50);
}