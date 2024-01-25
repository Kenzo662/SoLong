#include "so_long.h"

void    init_attack(t_data *data)
{
    data->textures->player_attack = (t_img *)malloc(sizeof(t_img) * 16);
    int i = 0;
    char *path;
    while(i < 16)
    {
        path = change_path("./Sprites/attack/attack", i);
        data->textures->player_attack[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

void    init_destpos(t_data *data)
{
    if(data->player.attack_side == 0)
    {
        data->player.destpos.x = data->player.p_pos.x;
        data->player.destpos.y = data->player.p_pos.y + 1;
    }
    if(data->player.attack_side == 4)
    {
        data->player.destpos.x = data->player.p_pos.x + 1;
        data->player.destpos.y = data->player.p_pos.y;
    }
    if(data->player.attack_side == 8)
    {
        data->player.destpos.x = data->player.p_pos.x;
        data->player.destpos.y = data->player.p_pos.y - 1;
    }
    if(data->player.attack_side == 12)
    {
        data->player.destpos.x = data->player.p_pos.x - 1;
        data->player.destpos.y = data->player.p_pos.y;
    }
}

void    init_startenemies(t_data *data)
{
    data->textures->buu_start = (t_img *)malloc(sizeof(t_img) * 8);
    int i = 0;
    char *path;
    while(i < 8)
    {
        path = change_path("./Sprites/start/StartB", i);
        data->textures->buu_start[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

void    init_enemiesdeath(t_data *data)
{
    data->textures->buu_death = (t_img *)malloc(sizeof(t_img) * 10);
    int i = 0;
    char *path;
    while(i < 10)
    {
        path = change_path("./Sprites/BuuDeath/Death", i);
        data->textures->buu_death[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

void    init_exit(t_data *data)
{
    data->textures->exit = (t_img *)malloc(sizeof(t_img) * 2);
    int i = 0;
    char *path;
    while(i < 2)
    {
        path = change_path("./Sprites/textures/exit", i);
        data->textures->exit[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}