/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by klopez            #+#    #+#             */
/*   Updated: 2024/01/21 17:52:22 by klopez           ###   ########.fr       */
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
    init_textures(&data);
    init_collec(&data);
    init_player(&data);
    printimg(&data);
    mlx_key_hook(data.win, keyboard, &data);
    mlx_loop_hook(data.mlx, &clock, &data);
    mlx_loop(data.mlx);
} 

void    printimg(t_data *data)
{
     while (data->utils.i < data->axes.y)
    {
        data->utils.j = 0;
        while(data->utils.j < data->axes.x)
        {
            if (data->map[data->utils.i][data->utils.j] == '1')
                mlx_put_image_to_window(data->mlx, data->win , data->textures->wall.img , data->utils.j * 64, data->utils.i * 64);
            else if (data->map[data->utils.i][data->utils.j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img , data->utils.j * 64, data->utils.i * 64);
            else if (data->map[data->utils.i][data->utils.j] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->textures->exit[0].img , data->utils.j * 64, data->utils.i * 64);
            else if (data->map[data->utils.i][data->utils.j] == 'P')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->textures->player[0].img , data->utils.j * 64, data->utils.i * 64);
                data->player.p_pos.x = data->utils.j;
                data->player.p_pos.y = data->utils.i;
            }
            else if (data->map[data->utils.i][data->utils.j] == 'C')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->textures->collec[data->utils.k].img , data->utils.j * 64, data->utils.i * 64);
                data->utils.k++;
                if (data->utils.k == 7)
                    data->utils.k = 0;
                data->utils.countC++;
            }
            else if (data->map[data->utils.i][data->utils.j] == 'Z')
                mlx_put_image_to_window(data->mlx, data->win, data->textures->ennemies[0].img , data->utils.j * 64, data->utils.i * 64);
            data->utils.j++;
        }
        data->utils.i++;
    }
}
