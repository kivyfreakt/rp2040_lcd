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

    canvas->text(165, 30, "1", &font16, riskdigit_color, background);
    canvas->text(200, 63, "2", &font16, riskdigit_color, background);
    canvas->text(207, 106, "3", &font24, riskdigit_color, background);
    canvas->text(200, 160, "4", &font16, riskdigit_color, background);
    canvas->text(165, 193, "5", &font16, riskdigit_color, background);
    canvas->text(112, 195, "6", &font24, riskdigit_color, background);
    canvas->text(65, 193, "7", &font16, riskdigit_color, background);
    canvas->text(32, 160, "8", &font16, riskdigit_color, background);
    canvas->text(17, 106, "9", &font24, riskdigit_color, background);
    canvas->text(32, 63, "10", &font16, riskdigit_color, background);
    canvas->text(65, 30,"11", &font16, riskdigit_color, background);
    canvas->text(106, 14,"12", &font24, riskdigit_color, background);

    draw_arrow(canvas, sec * 6, 100, 1, sec_color);
    draw_arrow(canvas, min * 6 + sec / 10, 75, 2, arrow_color);
    draw_arrow(canvas, hour * 30 + min / 2, 50, 4, arrow_color);

    canvas->circle(LCD_W2, LCD_H2, 5, riskdigit_color, 2, 0);
    canvas->circle(LCD_W2, LCD_H2, 3, background, 1, 1);

    canvas->display();

    sleep_ms(50);
}

void draw_status(Framebuf* canvas, uint16_t status1, uint16_t status2, uint16_t status3)
{   
    canvas->clear(BLACK);

    canvas->arc(LCD_H2, LCD_W2, 0, status1, LCD_H2 - 6, RED, 3);
    canvas->arc(LCD_H2, LCD_W2, 0, status2, LCD_H2 - 12, GREEN, 3);
    canvas->arc(LCD_H2, LCD_W2, 0, status3, LCD_H2 - 18, BLUE, 3);

    canvas->display();

    sleep_ms(50);
}