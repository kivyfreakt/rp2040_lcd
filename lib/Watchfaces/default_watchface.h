#ifndef __DEFAULTWATCHFACE_H
#define __DEFAULTWATCHFACE_H

#include "watchface.h"
#include "framebuf.h"

#ifndef WHITE_THEME

#define BACKGROUND BLACK
#define TEXT_COLOR WHITE
#define RISK_COLOR WHITE
#define SMALL_RISK_COLOR DARKGREY
#define HOUR_COLOR BLUE
#define MIN_COLOR ORANGE
#define SEC_COLOR RED

#else

#define BACKGROUND WHITE
#define TEXT_COLOR BLACK
#define RISK_COLOR BLACK
#define SMALL_RISK_COLOR DARKGREY
#define HOUR_COLOR BLUE
#define MIN_COLOR ORANGE
#define SEC_COLOR RED

#endif

class DefaultWatchface : public Watchface
{
    void draw_arrow(Framebuf*, int16_t, int8_t, uint8_t, uint16_t);
    void draw_date(Framebuf*, datetime_t*);
    public:
        void draw_clock(Framebuf*, datetime_t*);
};

#endif
