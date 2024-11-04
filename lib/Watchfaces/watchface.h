#ifndef __WATCHFACE_H
#define __WATCHFACE_H

#include <cmath>
#include <ctime>
#include "pico/util/datetime.h"
#include "lcd.h"
#include "utils.h"

class Watchface
{
    public:
        virtual void draw_clock(Framebuf*, datetime_t*) = 0;
};

#endif
