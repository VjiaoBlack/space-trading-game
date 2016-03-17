#ifndef GAME_HXX
#define GAME_HXX

#include <stdio.h>
#include <sys/time.h>
#include <cstdlib>
#include "graphics/graphics.hxx"
#include "graphics/input.hxx"

#include <vector>

#define FPS 60
#define MSPF 17

typedef struct {
    int x;
    int y;
    int z;
} position_t;

typedef struct {
    int r, g, b, a;
} color_t;

class Star
{
    position_t pos;
    int size;
    color_t color;

public:
    position_t get_pos() {return pos;}
    color_t get_color() {return color;}
    int get_size() {return size;}

    void set_pos(const position_t pos) {
        this->pos = pos;}
    void set_color(const color_t color) {
        this->color = color;}

    Star(position_t pos, int size, color_t color);

    void draw();
};

Star::Star(position_t pos, int size, color_t color)
{
    this->pos = pos;
    this->size = size;
    this->color = color;
}

void Star::draw()
{

}


void draw();

void update();

#endif
