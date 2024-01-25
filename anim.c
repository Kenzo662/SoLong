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
		usleep(100000);
		mlx_do_sync(data->mlx);
		i++;
	}
}

void    startenemiesanim(t_data *data)
{
	int i = 0;
	while(i < 7)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->textures->buu_start[i].img , data->player.enemiespos.x * 64, data->player.enemiespos.y * 64);
		usleep(75000);
		mlx_do_sync(data->mlx);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->textures->ennemies[0].img , data->player.enemiespos.x * 64, data->player.enemiespos.y * 64);
}

void    printdirection(t_data *data)
{
    mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
    mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img, data->player.p_pos.x * 64, data->player.p_pos.y * 64);
    data->player.p_pos = data->player.destpos;
    mlx_do_sync(data->mlx);
    usleep(37500);
    mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side + 1].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
    mlx_do_sync(data->mlx);
    usleep(17000);
    mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side + 2].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
}

void	attack_anim(t_data *data)
{
	init_destpos(data);
	int i = 0;
	int j = 0;
	while(i < 4)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->textures->player_attack[data->player.attack_side + i].img, data->player.p_pos.x * 64, data->player.p_pos.y * 64);
		mlx_do_sync(data->mlx);
    	usleep(42500);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side + 2].img, data->player.p_pos.x * 64, data->player.p_pos.y * 64);
	if (data->map[data->player.destpos.y][data->player.destpos.x] == 'Z')
	{
		while(j < 10)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->textures->buu_death[j].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
			mlx_do_sync(data->mlx);
			usleep(42500);
			j++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img, data->player.destpos.x * 64, data->player.destpos.y * 64);
		data->map[data->player.destpos.y][data->player.destpos.x] = '0';
	}
}