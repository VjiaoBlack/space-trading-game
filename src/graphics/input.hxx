#ifndef INPUT_HANDLER_HXX
#define INPUT_HANDLER_HXX

#include <stdio.h>
#include <stdlib.h>
#include "SDL.h"
#include <iostream>
#include <map>
#include "../graphics/graphics.hxx"

extern std::map<int,int> keys_held;
// NOTE TO SELF, INCLUDE AN OLD KEYS_HELD TO DETECT CLICK BOUNDARIES:



extern int sdl_quit;


extern int mouse_x, mouse_y;
extern int mouse_xvel, mouse_yvel;
extern int mouse_left;
extern int click_left;

void init_input();
void get_input();

#endif
