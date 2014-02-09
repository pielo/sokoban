#include "sokoban.h"

static void     ft_init(s_list *env)
{
    int         i;
    int         j;

    (*env).remain_obj = 0;
    (*env).wall = IMG_Load("mur.jpg");
    (*env).box = IMG_Load("caisse.jpg");
    (*env).box_ok = IMG_Load("caisse_ok.jpg");
    (*env).obj = IMG_Load("objectif.png");
    (*env).mario[0] = IMG_Load("mario_haut.gif");
    (*env).mario[1] = IMG_Load("mario_bas.gif");
    (*env).mario[2] = IMG_Load("mario_gauche.gif");
    (*env).mario[3] = IMG_Load("mario_droite.gif");
    (*env).mario_now = (*env).mario[1];
    if (!ft_load_map((*env).map))
        exit(EXIT_FAILURE);
    i = 0;
    while (i < nb_square_hor)
    {
        j = 0;
        while (j < nb_square_vert)
        {
            if ((*env).map[i][j] == MARIO)
            {
                (*env).player_pos.x = i;
                (*env).player_pos.y = j;
                (*env).map[i][j] = EMPTY;
            }
            j++;
        }
        i++;
    }
}

void            ft_game(s_list env)
{
    SDL_Rect    pos;
    SDL_Event   event;
    int         continu = 1;
    int         i;
    int         j;

    ft_init(&env);
    SDL_EnableKeyRepeat(100, 100);
    while (continu)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
    case SDL_QUIT:
        continu = 0;
        break;
    case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
            case SDLK_ESCAPE:
                continu = 0;
                break;
            case SDLK_UP:
                env.mario_now = env.mario[0];
                ft_move(env.map, &(env.player_pos), 0);
                break;
            case SDLK_DOWN:
                env.mario_now = env.mario[1];
                ft_move(env.map, &(env.player_pos), 1);
                break;
            case SDLK_LEFT:
                env.mario_now = env.mario[2];
                ft_move(env.map, &(env.player_pos), 2);
                break;
            case SDLK_RIGHT:
                env.mario_now = env.mario[3];
                ft_move(env.map, &(env.player_pos), 3);
                break;
            default:
                break;
        }
        break;
            default:
                break;
    }

    SDL_FillRect(env.screen, NULL, SDL_MapRGB(env.screen->format, 255, 255, 255));

    env.remain_obj = 0;

    for (i = 0 ; i < nb_square_hor ; i++)
    {
        for (j = 0 ; j < nb_square_vert ; j++)
        {
            pos.x = i * square_size;
            pos.y = j * square_size;

            switch(env.map[i][j])
            {
                case WALL:
                    SDL_BlitSurface(env.wall, NULL, env.screen, &pos);
                    break;
                case BOX:
                    SDL_BlitSurface(env.box, NULL, env.screen, &pos);
                    break;
                case BOX_OK:
                    SDL_BlitSurface(env.box_ok, NULL, env.screen, &pos);
                    break;
                case OBJ:
                    SDL_BlitSurface(env.obj, NULL, env.screen, &pos);
                    env.remain_obj = 1;
                    break;
            }
        }
    }
    if (!env.remain_obj)
        continu = 0;
    pos.x = env.player_pos.x * square_size;
    pos.y = env.player_pos.y * square_size;
    SDL_BlitSurface(env.mario_now, NULL, env.screen, &pos);
    SDL_Flip(env.screen);
    }
    SDL_FreeSurface(env.wall);
    SDL_FreeSurface(env.box);
    SDL_FreeSurface(env.box_ok);
    SDL_FreeSurface(env.obj);
    for (i = 0 ; i < 4 ; i++)
        SDL_FreeSurface(env.mario[i]);
}
