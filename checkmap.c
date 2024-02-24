/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:27:49 by klopez            #+#    #+#             */
/*   Updated: 2024/02/13 19:47:27 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloctab(t_data *data, char *path)
{
	t_utils	utils;
	int		fd;

	utils.k = 0;
	fd = open(path, O_RDONLY);
	utils.str = get_next_line(fd);
	if (utils.str == NULL)
	{
		ft_printf("The map is invalid! Please, send a valid map!");
		exit(0);
	}
	while (utils.str)
	{
		free(utils.str);
		utils.k++;
		utils.str = get_next_line(fd);
	}
	data->map = (char **)malloc(sizeof(char *) * utils.k + 1);
	close(fd);
}

int	checkone(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	checkmap(t_data *data, int fd)
{
	t_utils	utils;

	utils.countp = 0;
	utils.line = 0;
	data->map[utils.line] = get_next_line(fd);
	utils.bytes = 1;
	utils.i = ft_strlen(data->map[utils.line]);
	if (checkone(data->map[utils.line]) == 1)
		is_invalid(data, &utils);
	checkchar(data, fd, &utils);
	utils.j = ft_strlen(data->map[utils.line]);
	data->axes.x = ft_strlen(data->map[utils.line]);
	data->axes.y = utils.line + 1;
	if (data->map[utils.line][utils.j - 1] == '\n')
		data->axes.x -= 1;
	if (checkone(data->map[utils.line]) == 0
		&& (utils.i == utils.j + 1 || (utils.i == utils.j
				&& data->map[utils.line][utils.j - 1] == '\n'))
			&& data->utils.counte == 1 && utils.countp == 1
			&& data->utils.countc > 0)
		return ;
	else
		return (ft_printf("The map is invalid! Please, send a valid map!"),
			freetabfull(data->map, data), exit(0));
}

void	checkchar(t_data *data, int fd, t_utils *utils)
{
	data->utils.counte = 0;
	data->utils.countc = 0;
	utils->bytes = 1;
	data->map[++utils->line] = get_next_line(fd);
	while (utils->bytes == 1)
	{
		utils->bytes = checkone(data->map[utils->line]);
		if (utils->bytes == 0)
			break ;
		utils->j = 0;
		if (data->map[utils->line][0] != '1')
			is_invalid(data, utils);
		checkwhile(data, utils);
		if (data->map[utils->line][utils->j - 2] != '1' || utils->i != utils->j)
			is_invalid(data, utils);
		data->map[++utils->line] = get_next_line(fd);
	}
}

void	checkwhile(t_data *data, t_utils *utils)
{
	data->utils.e_way = 0;
	data->utils.c_way = 0;
	while (data->map[utils->line][utils->j])
	{
		if (data->map[utils->line][utils->j] != '1'
			&& data->map[utils->line][utils->j] != '0'
			&& data->map[utils->line][utils->j] != 'P'
			&& data->map[utils->line][utils->j] != 'E'
			&& data->map[utils->line][utils->j] != 'C'
			&& data->map[utils->line][utils->j] != '\n'
			&& data->map[utils->line][utils->j] != 'Z')
			is_invalid(data, utils);
		if (data->map[utils->line][utils->j] == 'E')
			data->utils.counte++;
		if (data->map[utils->line][utils->j] == 'P')
			utils->countp++;
		if (data->map[utils->line][utils->j] == 'C')
			data->utils.countc++;
		utils->j++;
	}
}
