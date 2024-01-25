/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:06:37 by klopez            #+#    #+#             */
/*   Updated: 2024/01/23 17:33:13 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    moves(t_data *data)
{
    if (walkable(data, data->player.destpos) == 1)
    {
        printdirection(data);  
    } 
}

void    moveup(t_data *data)
{
    data->player.side = 6;
    data->player.attack_side = 8;
    data->player.destpos.x = data->player.p_pos.x;
    data->player.destpos.y = data->player.p_pos.y - 1;
    data->utils.whichside = 1;
    if (data->map[data->player.destpos.y][data->player.destpos.x] == 'C')
    {
        data->map[data->player.destpos.y][data->player.destpos.x] = '0';
        data->utils.collect++;
        printf("collect = %d\n", data->utils.collect);
    }
    if (data->utils.collect == data->utils.countC)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->textures->exit[1].img, data->player.exitpos.x * 64, data->player.exitpos.y * 64);
        endgame(data);
    }
    moves(data);
}

void    movedown(t_data *data)
{
    data->player.side = 0;
    data->player.attack_side = 0;
    data->player.destpos.x = data->player.p_pos.x;
    data->player.destpos.y = data->player.p_pos.y + 1;
    data->utils.whichside = 0;
    if (data->map[data->player.destpos.y][data->player.destpos.x] == 'C')
    {
        data->map[data->player.destpos.y][data->player.destpos.x] = '0';
        data->utils.collect++;
        printf("collect = %d\n", data->utils.collect);
    }
    if (data->utils.collect == data->utils.countC)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->textures->exit[1].img, data->player.exitpos.x * 64, data->player.exitpos.y * 64);
        endgame(data);
    }
    moves(data);
}

void    moveleft(t_data *data)
{
    data->player.side = 9;
    data->player.attack_side = 12;
    data->player.destpos.x = data->player.p_pos.x - 1;
    data->player.destpos.y = data->player.p_pos.y;
    data->utils.whichside = 3;
    if (data->map[data->player.destpos.y][data->player.destpos.x] == 'C')
    {
        data->map[data->player.destpos.y][data->player.destpos.x] = '0';
        data->utils.collect++;
        printf("collect = %d\n", data->utils.collect);
    }
    if (data->utils.collect == data->utils.countC)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->textures->exit[1].img, data->player.exitpos.x * 64, data->player.exitpos.y * 64);
        endgame(data);
    }
    moves(data);
}

void    moveright(t_data *data)
{   
    data->player.side = 3;
    data->player.attack_side = 4;
    data->player.destpos.x = data->player.p_pos.x + 1;
    data->player.destpos.y = data->player.p_pos.y;
    data->utils.whichside = 4;
    if (data->map[data->player.destpos.y][data->player.destpos.x] == 'C')
    {
        data->map[data->player.destpos.y][data->player.destpos.x] = '0';
        data->utils.collect++;
        printf("collect = %d\n", data->utils.collect);
    }
    if (data->utils.collect == data->utils.countC)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->textures->exit[1].img, data->player.exitpos.x * 64, data->player.exitpos.y * 64);
        endgame(data);
    }
    moves(data);
}

