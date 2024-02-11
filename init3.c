/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:25:28 by klopez            #+#    #+#             */
/*   Updated: 2024/02/11 05:11:41 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemiesattack(t_data *data)
{
	char	*path;

	data->textures->enemiesattack = (t_img *)malloc(sizeof(t_img) * 8);
	while (data->utils.i_enemiesattack < 8)
	{
		path = change_path("./Sprites/attack/attackB",
				data->utils.i_enemiesattack);
		data->textures->enemiesattack[data->utils.i_enemiesattack]
			= transparance(data->mlx, data->textures->ground, path);
		data->utils.i_enemiesattack++;
		free(path);
	}
}

void	init_enemiesdestpos(t_data *data, int side)
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

void	init_enemiespos(t_data *data)
{
	data->player.enemiespos.x = data->utils.j;
	data->player.enemiespos.y = data->utils.i;
}

void	init_start(t_data *data)
{
	char	*path;

	data->textures->player_start = (t_img *)malloc(sizeof(t_img) * 6);
	while (data->utils.i_startp < 6)
	{
		path = change_path("./Sprites/start/Start",
				data->utils.i_startp);
		data->textures->player_start[data->utils.i_startp]
			= transparance(data->mlx, data->textures->ground, path);
		data->utils.i_startp++;
		free(path);
	}
}

void	init_p_pos(t_data *data)
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
			if (data->map[i][j] == 'P')
			{
				data->player.p_pos.x = j;
				data->player.p_pos.y = i;
			}
			j++;
		}
		i++;
	}
}
