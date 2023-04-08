#ifndef DEMO_CLOCK_H_
#define DEMO_CLOCK_H_

#include <cmath>
#include "lcd.h"

void draw_arrow(Framebuf* canvas, int16_t angle, uint8_t length, uint8_t size, uint16_t color); 
void draw_clock(Framebuf* canvas, uint8_t hour, uint8_t min, uint8_t sec);
void draw_status(Framebuf* canvas, uint16_t status1, uint16_t status2, uint16_t status3);

#endif
