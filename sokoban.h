#ifndef SOKOBAN_H
# define SOKOBAN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# define square_size    34
# define nb_square_vert 12
# define nb_square_hor  12
# define WIDTH          square_size * nb_square_hor
# define HEIGHT         square_size * nb_square_vert

enum {EMPTY, WALL, BOX, OBJ, MARIO, BOX_OK};

typedef struct      t_list
{
    SDL_Surface     *screen;
    SDL_Surface     *mario[4];
    SDL_Surface     *wall;
    SDL_Surface     *box;
    SDL_Surface     *box_ok;
    SDL_Surface     *obj;
    SDL_Surface     *mario_now;
    SDL_Rect        player_pos;
    int             remain_obj;
    int             map[nb_square_hor][nb_square_vert];
}                   s_list;

void    ft_game(s_list env);
void    ft_move(int map[][nb_square_vert], SDL_Rect *pos, int dir);
int     ft_load_map(int map[][nb_square_vert]);
int     ft_save_map(int map[][nb_square_vert]);
void    ft_edit(s_list env);

#endif
