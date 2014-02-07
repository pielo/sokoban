#include "sokoban.h"

static int     ft_event(s_list env)
{
    SDL_Event   event;

    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT || (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE))
        return (0);
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_KP1)
        ft_game(env);
//    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP)
//        positionsapin.y--;
//    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN)
//        positionsapin.y++;
//    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
//        positionsapin.x--;
//    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
//        positionsapin.x++;
    return (1);
}

int             main(int argc, char** argv)
{
    int         continu;
    s_list      env;
    SDL_Surface *menu = NULL;
    SDL_Rect    position_img;

    continu = 1;
    position_img.x = 0;
    position_img.y = 0;
    menu = IMG_Load("menu.jpg");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        write(1, "Unable to init SDL\n", 20);
        return (EXIT_FAILURE);
    }
    if ((env.screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) < 0)
    {
        write(1, "impossible to create screen\n", 28);
        return (EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Mario Sokoban", NULL);
    while(continu)
    {
        continu = ft_event(env);
        SDL_BlitSurface(menu, NULL, env.screen, &position_img);
        SDL_Flip(env.screen);
    }
    SDL_FreeSurface(menu);
    SDL_Quit();
    return (EXIT_SUCCESS);
}
