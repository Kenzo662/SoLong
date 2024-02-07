/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 04:20:02 by klopez            #+#    #+#             */
/*   Updated: 2024/02/06 23:49:27 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures->ground.img);
	mlx_destroy_image(data->mlx, data->textures->wall.img);
	mlx_destroy_image(data->mlx, data->textures->ennemies[0].img);
	mlx_destroy_image(data->mlx, data->textures->exit[0].img);
	mlx_destroy_image(data->mlx, data->textures->exit[1].img);
	mlx_destroy_image(data->mlx, data->textures->collec[0].img);
	mlx_destroy_image(data->mlx, data->textures->collec[1].img);
	mlx_destroy_image(data->mlx, data->textures->collec[2].img);
	mlx_destroy_image(data->mlx, data->textures->collec[3].img);
	mlx_destroy_image(data->mlx, data->textures->collec[4].img);
	mlx_destroy_image(data->mlx, data->textures->collec[5].img);
	mlx_destroy_image(data->mlx, data->textures->collec[6].img);
	mlx_destroy_image(data->mlx, data->textures->player[0].img);
	mlx_destroy_image(data->mlx, data->textures->player[1].img);
	mlx_destroy_image(data->mlx, data->textures->player[2].img);
	mlx_destroy_image(data->mlx, data->textures->player[3].img);
	mlx_destroy_image(data->mlx, data->textures->player[4].img);
	mlx_destroy_image(data->mlx, data->textures->player[5].img);
	mlx_destroy_image(data->mlx, data->textures->player[6].img);
	mlx_destroy_image(data->mlx, data->textures->player[7].img);
	mlx_destroy_image(data->mlx, data->textures->player[8].img);
	mlx_destroy_image(data->mlx, data->textures->player[9].img);
	mlx_destroy_image(data->mlx, data->textures->player[10].img);
	mlx_destroy_image(data->mlx, data->textures->player[11].img);
	destroy_img2(data);
}

void	destroy_img2(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures->player_attack[0].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[1].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[2].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[3].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[4].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[5].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[6].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[7].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[8].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[9].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[10].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[11].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[12].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[13].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[14].img);
	mlx_destroy_image(data->mlx, data->textures->player_attack[15].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[0].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[1].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[2].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[3].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[4].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[5].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[6].img);
	mlx_destroy_image(data->mlx, data->textures->enemiesattack[7].img);
	destroy_img3(data);
}

void	destroy_img3(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures->buu_start[0].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[1].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[2].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[3].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[4].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[5].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[6].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[7].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[8].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[9].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[10].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[11].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[12].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[13].img);
	mlx_destroy_image(data->mlx, data->textures->buu_start[14].img);
	destroy_img4(data);
}

void	destroy_img4(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures->buu_death[0].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[1].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[2].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[3].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[4].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[5].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[6].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[7].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[8].img);
	mlx_destroy_image(data->mlx, data->textures->buu_death[9].img);
	mlx_destroy_image(data->mlx, data->textures->player_start[0].img);
	mlx_destroy_image(data->mlx, data->textures->player_start[1].img);
	mlx_destroy_image(data->mlx, data->textures->player_start[2].img);
	mlx_destroy_image(data->mlx, data->textures->player_start[3].img);
	mlx_destroy_image(data->mlx, data->textures->player_start[4].img);
	mlx_destroy_image(data->mlx, data->textures->player_start[5].img);
    int i = 0;
    while(i < data->axes.y)
    {
        free(data->map[i]);
        i++;
    }
	free(data->map);
	free_textures(data);
}

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
