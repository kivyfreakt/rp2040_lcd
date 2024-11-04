#ifndef __DEFAULTWATCHFACE_H
#define __DEFAULTWATCHFACE_H

#include "watchface.h"
#include "framebuf.h"

class DefaultWatchface : public Watchface
{
    void draw_arrow(Framebuf*, int16_t, uint8_t, uint8_t, uint16_t);
    public:
        void draw_clock(Framebuf*, uint8_t, uint8_t, uint8_t);
};

#endif
