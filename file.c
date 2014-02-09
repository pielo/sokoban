#include "sokoban.h"

int     ft_load_map(int map[][nb_square_vert])
{
    FILE* file = NULL;
    char ligneFichier[nb_square_hor * nb_square_vert + 1] = {0};
    int i = 0, j = 0;

    file = fopen("niveaux.lvl", "r");
    if (file == NULL)
        return 0;
    fgets(ligneFichier, nb_square_hor * nb_square_vert + 1, file);
    for (i = 0 ; i < nb_square_hor ; i++)
    {
        for (j = 0 ; j < nb_square_vert ; j++)
        {
            switch (ligneFichier[(i * nb_square_hor) + j])
            {
                case '0':
                    map[j][i] = 0;
                    break;
                case '1':
                    map[j][i] = 1;
                    break;
                case '2':
                    map[j][i] = 2;
                    break;
                case '3':
                    map[j][i] = 3;
                    break;
                case '4':
                    map[j][i] = 4;
                    break;
            }
        }
    }
    fclose(file);
    return 1;
}

int     ft_save_map(int map[][nb_square_vert])
{
    FILE* file = NULL;
    int i = 0, j = 0;

    file = fopen("niveaux.lvl", "w");
    if (file == NULL)
        return 0;

    for (i = 0 ; i < nb_square_hor ; i++)
    {
        for (j = 0 ; j < nb_square_vert ; j++)
        {
            fprintf(file, "%d", map[j][i]);
        }
    }

    fclose(file);
    return 1;
}
