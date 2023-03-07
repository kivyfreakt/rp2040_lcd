#ifndef __FONTS_H
#define __FONTS_H

#include <stdint.h>

struct Font
{
    const uint8_t *table;
    uint8_t width;
    uint8_t height;

    Font(const uint8_t* _table, uint8_t _width, uint8_t _height): table(_table), width(_width), height(_height){};
};

extern Font font24;
extern Font font20;
extern Font font16;
extern Font font12;

#endif
