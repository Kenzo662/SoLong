/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:06:37 by klopez            #+#    #+#             */
/*   Updated: 2024/01/21 18:03:49 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int    walkable(t_data *data, t_axes pos)
{
    if (data->map[pos.y][pos.x] == '1')
        return(0);
    return(1);
}
void    moves(t_data *data)
{
    if (walkable(data, data->player.destpos) == 1)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img
        , data->player.p_pos.x * 64, data->player.p_pos.y  * 64);
        mlx_put_image_to_window(data->mlx, data->win, data->textures->player[0].img
        , data->player.destpos.x * 64, data->player.destpos.y  * 64);
        data->player.p_pos = data->player.destpos;
    }
    
}

void    moveup(t_data *data)
{
    data->player.destpos.x = data->player.p_pos.x;
    data->player.destpos.y = data->player.p_pos.y - 1;
    moves(data);
}

void    movedown(t_data *data)
{
    data->player.destpos.x = data->player.p_pos.x;
    data->player.destpos.y = data->player.p_pos.y + 1;
    moves(data);
}

void    moveleft(t_data *data)
{
    
    data->player.destpos.x = data->player.p_pos.x - 1;
    data->player.destpos.y = data->player.p_pos.y;
    moves(data);
}

void    moveright(t_data *data)
{
    data->player.destpos.x = data->player.p_pos.x + 1;
    data->player.destpos.y = data->player.p_pos.y;
    moves(data);
}

int	keyboard(int keycode, t_data *data)
{
	if (keycode == W)
	{
		moveup(data);
    }
	else if (keycode == A)
	{
		moveleft(data);
	}
	else if (keycode == S)
	{
		movedown(data);
	}
	else if (keycode == D)
	{
		moveright(data);
	}
	return (0);
}