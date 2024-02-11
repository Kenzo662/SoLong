/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmapway.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:38:28 by klopez            #+#    #+#             */
/*   Updated: 2024/02/11 19:48:12 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(t_data *data, t_axes pos, char **mapcheck)
{
	int		i;
	t_axes	nextway[4];

	i = -1;
	if (pos.y < 0 || pos.y >= data->axes.y || pos.x < 0
		|| pos.x >= data->axes.x)
		return ;
	if (data->map[pos.y][pos.x] == '1' || mapcheck[pos.y][pos.x] == '1')
		return ;
	mapcheck[pos.y][pos.x] = '1';
	if (data->map[pos.y][pos.x] == 'C')
		data->utils.c_way++;
	if (data->map[pos.y][pos.x] == 'E')
		data->utils.e_way++;
	while (++i < 4)
		nextway[i] = find_dir(pos, i * 2);
	i = -1;
	while (++i < 4)
		dfs(data, nextway[i], mapcheck);
}

char	**mallocnewtab(t_data *data)
{
	int		i;
	int		fd;
	char	*str;
	char	**tab;
	int		j;

	i = 0;
	j = 0;
	fd = open(data->img.path, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < (i - 1))
	{
		tab[j] = (char *)ft_calloc(data->axes.x + 1, sizeof(char));
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

t_axes	find_dir(t_axes pos, int dir)
{
	if (dir == 0)
		pos.y++;
	else if (dir == 2)
		pos.y--;
	else if (dir == 4)
		pos.x--;
	else if (dir == 6)
		pos.x++;
	return (pos);
}

void	checkway(t_data *data)
{
	data->utils.mapcheck = mallocnewtab(data);
	dfs(data, data->player.p_pos, data->utils.mapcheck);
	if (data->utils.c_way != data->utils.countc
		|| data->utils.e_way != data->utils.counte)
	{
		ft_printf("All collectibles or exit are not reachable!\n");
		ft_printf("Please, send a valid map!\n");
		freetabfull(data->map, data);
		freetabfull(data->utils.mapcheck, data);
		exit(0);
	}
}

void	is_invalid(t_data *data, t_utils *utils)
{
	ft_printf("The map is invalid! Please, send a valid map!\n");
	data->map[utils->line + 1] = NULL;
	freetab(data->map);
	exit(0);
}
