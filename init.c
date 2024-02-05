/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:14:04 by klopez            #+#    #+#             */
/*   Updated: 2024/02/04 15:43:28 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->utils.k = 0;
	data->utils.countc = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->axes.x * 64, data->axes.y * 64,
			"so_long");
	data->textures = (t_textures *)malloc(sizeof(t_textures));
	data->player.p_pos.x = 0;
	data->player.p_pos.y = 0;
	data->player.destpos.x = 0;
	data->player.destpos.y = 0;
	data->player.side = 0;
	data->utils.i = 0;
	data->utils.j = 0;
	data->utils.k = 0;
	data->player.attack_side = 0;
	data->player.enemiespos.x = 0;
	data->player.enemiespos.y = 0;
	data->utils.whichside = 0;
	data->utils.collect = 0;
	data->utils.loop = 0;
	data->utils.loop1 = 0;
	data->utils.l = 0;
	data->utils.e_side = -1;
	init_data2(data);
}

void	init_data2(t_data *data)
{
	data->player.exitpos.x = 0;
	data->player.exitpos.y = 0;
	data->player.e_destpos.x = 0;
	data->player.e_destpos.y = 0;
	data->utils.loopcount = 0;
	data->utils.loopcount1 = 0;
	data->utils.side = -1;
	init_textures(data);
	init_collec(data);
	init_player(data);
	init_start(data);
	init_attack(data);
	init_startenemies(data);
	init_exit(data);
	init_enemiesdeath(data);
	init_enemiesattack(data);
}

void	init_textures(t_data *data)
{
	data->textures->ennemies = (t_img *)malloc(sizeof(t_img));
	data->textures->wall.img = mlx_xpm_file_to_image(data->mlx,
			"./Sprites/textures/sol.xpm", &(int){0}, &(int){0});
	data->textures->ground.img = mlx_xpm_file_to_image(data->mlx,
			"./Sprites/textures/sol1.xpm", &(int){0}, &(int){0});
	data->textures->ground.addr = mlx_get_data_addr(data->textures->ground.img,
			&data->textures->ground.bpp, &data->textures->ground.size_line,
			&data->textures->ground.endian);
	data->textures->ennemies[0] = transparance(data->mlx,
			data->textures->ground, "./Sprites/skins/BuuFace.xpm");
}

void	init_collec(t_data *data)
{
	int		i;
	char	*path;

	i = 0;
	data->textures->collec = (t_img *)malloc(sizeof(t_img) * 7);
	while (i < 7)
	{
		path = change_path("./Sprites/items/Crystal", i);
		data->textures->collec[i] = transparance(data->mlx,
				data->textures->ground, path);
		i++;
		free(path);
	}
}

void	init_player(t_data *data)
{
	int		i;
	char	*path;

	data->textures->player = (t_img *)malloc(sizeof(t_img) * 12);
	i = 0;
	while (i < 12)
	{
		path = change_path("./Sprites/skins/Broly", i);
		data->textures->player[i] = transparance(data->mlx,
				data->textures->ground, path);
		i++;
		free(path);
	}
}
