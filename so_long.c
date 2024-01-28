/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by klopez            #+#    #+#             */
/*   Updated: 2024/01/24 17:26:33 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int main(int ac, char **av)
{
    char *path;
    t_data data;
    int fd;

    data.map = NULL;
    if (ac != 2)
    {
        path = "./map.ber";
    }
    else 
        path = av[1];
    MallocTab(&data, path);
    fd = open(path, O_RDONLY);
    Checkmap(&data, fd);
    init_data(&data);
    printmap(&data);
    mlx_loop_hook(data.mlx, startenemiesanim, &data);
    mlx_key_hook(data.win, keyboard, &data);
    mlx_loop(data.mlx);
} 

void    leave(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    exit(0);
}

void    endgame(t_data *data)
{
    init_destpos(data);
    if(data->map[data->player.destpos.y][data->player.destpos.x] == 'E')
        leave(data);
}