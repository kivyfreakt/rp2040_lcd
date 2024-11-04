#ifndef __LCD_H
#define __LCD_H	
    
#include "dev_config.h"
#include "framebuf.h"
#include <stdint.h>

#include <stdlib.h>
#include <stdio.h>

#define LCD_HEIGHT 240
#define LCD_WIDTH 240
#define LCD_W2 120
#define LCD_H2 120

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

class LCD : public Framebuf
{
    uint8_t direction;

    void data(uint8_t);
    void command(uint8_t);
    void init_reg(uint8_t);
    void set_windows(uint16_t, uint16_t, uint16_t, uint16_t);

    public:
        LCD(uint16_t*);
        LCD(uint16_t*, uint8_t);
        void reset();
        void display() override;
};

#endif
