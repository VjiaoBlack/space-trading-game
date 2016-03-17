// Victor 2/20

#include "input.hxx"

std::map<int,int> keys_held;
int sdl_quit;
int mouse_x, mouse_y;
int mouse_xvel, mouse_yvel;
int mouse_left;
int click_left;


void init_input()
{
    keys_held.clear();
    mouse_x = mouse_y = mouse_xvel = mouse_yvel = mouse_left = 0;
    sdl_quit = 0;
}


// does not handle: caps, control, fnction, option/alt, commmand, shift/tab??
void get_input()
{
    SDL_Event event;
    click_left = 0;


    // while clears the input queue. Thus, no lag!
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            sdl_quit = 1;
        }
        else if (event.type == SDL_KEYUP)
        {  // any key is released
            keys_held[event.key.keysym.sym] = 0;
        }
        else if (event.type == SDL_KEYDOWN)
        {  // any key is pressed
            keys_held[event.key.keysym.sym] = 1;
        }
        else if (event.type == SDL_MOUSEMOTION)
        {
            mouse_x = event.motion.x;
            mouse_y = event.motion.y;

            mouse_xvel = event.motion.xrel;
            mouse_yvel = event.motion.yrel;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN )
        {

            if ( event.button.button == SDL_BUTTON_LEFT )
            {
                printf("asdf\n");
                click_left = 1;

                mouse_x = event.button.x;
                mouse_y = event.button.y;
                mouse_left = 1;
            }

        }
        else if (event.type == SDL_MOUSEBUTTONUP)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {

                click_left = 0;
                mouse_x = event.button.x;
                mouse_y = event.button.y;
                mouse_left = 0;

            }
        }


    }
}
