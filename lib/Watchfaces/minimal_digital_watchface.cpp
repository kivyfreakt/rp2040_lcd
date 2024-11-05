#include "minimal_digital_watchface.h"

void MinimalDigitalWatchface::draw_clock(Framebuf* canvas, datetime_t* t) 
{
    canvas->clear(BACKGROUND);

    canvas->text(LCD_W2-19, LCD_H2-25, "12", &font24, HOUR_COLOR, BACKGROUND);
    canvas->text(LCD_W2-19, LCD_H2-1, "56", &font24, TEXT_COLOR, BACKGROUND);

    canvas->arc(LCD_H2, LCD_W2, 0, t->sec*6, LCD_H2 - 6, HOUR_COLOR, 3);
    canvas->display();
}