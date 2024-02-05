/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:11:09 by klopez            #+#    #+#             */
/*   Updated: 2024/01/29 14:22:06 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	attack_anim(t_data *data)
{
	int	i;
	int	j;

	init_destpos(data);
	i = 0;
	j = 0;
	while (i < 4)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->player_attack[data->player.attack_side + i].img,
			data->player.p_pos.x * 64, data->player.p_pos.y * 64);
		mlx_do_sync(data->mlx);
		usleep(25000);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->player[data->player.side + 2].img, data->player.p_pos.x
		* 64, data->player.p_pos.y * 64);
	if (data->map[data->player.destpos.y][data->player.destpos.x] == 'Z')
		attack_anim2(data, j);
}

void	attack_anim2(t_data *data, int j)
{
	while (j < 10)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->buu_death[j].img, data->player.destpos.x * 64,
			data->player.destpos.y * 64);
		mlx_do_sync(data->mlx);
		usleep(25000);
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img,
		data->player.destpos.x * 64, data->player.destpos.y * 64);
	data->map[data->player.destpos.y][data->player.destpos.x] = '0';
}

void	enemies_attack_anim(t_data *data)
{
	while (data->utils.loopcount < 2)
	{
		while (data->utils.loop < 30000)
		{
			data->utils.loop++;
			return ;
		}
		printattackanim(data,
			data->textures->enemiesattack[data->utils.loopcount + 6].img);
		data->utils.loopcount++;
		data->utils.loop = 0;
	}
	data->utils.loopcount = 0;
}

void	enemies_anim(t_data *data)
{
	while (data->utils.loopcount1 < 6)
	{
		while (data->utils.loop1 < 5000)
		{
			data->utils.loop1++;
			return ;
		}
		printchar(data,
			data->textures->enemiesattack[data->utils.loopcount1].img);
		data->utils.loopcount1++;
		data->utils.loop1 = 0;
	}
	data->utils.loopcount1 = 0;
}
