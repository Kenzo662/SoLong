/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movementsutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:33:52 by klopez            #+#    #+#             */
/*   Updated: 2024/02/04 15:37:23 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walkable(t_data *data, t_axes pos)
{
	init_destpos(data);
	if (data->map[pos.y][pos.x] == '1' || (data->map[pos.y][pos.x] == 'Z')
		|| data->map[pos.y][pos.x] == 'E')
	{
		return (0);
	}
	return (1);
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

int	keyboard(int keycode, t_data *data)
{
	if (keycode == W)
		moveup(data);
	else if (keycode == A)
		moveleft(data);
	else if (keycode == D)
		moveright(data);
	else if (keycode == S)
		movedown(data);
	else if (keycode == E)
		attack_anim(data);
	else if (keycode == ESC)
		leave(data);
	return (0);
}

void	printdirection(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->player[data->player.side].img, data->player.destpos.x
		* 64, data->player.destpos.y * 64);
	mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img,
		data->player.p_pos.x * 64, data->player.p_pos.y * 64);
	data->player.p_pos = data->player.destpos;
	mlx_do_sync(data->mlx);
	usleep(17500);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->player[data->player.side + 1].img,
		data->player.destpos.x * 64, data->player.destpos.y * 64);
	mlx_do_sync(data->mlx);
	usleep(7500);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->player[data->player.side + 2].img,
		data->player.destpos.x * 64, data->player.destpos.y * 64);
}

int	find_enemies_destpos(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->utils.e_side = -1;
	while (++data->utils.e_side < 4)
	{
		while (++i < data->axes.y)
		{
			j = -1;
			while (++j < data->axes.x)
			{
				if (data->map[i][j] == 'Z')
				{
					init_all_e_pos(data, data->utils.e_side, i, j);
					if ((data->player.e_destpos.x == data->player.destpos.x)
						&& (data->player.e_destpos.y == data->player.destpos.y))
						return (1);
				}
			}
		}
		i = -1;
	}
	return (0);
}
