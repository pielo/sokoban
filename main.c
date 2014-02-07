#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unistd.h>

int             main(int argc, char** argv)
{
    int         continu;
    SDL_Event   event;
    SDL_Surface *screen = NULL;
    SDL_Surface *img = NULL;
    SDL_Surface *sapin = NULL;
    SDL_Rect    positionfond;
    SDL_Rect    positionsapin;

    continu = 1;
    positionfond.x = 0;
    positionfond.y = 0;
    positionsapin.x = 500;
    positionsapin.y = 300;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        write(1, "Unable to init SDL\n", 20);
        return (EXIT_FAILURE);
    }
    if ((screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE)) < 0)
    {
        write(1, "impossible to create screen\n", 28);
        return (EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Sokoban", NULL);
    while(continu)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT || (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE))
            continu = 0;
        img = IMG_Load("lac_en_montagne.bmp");
        SDL_BlitSurface(img, NULL, screen, &positionfond);
        sapin = IMG_Load("sapin.png");
        SDL_BlitSurface(sapin, NULL, screen, &positionsapin);
        SDL_Flip(screen);
    }
    SDL_FreeSurface(img);
    SDL_Quit();
    return (EXIT_SUCCESS);
}
