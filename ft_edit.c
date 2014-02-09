#include "sokoban.h"

void    ft_edit(s_list env)
{
    SDL_Rect position;
    SDL_Event event;

    int continu = 1, clicGaucheEnCours = 0, clicDroitEnCours = 0;
    int i = 0, j = 0;

    env.remain_obj = WALL;
    env.wall = IMG_Load("mur.jpg");
    env.box = IMG_Load("caisse.jpg");
    env.obj = IMG_Load("objectif.png");
    env.mario_now = IMG_Load("mario_bas.gif");

    if (!ft_load_map(env.map))
        exit(EXIT_FAILURE);
    while (continu)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continu = 0;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                env.map[event.button.x / square_size][event.button.y / square_size] = env.remain_obj;
                clicGaucheEnCours = 1;
            }
            else if (event.button.button == SDL_BUTTON_RIGHT)
            {
                env.map[event.button.x / square_size][event.button.y /square_size] = EMPTY;
                clicDroitEnCours = 1;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT)
                clicGaucheEnCours = 0;
            else if (event.button.button == SDL_BUTTON_RIGHT)
                clicDroitEnCours = 0;
            break;
        case SDL_MOUSEMOTION:
            if (clicGaucheEnCours)
            {
                env.map[event.motion.x / square_size][event.motion.y / square_size] = env.remain_obj;
            }
            else if (clicDroitEnCours)
            {
                env.map[event.motion.x / square_size][event.motion.y / square_size] = EMPTY;
            }
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    continu = 0;
                    break;
                case SDLK_s:
                    ft_save_map(env.map);
                    break;
                case SDLK_c:
                    ft_load_map(env.map);
                    break;
                case SDLK_KP1:
                    env.remain_obj = WALL;
                    break;
                case SDLK_KP2:
                    env.remain_obj = BOX;
                    break;
                case SDLK_KP3:
                    env.remain_obj = OBJ;
                    break;
                case SDLK_KP4:
                    env.remain_obj = MARIO;
                    break;
                default:
                    break;
            }
            break;
                default:
                    break;
        }
            SDL_FillRect(env.screen, NULL, SDL_MapRGB(env.screen->format, 255, 255, 255));
for (i = 0 ; i < nb_square_hor ; i++)
{
    for (j = 0 ; j < nb_square_vert ; j++)
    {
        position.x = i * square_size;
        position.y = j * square_size;
        switch(env.map[i][j])
        {
            case WALL:
                SDL_BlitSurface(env.wall, NULL, env.screen, &position);
                break;
            case BOX:
                SDL_BlitSurface(env.box, NULL, env.screen, &position);
                break;
            case OBJ:
                SDL_BlitSurface(env.obj, NULL, env.screen, &position);
                break;
            case MARIO:
                SDL_BlitSurface(env.mario_now, NULL, env.screen, &position);
                break;
        }
    }
}
SDL_Flip(env.screen);
        }

SDL_FreeSurface(env.wall);
SDL_FreeSurface(env.box);
SDL_FreeSurface(env.obj);
SDL_FreeSurface(env.mario_now);
}
