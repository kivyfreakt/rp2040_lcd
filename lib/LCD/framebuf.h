#ifndef __FRAMEBUF_H
#define __FRAMEBUF_H

#include "dev_config.h"
#include "../Fonts/fonts.h"

#define _swap_bytes(val) ( (((val)>>8)&0x00FF)|(((val)<<8)&0xFF00) )
#define PI 3.14159265

// Color definitions
#define BLACK 0x0000       ///<   0,   0,   0
#define RED 0xF800         ///< 255,   0,   0
#define GREEN 0x07E0       ///<   0, 255,   0
#define BLUE 0x001F        ///<   0,   0, 255
#define NAVY 0x000F        ///<   0,   0, 123
#define DARKGREEN 0x03E0   ///<   0, 125,   0
#define DARKCYAN 0x03EF    ///<   0, 125, 123
#define MAROON 0x7800      ///< 123,   0,   0
#define PURPLE 0x780F      ///< 123,   0, 123
#define OLIVE 0x7BE0       ///< 123, 125,   0
#define LIGHTGREY 0xC618   ///< 198, 195, 198
#define DARKGREY 0x7BEF    ///< 123, 125, 123
#define CYAN 0x07FF        ///<   0, 255, 255
#define MAGENTA 0xF81F     ///< 255,   0, 255
#define YELLOW 0xFFE0      ///< 255, 255,   0
#define WHITE 0xFFFF       ///< 255, 255, 255
#define ORANGE 0xFD20      ///< 255, 165,   0
#define GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define PINK 0xFC18        ///< 255, 130, 198

struct Framebuf
{
    uint16_t* canvas;

    uint8_t width;
    uint8_t height;

    Framebuf(uint16_t*, uint8_t, uint8_t);

    // draw
    virtual void display() = 0;
    void clear(uint16_t);
    void pixel(uint8_t, uint8_t, uint16_t);
    void pixel(uint8_t, uint8_t, uint16_t, uint8_t, uint16_t);
    void point(uint8_t, uint8_t, uint16_t, uint8_t);
    void line(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t, uint8_t);
    void hline(uint8_t, uint8_t, uint8_t, uint16_t, uint8_t);
    void vline(uint8_t, uint8_t, uint8_t, uint16_t, uint8_t);
    void rect(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t, uint8_t, bool);
    void circle(uint8_t, uint8_t, uint8_t, uint16_t, uint8_t, bool);
    void arc(uint8_t, uint8_t, int16_t, int16_t, uint8_t, uint16_t, uint8_t);

    uint16_t alpha_blend(uint8_t, uint16_t, uint16_t);
    void gradient(uint8_t, uint8_t, uint8_t, uint8_t, uint16_t, uint16_t, bool);

    // text
    void ch(uint8_t, uint8_t, const char, Font*, uint16_t, uint16_t);
    void text(uint8_t, uint8_t, const char *, Font*, uint16_t, uint16_t);

    float smoothline_distance(float xpax, float ypay, float bax, float bay, float dr);
    void smoothline(float ax, float ay, float bx, float by, float ar, float br, uint16_t fg_color, uint16_t bg_color);
    void smoothline(float ax, float ay, float bx, float by, float wd, uint16_t fg_color, uint16_t bg_color);
};

#endif





