/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:25:28 by klopez            #+#    #+#             */
/*   Updated: 2024/02/04 15:25:29 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemiesattack(t_data *data)
{
	int		i;
	char	*path;

	data->textures->enemiesattack = (t_img *)malloc(sizeof(t_img) * 8);
	i = 0;
	while (i < 8)
	{
		path = change_path("./Sprites/attack/attackB", i);
		data->textures->enemiesattack[i] = transparance(data->mlx,
				data->textures->ground, path);
		i++;
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
	int		i;
	char	*path;

	data->textures->player_start = (t_img *)malloc(sizeof(t_img) * 6);
	i = 0;
	while (i < 6)
	{
		path = change_path("./Sprites/start/Start", i);
		data->textures->player_start[i] = transparance(data->mlx,
				data->textures->ground, path);
		i++;
		free(path);
	}
}
