#include "framebuf.h"
#include "DEV_Config.h"
#include <stdint.h>
#include <stdlib.h>
// #include <math.h>


Framebuf::Framebuf(uint16_t* _canvas, uint8_t _width, uint8_t _height)
{
    this->canvas = _canvas;
    this->width = _width;
    this->height = _height;
}


void Framebuf::pixel(uint16_t x, uint16_t y, uint16_t color)
{
    if (x > this->width || y > this->height || x < 0 || y < 0) 
        return;

    uint16_t color_swapped = _swap_bytes(color); // костыль....
    // если ставить порядок rgb в init, канал зеленого и синего меняются местами....
    
    this->canvas[x + y*this->width] = color_swapped;
}


void Framebuf::point(uint16_t x, uint16_t y, uint16_t color, uint16_t size)
{
    if (x > this->width || y > this->height || x < 0 || y < 0) 
        return;

        for (int16_t x_i = 0; x_i < size; x_i++)
            for (int16_t y_i = 0; y_i < size; y_i++)
                this->pixel(x + x_i - 1, y + y_i - 1, color);

}

void Framebuf::line(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color, uint16_t size)
{

    if (x_start > this->width || y_start > this->height || x_start < 0 || y_start < 0 || x_end > this->width || y_end > this->height || x_end < 0 || y_end < 0 ) 
        return;
    
    uint16_t x_point = x_start;
    uint16_t y_point = y_start;

    int dx = (int)x_end - (int)x_start >= 0 ? x_end - x_start : x_start - x_end;
    int dy = (int)y_end - (int)y_start <= 0 ? y_end - y_start : y_start - y_end;

    // Increment direction, 1 is positive, -1 is counter;
    int XAddway = x_start < x_end ? 1 : -1;
    int YAddway = y_start < y_end ? 1 : -1;

    //Cumulative error
    int eps = dx + dy;

    for (;;)
    {

        this->point(x_point, y_point, color, size);

        if (2 * eps >= dy) 
        {
            if (x_point == x_end)
                break;
            eps += dy;
            x_point += XAddway;
        }

        if (2 * eps <= dx) 
        {
            if (y_point == y_end)
                break;

            eps += dx;
            y_point += YAddway;
        }

    }
}


void Framebuf::rect(uint16_t x_start, uint16_t y_start, uint16_t x_end, uint16_t y_end, uint16_t color, uint16_t size, uint8_t fill)
{
    if (x_start > this->width || y_start > this->height || x_start < 0 || y_start < 0 || x_end > this->width || y_end > this->height || x_end < 0 || y_end < 0 ) 
        return;

    if (fill) {
        for(uint16_t i = y_start; i < y_end; i++) {
            this->line(x_start, i, x_end, i, color, size);
        }
    } else {
        this->line(x_start, y_start, x_end, y_start, color, size);
        this->line(x_start, y_start, x_start, y_end, color, size);
        this->line(x_end, y_end, x_end, y_start, color, size);
        this->line(x_end, y_end, x_start, y_end, color, size);
    }
}

void Framebuf::clear(uint16_t color)
{
    for (int i = 0; i < this->height*this->width; i++) {
        this->canvas[i] = color;
    }
}

void Framebuf::ch(uint16_t x, uint16_t y, const char ascii, sFONT* font, uint16_t foreground, uint16_t background)
{
    uint16_t page, column;

    if (x > this->width || y > this->height || x < 0 || y < 0) 
        return;

    uint32_t offset = (ascii - ' ') * font->Height * (font->Width / 8 + (font->Width % 8 ? 1 : 0));
    const unsigned char *ptr = &font->table[offset];

    for (page = 0; page < font->Height; page ++ ) {
        for (column = 0; column < font->Width; column ++ ) {

            // To determine whether the font background color and screen background color is consistent
            if (*ptr & (0x80 >> (column % 8)))
            {
                this->pixel(x + column, y + page, background);
            }
            else
            {
                this->pixel(x + column, y + page, foreground);
            }
            //One pixel is 8 bits
            if (column % 8 == 7)
                ptr++;
        }// Write a line
        if (font->Width % 8 != 0)
            ptr++;
    }// Write all
}

void Framebuf::text(uint16_t x, uint16_t y, const char * str, sFONT* font, uint16_t foreground, uint16_t background)
{
    uint16_t x_point = x;
    uint16_t y_point = y;

    if (x > this->width || y > this->height || x < 0 || y < 0) 
        return;

    while (* str != '\0') {
        //if X direction filled , reposition to(x,y_point),y_point is Y direction plus the Height of the character
        if ((x_point + font->Width) > this->width) {
            x_point = x;
            y_point += font->Height;
        }

        // If the Y direction is full, reposition to(x, y)
        if ((y_point  + font->Height ) > this->height) {
            x_point = x;
            y_point = y;
        }
        this->ch(x_point, y_point, * str, font, background, foreground);

        //The next character of the address
        str++;

        //The next word of the abscissa increases the font of the broadband
        x_point += font->Width;
    }
}
