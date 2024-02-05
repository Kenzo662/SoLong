/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animstart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:34 by klopez            #+#    #+#             */
/*   Updated: 2024/02/01 13:56:57 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	startplayeranim(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->player_start[i].img, data->player.p_pos.x * 64,
			data->player.p_pos.y * 64);
		usleep(75000);
		mlx_do_sync(data->mlx);
		i++;
	}
}

int	startenemiesanim(t_data *data)
{
	while (data->utils.l < 15)
	{
		while (data->utils.loop < 2700)
		{
			data->utils.loop++;
			return (1);
		}
		printchar(data, data->textures->buu_start[data->utils.l].img);
		data->utils.l++;
		data->utils.loop = 0;
	}
	enemies_anim(data);
	enemies_attack_anim(data);
	return (0);
}
