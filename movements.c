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
void    moves(t_data *data, t_axes dest)
{
    if (walkable(data, dest) == 1)
    {
        transparance(data->mlx, data->textures->ground, "/Sprites/skins/BrolyFace0.xpm");
    }
    
}

void    moveup(t_data *data)
{
    t_axes dest;
    dest.x = data->player.p_pos.x;
    dest.y = data->player.p_pos.y - 1;
    printf("y = %d\n", dest.y);
    printf("x = %d\n", dest.x);
    moves(data, dest);
}

void    movedown(t_data *data)
{
    t_axes dest;
    dest.x = data->player.p_pos.x;
    dest.y = data->player.p_pos.y + 1;
        printf("y = %d\n", dest.y);
    printf("x = %d\n", dest.x);
    moves(data, dest);
}

void    moveleft(t_data *data)
{
    t_axes dest;
    dest.x = data->player.p_pos.x - 1;
    dest.y = data->player.p_pos.y;
    moves(data, dest);
        printf("y = %d\n", dest.y);
    printf("x = %d\n", dest.x);
}

void    moveright(t_data *data)
{
    t_axes dest;
    dest.x = data->player.p_pos.x + 1;
    dest.y = data->player.p_pos.y;
    moves(data, dest);
        printf("y = %d\n", dest.y);
    printf("x = %d\n", dest.x);
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