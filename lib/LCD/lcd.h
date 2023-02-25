#ifndef __LCD_H
#define __LCD_H	
    
#include "DEV_Config.h"
#include "framebuf.h"
#include <stdint.h>

#include <stdlib.h>
#include <stdio.h>

#define LCD_HEIGHT 240
#define LCD_WIDTH 240
#define LCD_W2 120
#define LCD_H2 120
#define LCD_SZ LCD_W*LCD_H*2

#define HORIZONTAL 0
#define VERTICAL 1

class LCD : public Framebuf
{
    uint8_t direction;

    void data(uint8_t);
    void command(uint8_t);
    void init_reg();
    void set_windows(uint16_t, uint16_t, uint16_t, uint16_t);

    public:
        LCD(uint16_t*);
        LCD(uint16_t*, uint8_t);
        void reset();
        void display();

        void set_direction(uint8_t);
        uint8_t get_direction();
};

#endif
