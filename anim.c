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

int    startenemiesanim(t_data *data)
{
	while(data->utils.l < 15)
	{
		while (data->utils.loop < 400)
		{
			data->utils.loop++;
			return(1);
		}
		printchar(data, data->textures->buu_start[data->utils.l].img);
		data->utils.l++;
		data->utils.loop = 0;
	}
	return(0);
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
    	usleep(37500);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side + 2].img, data->player.p_pos.x * 64, data->player.p_pos.y * 64);
	if (data->map[data->player.destpos.y][data->player.destpos.x] == 'Z')
	{
		while(j < 10)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->textures->buu_death[j].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
			mlx_do_sync(data->mlx);
			usleep(37500);
			j++;
		}
		mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img, data->player.destpos.x * 64, data->player.destpos.y * 64);
		data->map[data->player.destpos.y][data->player.destpos.x] = '0';
	}
}

void	enemies_attack_anim(t_data *data)
{
	
}