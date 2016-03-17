#ifndef GRAPHICS_HXX
#define GRAPHICS_HXX

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

#include "SDL.h"
#include "input.hxx"
#include <math.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>





void draw_line(int,int,int,int, int,int,int,int);
void draw_rect(int,int,int,int, int,int,int,int);
void draw_font(std::string, int,int, int,int,int);

void init_sdl();

void clear_textures();

void init_graphics();


extern SDL_Window* window;
extern SDL_Texture* texture;
extern SDL_Renderer* renderer;

extern SDL_Texture *grass;

extern TTF_Font* font;


extern std::map<std::string, SDL_Texture*> textures;



// TODO: this graphics world view thing.

#endif
