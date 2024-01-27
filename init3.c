#include "so_long.h"

void    init_enemiesattack(t_data *data)
{
    data->textures->enemiesattack = (t_img *)malloc(sizeof(t_img) * 2);
    int i = 0;
    char *path;
    while(i < 2)
    {
        path = change_path("./Sprites/attack/attackB", i);
        data->textures->enemiesattack[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

void    init_enemiesdestpos(t_data *data)
{
    
}