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
    int i = 0, j = 0, k = 0;
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
    //img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
    while (i < data.axes.y)
    {
        j = 0;
        while(j < data.axes.x)
        {
            if (data.map[i][j] == '1')
                mlx_put_image_to_window(data.mlx, data.win , data.textures->wall.img , j * 64, i * 64);
            else if (data.map[i][j] == '0')
                mlx_put_image_to_window(data.mlx, data.win, data.textures->ground.img , j * 64, i * 64);
            else if (data.map[i][j] == 'E')
                mlx_put_image_to_window(data.mlx, data.win, data.textures->exit[0].img , j * 64, i * 64);
            else if (data.map[i][j] == 'P')
            {
                mlx_put_image_to_window(data.mlx, data.win, data.textures->player[0].img , j * 64, i * 64);
                data.player.p_pos.x = j;
                data.player.p_pos.y = i;
            }
            else if (data.map[i][j] == 'C')
            {
                mlx_put_image_to_window(data.mlx, data.win, data.textures->collec[k].img , j * 64, i * 64);
                k++;
                if (k == 7)
                    k = 0;
                data.utils.countC++;
            }
            j++;
        }
        i++;
    }
    mlx_key_hook(data.win, keyboard, &data);
    mlx_loop(data.mlx);
} 
