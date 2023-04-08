#include "turtle.h"

Turtle::Turtle(Framebuf *_display)
{
    this->display = _display;
    this->direction = 0;
    this->x = _display->width / 2;
    this->y = _display->height / 2;
    this->pen = false;
    this->pen_color = BLACK;
    this->pen_size = 1;
}

bool Turtle::get_pen() 
{
    return pen;
}

void Turtle::set_color(uint16_t _color) 
{
    this->pen_color = _color;
}

uint16_t Turtle::get_color() 
{
    return this->pen_color;
}

void Turtle::set_size(uint8_t _size) 
{
    this->pen_size = _size;
}

uint8_t Turtle::get_size() 
{
    return this->pen_size;
}

void Turtle::set_pen(bool _pen) 
{
    this->pen = _pen;
}

void Turtle::moveto(int x1, int y1)
{
    /* Move the turtle to a point with coordinates (x,y) */
    x = x1;
    y = y1;
}

void Turtle::move(int distance)
{
    /* Move the turtle forward by a given distance */
    uint8_t nx = x + distance * cos(degToRad(direction));
    uint8_t ny = y + distance * sin(degToRad(direction));
    if (pen)
        draw(nx, ny);
    x = nx;
    y = ny;
}

void Turtle::right(float angle)
{
    /* Turn the turtle to the right side */
    float result = direction + angle;
    if (result > 360.0 || result < 0)
        angle = fmod(result, 360.0) - direction;
    direction += angle;
}

void Turtle::left(float angle)
{
    /* Turn the turtle to the left side */
    right(-angle);
}

void Turtle::save()
{
    save_stack.push(x);
    save_stack.push(y);
    save_stack.push(direction);
}

void Turtle::restore()
{
    direction = save_stack.top();
    save_stack.pop();
    int ny = save_stack.top();
    save_stack.pop();
    int nx = save_stack.top();
    save_stack.pop();
    x = nx;
    y = ny;
}

// --------------- Drawing methods ---------------

void Turtle::pendown()
{
    /* Lowers the pen-the turtle, after which
    * she leaves a trail when moving
    */
    this->set_pen(true);
}

void Turtle::penup()
{
    /* Lifts the pen the turtle, after which
    * it ceases to leave a trail when moving
    */
    this->set_pen(false);
}

void Turtle::draw(uint16_t _x, uint16_t _y)
{   
    display->line(this->x, this->y, _x, _y, this->pen_color, this->pen_size);
    display->display();
}