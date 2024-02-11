/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:07:17 by kenz              #+#    #+#             */
/*   Updated: 2024/02/11 05:10:41 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_data *data)
{
	free(data->textures->ennemies);
	free(data->textures->collec);
	free(data->textures->exit);
	free(data->textures->player_start);
	free(data->textures->enemiesattack);
	free(data->textures->player_attack);
	free(data->textures->buu_death);
	free(data->textures->buu_start);
	free(data->textures->player);
	free(data->textures);
}

void	freetabfull(char **tab, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->axes.y)
		free(tab[i]);
	free(tab);
}

void	freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
