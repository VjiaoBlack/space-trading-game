#include "game.hxx"

int x = 100;
int y = 100;

int v_x = 0;
int v_y = 0;

std::vector<Star> stars;
int num_stars = 1000;


void draw()
{
    SDL_RenderClear(renderer);


    for (int i = 0; i < 1000; i++)
    {
        Star star = stars.at(i);

        int dist = star.get_pos().z;
        int app_x = star.get_pos().x - x * 200 / dist;
        int app_y = star.get_pos().y - y * 200 / dist;
        int app_size = star.get_size() * (200 / dist);

        // subtract one to not overdraw
        draw_rect(app_x, app_y,
                  app_x + app_size, app_y + app_size,
                  star.get_color().r, star.get_color().g, star.get_color().b, 0);



    }



    SDL_RenderPresent(renderer);


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

void update()
{
    if (keys_held['w'])
    {
        v_y = -2;
    }

    if (keys_held['s'])
    {
        v_y = 2;
    }

    if (keys_held['a'])
    {
        v_x = -2;
    }

    if (keys_held['d'])
    {
        v_x = 2;
    }

    x += v_x;
    y += v_y;

    if (v_x != 0) {
        v_x -= v_x / sqrt(v_x * v_x);
    }

    if (v_y != 0) {
        v_y -= v_y / sqrt(v_y * v_y);

    }
}

int main(int argv, char* argc[])
{

    init_sdl();

    // init game

    for (int i = 0; i < 1000; i++)
    {
        position_t pos = (position_t) {rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT, 100 + rand() % 400};
        int size = 1 + rand() % 2;

        int luminosity = rand() % 200 + 55;
        color_t color = (color_t) {luminosity, luminosity, luminosity, 1};

        Star* star = new Star(pos, size, color);
        stars.push_back(*star);
        delete star;
    }


    struct timeval start, current;

    gettimeofday(&start, NULL);
    gettimeofday(&current, NULL);




    while (!keys_held['q'])
    {

        gettimeofday(&current, NULL);
        get_input();

        draw();

        update();

        SDL_Delay(MSPF);
    }



    SDL_DestroyWindow(window);
    SDL_Quit();
}
