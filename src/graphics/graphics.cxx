#include "graphics.hxx"

SDL_Window* window;
SDL_Texture* texture;
SDL_Renderer* renderer;




void draw_line(int x1, int y1, int x2, int y2, int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor( renderer, r, g, b, a );
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void draw_rect(int x1, int y1, int x2, int y2, int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor( renderer, r, g, b, a );

    int ymin = (y1 < y2) ? y1 : y2;
    int ymax = (y1 > y2) ? y1 : y2;

    for (int y = ymin; y <= ymax; ++y)
{
        SDL_RenderDrawLine(renderer, x1, y, x2, y);
    }
}

void init_graphics()
{

}

void init_sdl()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow("My Game Window",
                        SDL_WINDOWPOS_UNDEFINED,
                        SDL_WINDOWPOS_UNDEFINED,
                        WINDOW_WIDTH, WINDOW_HEIGHT,
                        SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        printf("Couldn't set window mode %d x %d: %s\n", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer( window, 0, SDL_RENDERER_ACCELERATED);

    init_graphics();

}
