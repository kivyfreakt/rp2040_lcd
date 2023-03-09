#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include "framebuf.h"

#define degToRad(deg) (deg * M_PI / 180.0)

class Turtle
{

    Framebuf* display; //Display for turtle graphics.
    std::stack <int> save_stack; // stack to store coordinates
    int x; //Current position of the turtle
    int y; //Current position of the turtle
    int direction;  // position of the turtle's head in space( in degrees )
    bool pen;
    uint16_t pen_color;
    uint8_t pen_size;
    
    void draw(uint16_t, uint16_t);

    public:
        Turtle(Framebuf*);
        void moveto(int, int);
        void move(int);
        void right(int);
        void left(int);
        void save();
        void restore();

        bool get_pen();
        void set_pen(bool);

        uint16_t get_color();
        void set_color(uint16_t);

        uint8_t get_size();
        void set_size(uint8_t);

        void pendown();
        void penup();
};
