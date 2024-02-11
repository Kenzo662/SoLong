/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:04:15 by klopez            #+#    #+#             */
/*   Updated: 2024/02/11 03:57:14 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(t_data *data)
{
	while (data->utils.i < data->axes.y)
	{
		data->utils.j = 0;
		while (data->utils.j < data->axes.x)
		{
			printmapchar(data);
			if (data->map[data->utils.i][data->utils.j] == 'Z')
			{
				init_enemiespos(data);
				mlx_put_image_to_window(data->mlx, data->win,
					data->textures->ennemies[0].img, data->utils.j * 64,
					data->utils.i * 64);
			}
			else if (data->map[data->utils.i][data->utils.j] == 'E')
			{
				data->player.exitpos.x = data->utils.j;
				data->player.exitpos.y = data->utils.i;
				mlx_put_image_to_window(data->mlx, data->win, data->textures
					->exit[0].img, data->utils.j * 64, data->utils.i * 64);
			}
			data->utils.j++;
		}
		data->utils.i++;
	}
	startplayeranim(data);
}

void	printmapchar(t_data *data)
{
	if (data->map[data->utils.i][data->utils.j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->textures->wall.img,
			data->utils.j * 64, data->utils.i * 64);
	else if (data->map[data->utils.i][data->utils.j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->ground.img, data->utils.j * 64, data->utils.i * 64);
	else if (data->map[data->utils.i][data->utils.j] == 'P')
	{
		data->player.p_pos.x = data->utils.j;
		data->player.p_pos.y = data->utils.i;
	}
	else if (data->map[data->utils.i][data->utils.j] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->collec[data->utils.k].img, data->utils.j * 64,
			data->utils.i * 64);
		data->utils.k++;
		if (data->utils.k == 7)
			data->utils.k = 0;
	}
}

void	printchar(t_data *data, void *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->axes.y)
	{
		j = 0;
		while (j < data->axes.x)
		{
			if (data->map[i][j] == 'Z')
				mlx_put_image_to_window(data->mlx, data->win, img, j * 64, i
					* 64);
			j++;
		}
		i++;
	}
}

void	printattackanim(t_data *data, void *img)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->utils.side = -1;
	while (++data->utils.side < 4)
	{
		while (++i < data->axes.y)
		{
			j = -1;
			while (++j < data->axes.x)
				sideattackanim(data, i, j, img);
		}
		i = -1;
	}
}

void	sideattackanim(t_data *data, int i, int j, void *img)
{
	if (data->map[i][j] == 'Z')
	{
		data->player.enemiespos.x = j;
		data->player.enemiespos.y = i;
		init_enemiesdestpos(data, data->utils.side);
		if (data->map[data->player.e_destpos.y]
			[data->player.e_destpos.x] == '0')
		{
			mlx_put_image_to_window(data->mlx, data->win, img,
				data->player.e_destpos.x * 64, data->player.e_destpos.y * 64);
			if (data->utils.loopcount == 0)
			{
				if ((data->player.p_pos.x == data->player.e_destpos.x)
					&& (data->player.p_pos.y == data->player.e_destpos.y))
					leave(data);
			}
		}
	}
}
