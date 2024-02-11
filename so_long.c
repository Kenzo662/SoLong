/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by klopez            #+#    #+#             */
/*   Updated: 2024/02/11 04:57:22 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	data.map = NULL;
	if (ac != 2)
	{
		data.img.path = "map/map.ber";
	}
	else
		data.img.path = av[1];
	malloctab(&data, data.img.path);
	fd = open(data.img.path, O_RDONLY);
	checkmap(&data, fd);
	close(fd);
	init_p_pos(&data);
	printf("x = %d y = %d\n", data.player.p_pos.x, data.player.p_pos.y);
	data.utils.mapcheck = mallocnewtab(&data);
	dfs(&data, data.player.p_pos, data.utils.mapcheck);
	if (data.utils.c_way != data.utils.countc
		|| data.utils.e_way != data.utils.counte)
	{
		ft_printf("The way to the exit is wrong, please send a new map!");
		exit(0);
	}
	init_data(&data);
	printmap(&data);
	mlx_loop_hook(data.mlx, startenemiesanim, &data);
	mlx_key_hook(data.win, keyboard, &data);
	mlx_hook(data.win, 17, 0, leave, &data);
	mlx_loop(data.mlx);
}

int	leave(t_data *data)
{
	destroy_img(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	endgame(t_data *data)
{
	init_destpos(data);
	if (data->map[data->player.destpos.y][data->player.destpos.x] == 'E')
		leave(data);
}

void	init_all_e_pos(t_data *data, int side, int i, int j)
{
	data->player.enemiespos.x = j;
	data->player.enemiespos.y = i;
	init_destpos(data);
	init_enemiesdestpos(data, side);
}
