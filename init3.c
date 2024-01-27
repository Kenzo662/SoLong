#include "so_long.h"

void    init_enemiesattack(t_data *data)
{
    data->textures->enemiesattack = (t_img *)malloc(sizeof(t_img) * 4);
    int i = 0;
    char *path;
    while(i < 4)
    {
        path = change_path("./Sprites/attack/attackB", i);
        data->textures->enemiesattack[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

void    init_enemiesdestpos(t_data *data, int side)
{
    if (side == 0)
    {
        data->player.e_destpos.x = data->player.enemiespos.x;
        data->player.e_destpos.y = data->player.enemiespos.y + 1;
    }
    if (side == 1)
    {
        data->player.e_destpos.x = data->player.enemiespos.x;
        data->player.e_destpos.y = data->player.enemiespos.y - 1;
    }
    if (side == 2)
    {
        data->player.e_destpos.x = data->player.enemiespos.x + 1;
        data->player.e_destpos.y = data->player.enemiespos.y;
    }
    if (side == 3)
    {
        data->player.e_destpos.x = data->player.enemiespos.x - 1;
        data->player.e_destpos.y = data->player.enemiespos.y;
    }
}