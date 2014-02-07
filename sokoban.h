#ifndef SOKOBAN_H
# define SOKOBAN_H

# include <stdlib.h>
# include <unistd.h>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>

# define square_size    34
# define nb_square_vert 12
# define nb_square_hor  12
# define WIDTH          square_size * nb_square_vert
# define HEIGHT         square_size * nb_square_hor

typedef struct      t_list
{
    SDL_Surface     *screen;
}                   s_list;

void    ft_game(s_list env);

#endif
