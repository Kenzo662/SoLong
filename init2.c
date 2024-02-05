/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:25:21 by klopez            #+#    #+#             */
/*   Updated: 2024/02/05 18:56:43 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_attack(t_data *data)
{
	char	*path;

	data->textures->player_attack = (t_img *)malloc(sizeof(t_img) * 16);
	while (data->utils.i_attack < 16)
	{
		path = change_path("./Sprites/attack/attack", data->utils.i_attack);
		data->textures->player_attack[data->utils.i_attack]
			= transparance(data->mlx, data->textures->ground, path);
		data->utils.i_attack++;
		free(path);
	}
}

void	init_destpos(t_data *data)
{
	if (data->player.attack_side == 0)
	{
		data->player.destpos.x = data->player.p_pos.x;
		data->player.destpos.y = data->player.p_pos.y + 1;
	}
	if (data->player.attack_side == 4)
	{
		data->player.destpos.x = data->player.p_pos.x + 1;
		data->player.destpos.y = data->player.p_pos.y;
	}
	if (data->player.attack_side == 8)
	{
		data->player.destpos.x = data->player.p_pos.x;
		data->player.destpos.y = data->player.p_pos.y - 1;
	}
	if (data->player.attack_side == 12)
	{
		data->player.destpos.x = data->player.p_pos.x - 1;
		data->player.destpos.y = data->player.p_pos.y;
	}
}

void	init_startenemies(t_data *data)
{
	char	*path;

	data->textures->buu_start = (t_img *)malloc(sizeof(t_img) * 15);
	while (data->utils.i_starte < 15)
	{
		path = change_path("./Sprites/start/StartB", data->utils.i_starte);
		data->textures->buu_start[data->utils.i_starte]
			= transparance(data->mlx, data->textures->ground, path);
		data->utils.i_starte++;
		free(path);
	}
}

void	init_enemiesdeath(t_data *data)
{
	char	*path;

	data->textures->buu_death = (t_img *)malloc(sizeof(t_img) * 10);
	while (data->utils.i_death < 10)
	{
		path = change_path("./Sprites/BuuDeath/Death", data->utils.i_death);
		data->textures->buu_death[data->utils.i_death]
			= transparance(data->mlx, data->textures->ground, path);
		data->utils.i_death++;
		free(path);
	}
}

void	init_exit(t_data *data)
{
	int		i;
	char	*path;

	i = 0;
	data->textures->exit = (t_img *)malloc(sizeof(t_img) * 2);
	while (i < 2)
	{
		path = change_path("./Sprites/textures/exit", i);
		data->textures->exit[i] = transparance(data->mlx,
				data->textures->ground, path);
		i++;
		free(path);
	}
}
