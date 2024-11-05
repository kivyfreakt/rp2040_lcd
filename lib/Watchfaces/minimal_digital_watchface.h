#ifndef __MINIMALDIGITALWATCHFACE_H
#define __MINIMALDIGITALWATCHFACE_H

#include "watchface.h"
#include "framebuf.h"

#ifndef WHITE_THEME

#define BACKGROUND BLACK
#define TEXT_COLOR WHITE
#define HOUR_COLOR CYAN

#else

#define BACKGROUND WHITE
#define TEXT_COLOR BLAVK
#define HOUR_COLOR CYAN

#endif

class MinimalDigitalWatchface : public Watchface
{
    public:
        void draw_clock(Framebuf*, datetime_t*);
};

#endif