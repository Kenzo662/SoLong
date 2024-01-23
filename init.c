/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:14:04 by klopez            #+#    #+#             */
/*   Updated: 2024/01/21 17:30:08 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_data(t_data *data)
{
    data->utils.k = 0;
    data->utils.countC = 0;
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, data->axes.x * 64, data->axes.y * 64, "so_long");
    data->textures = (t_textures *)malloc(sizeof(t_textures));
    data->player.p_pos.x = 0;
    data->player.p_pos.y = 0;
    data->player.destpos.x = 0;
    data->player.destpos.y = 0;
    data->player.side = 0;
    data->utils.linenumber = 0;
    data->utils.linelen = 0;
    data->utils.i = 0;
    data->utils.j = 0;
    data->utils.k = 0;
    data->frame = 0;
    data->clock = 0;
}
char	*change_path(char *textures, int i)
{
	char	*number;
	char	*str;
	char	*path;

	number = ft_itoa(i);
	str = ft_strjoin(textures, number);
	free(number);
	path = ft_strjoin(str, ".xpm");
	free(str);
	return (path);
}

void    init_textures(t_data *data)
{

    data->textures->exit = (t_img *)malloc(sizeof(t_img));
    data->textures->ennemies = (t_img *)malloc(sizeof(t_img));
    data->textures->wall.img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/sol.xpm", &(int){0}, &(int){0});
    data->textures->ground.img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/sol1.xpm", &(int){0}, &(int){0});
    data->textures->exit[0].img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/exit.xpm", &(int){0}, &(int){0});
    data->textures->ground.addr= mlx_get_data_addr(data->textures->ground.img, &data->textures->ground.bpp, 
    &data->textures->ground.size_line, &data->textures->ground.endian);
    data->textures->ennemies[0] = transparance(data->mlx, data->textures->ground, "./Sprites/skins/BuuFace.xpm");
}

void    init_collec(t_data *data)
{
    int i = 0;
    char *path;
    data->textures->collec = (t_img *)malloc(sizeof(t_img) * 7);
    while(i < 7)
    {
        path = change_path("./Sprites/items/Crystal", i);
        data->textures->collec[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

void    init_player(t_data *data)
{
    data->textures->player = (t_img *)malloc(sizeof(t_img) * 2);
    int i = 0;
    char *path;
    while(i < 2)
    {
        path = change_path("./Sprites/skins/Broly", i);
        data->textures->player[i] = transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

