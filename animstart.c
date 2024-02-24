/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animstart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:20:34 by klopez            #+#    #+#             */
/*   Updated: 2024/02/13 16:38:33 by klopez           ###   ########.fr       */
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

void	printstring(t_data *data)
{
	char	*count;

	count = ft_itoa(data->utils.movecount);
	data->utils.str = ft_strjoin("Moves = ", count);
	mlx_put_image_to_window(data->mlx, data->win, data->textures->wall.img, 0,
		0);
	mlx_put_image_to_window(data->mlx, data->win, data->textures->wall.img, 64,
		0);
	mlx_string_put(data->mlx, data->win, 16, 16, 0x000000, data->utils.str);
	free(data->utils.str);
	free(count);
}

int	checkpath(char *path, int ac)
{
	int	i;

	if (ac == 2)
	{
		i = ft_strlen(path) - 1;
		if (path[i] != 'r' || path[i - 1] != 'e' || path[i - 2] != 'b' || path[i
				- 3] != '.' || ft_strlen(path) <= 4)
		{
			ft_printf("Please, send a .ber map\n");
			exit(0);
		}
	}
	return (0);
}
