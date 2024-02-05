/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by klopez            #+#    #+#             */
/*   Updated: 2024/02/05 20:03:02 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	*path;
	t_data	data;
	int		fd;

	data.map = NULL;
	if (ac != 2)
	{
		path = "./map.ber";
	}
	else
		path = av[1];
	malloctab(&data, path);
	fd = open(path, O_RDONLY);
	checkmap(&data, fd);
	init_data(&data);
	printmap(&data);
	mlx_loop_hook(data.mlx, startenemiesanim, &data);
	mlx_key_hook(data.win, keyboard, &data);
	mlx_hook(data.win, 17, 0, leave, &data);
	mlx_loop(data.mlx);
}

int	leave(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

void	endgame(t_data *data)
{
	init_destpos(data);
	if (data->map[data->player.destpos.y][data->player.destpos.x] == 'E')
		leave(data);
}

void	init_all_e_pos(t_data *data, int side, int i, int j)
{
	data->player.enemiespos.x = j;
	data->player.enemiespos.y = i;
	init_destpos(data);
	init_enemiesdestpos(data, side);
}

void	destoy_img(t_data *data, int imgnbr, void *img)
{
	mlx_destroy_image(data->mlx, data->textures->ground.img);
	mlx_destroy_image(data->mlx, data->textures->exit[0].img);
	mlx_destroy_image(data->mlx, data->textures->exit[1].img);
	int i;

	i = 0;
	while (i < imgnbr)
	{
		//mlx_destroy_image(data->mlx, data->textures->img[i].img);
		i++;
	}
}
