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


void    moves(t_data *data)
{
    if (walkable(data, data->player.destpos) == 1)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img
        , data->player.p_pos.x * 64, data->player.p_pos.y  * 64);
        mlx_put_image_to_window(data->mlx, data->win, data->textures->player[0].img
        , data->player.destpos.x * 64, data->player.destpos.y  * 64);
        data->player.p_pos = data->player.destpos;
        printf("x = %d y = %d\n", data->player.p_pos.x, data->player.p_pos.y);
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
