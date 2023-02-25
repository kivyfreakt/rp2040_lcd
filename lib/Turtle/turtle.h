#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include "lcd.h"

#define degToRad(deg) (deg * M_PI / 180)

class Turtle
{

    LCD* display = NULL; //Display for turtle graphics.
    std::stack <int> save_stack; // stack to store coordinates
    int x; //Current position of the turtle
    int y; //Current position of the turtle
    int direction;  // position of the turtle's head in space( in degrees )
    bool pen;
    
    int step;
    int angle;

    void draw(uint16_t, uint16_t);

    public:
        Turtle(LCD*);
        void init(int, int);
        void moveto(int, int);
        void move(int);
        void right(int);
        void left(int);
        void save();
        void restore();

        bool get_pen();
        void set_pen(bool);

        void pendown();
        void penup();

};
