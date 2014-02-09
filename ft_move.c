#include "sokoban.h"

static void deplacerCaisse(int *premiereCase, int *secondeCase)
{
    if (*premiereCase == BOX || *premiereCase == BOX_OK)
    {
        if (*secondeCase == OBJ)
            *secondeCase = BOX_OK;
        else
            *secondeCase = BOX;

        if (*premiereCase == BOX_OK)
            *premiereCase = OBJ;
        else
            *premiereCase = EMPTY;
    }
}

void    ft_move(int map[][nb_square_vert], SDL_Rect *pos, int dir)
{
    switch(dir)
    {
    case 0:
        if (pos->y - 1 < 0)
            break;
        if (map[pos->x][pos->y - 1] == WALL)
            break;
        if ((map[pos->x][pos->y - 1] == BOX || map[pos->x][pos->y - 1] == BOX_OK) &&
            (pos->y - 2 < 0 || map[pos->x][pos->y - 2] == WALL ||
            map[pos->x][pos->y - 2] == BOX || map[pos->x][pos->y - 2] == BOX_OK))
            break;
        deplacerCaisse(&map[pos->x][pos->y - 1], &map[pos->x][pos->y - 2]);
        pos->y--;
        break;
    case 1:
        if (pos->y + 1 < 0)
            break;
        if (map[pos->x][pos->y + 1] == WALL)
            break;
        if ((map[pos->x][pos->y + 1] == BOX || map[pos->x][pos->y + 1] == BOX_OK) &&
            (pos->y + 2 < 0 || map[pos->x][pos->y + 2] == WALL ||
            map[pos->x][pos->y + 2] == BOX || map[pos->x][pos->y + 2] == BOX_OK))
            break;
        deplacerCaisse(&map[pos->x][pos->y + 1], &map[pos->x][pos->y + 2]);
        pos->y--;
        break;
    case 2:
        if (pos->x - 1 < 0)
            break;
        if (map[pos->x - 1][pos->y] == WALL)
            break;
        if ((map[pos->x - 1][pos->y] == BOX || map[pos->x - 1][pos->y] == BOX_OK) &&
            (pos->x - 2 < 0 || map[pos->x - 2][pos->y] == WALL ||
            map[pos->x - 2][pos->y] == BOX || map[pos->x - 2][pos->y] == BOX_OK))
            break;
        deplacerCaisse(&map[pos->x - 1][pos->y], &map[pos->x - 2][pos->y]);
        pos->x--;
        break;
    case 3:
        if (pos->x + 1 < 0)
            break;
        if (map[pos->x + 1][pos->y] == WALL)
            break;
        if ((map[pos->x + 1][pos->y] == BOX || map[pos->x + 1][pos->y] == BOX_OK) &&
            (pos->x + 2 < 0 || map[pos->x + 2][pos->y] == WALL ||
            map[pos->x + 2][pos->y] == BOX || map[pos->x + 2][pos->y] == BOX_OK))
            break;
        deplacerCaisse(&map[pos->x + 1][pos->y], &map[pos->x + 2][pos->y]);
        pos->x++;
        break;
    }
}
