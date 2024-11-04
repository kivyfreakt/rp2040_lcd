#ifndef __WATCHFACE_H
#define __WATCHFACE_H

#include <cmath>
#include "lcd.h"

class Watchface
{
    public:
        virtual void draw_clock(Framebuf*, uint8_t, uint8_t, uint8_t) = 0;
};

#endif
