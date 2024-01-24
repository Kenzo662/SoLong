/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:11:09 by klopez            #+#    #+#             */
/*   Updated: 2024/01/24 17:27:51 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* int     clock(t_data *data)
{
    if (data->clock == data->clockcount)
	{
		init_clock(data);
		printf("count = %d\n", data->clockcount);
		data->clock = 0;
		if (data->frame == 1)
			data->frame = 0;
		else
			data->frame = 1;
		 mlx_do_sync(data->mlx);
		usleep(300000); 
	}
	else
		data->clock++;
	return(0);
}


void	playeranim(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side + data->frame].img,
	data->player.p_pos.x * 64, data->player.p_pos.y * 64);
}

void	init_clock(t_data *data)
{
	if (data->player.side < 2)
		data->clockcount = 75000;
	if (data->player.side > 1 && data->player.side < 4)
		data->clockcount = 12500;
} */

void    startplayeranim(t_data *data)
{
	int i = 0;
	while(i < 6)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->textures->player_start[i].img , data->player.p_pos.x * 64, data->player.p_pos.y * 64);
		mlx_do_sync(data->mlx);
		usleep(300000);
		i++;
	}
}