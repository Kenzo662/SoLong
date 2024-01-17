/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by klopez            #+#    #+#             */
/*   Updated: 2024/01/17 19:04:33 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


char	*change_path(char *textures, int i)
{
	char	*number;
	char	*str;
	char	*path;

	number = ft_itoa(i);
	str = ft_strjoin(textures, number);
	free(number);
	path = ft_strjoin(str, ".xpm");
	free(str);
	return (path);
}

void    init_textures(t_data *data)
{
    data->textures->exit = (t_img *)malloc(sizeof(t_img));
    data->textures->player = (t_img *)malloc(sizeof(t_img));
    data->textures->wall.img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/sol.xpm", &(int){0}, &(int){0});
    data->textures->ground.img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/sol1.xpm", &(int){0}, &(int){0});
    data->textures->exit[0].img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/exit.xpm", &(int){0}, &(int){0});
    data->textures->player[0].img = mlx_xpm_file_to_image(data->mlx,"./Sprites/skins/BrolyFace0.xpm", &(int){0}, &(int){0});
}

void    init_collec(t_data *data)
{
    int i = 0;
    char *path;
    data->textures->collec = (t_img *)malloc(sizeof(t_img) * 7);
    while(i < 7)
    {
        path = change_path("./Sprites/items/Crystal", i);
        data->textures->collec[i].img = mlx_xpm_file_to_image(data->mlx, path, &(int){0}, &(int){0});
        i++;
        free(path);
    }
}

int main(int ac, char **av)
{
    char *path;
    t_data data;
    int i = 0, j = 0, k = 0;
    int fd;

    data.map = NULL;
    if (ac != 2)
    {
        path = "./map.ber";
    }
    else 
        path = av[1];
    MallocTab(&data, path);
    fd = open(path, O_RDONLY);
    Checkmap(&data, fd);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.axes.x * 64, data.axes.y * 64, "so_long");
    data.textures = (t_textures *)malloc(sizeof(t_textures));
    init_textures(&data);
    init_collec(&data);
    //img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
    while (i < data.axes.y)
    {
        j = 0;
        while(j < data.axes.x)
        {
            // printf("x = %d, y = %d\n", data.axes.x, data.axes.y);
            if (data.map[i][j] == '1')
                mlx_put_image_to_window(data.mlx, data.win , data.textures->wall.img , j * 64, i * 64);
            else if (data.map[i][j] == '0')
                mlx_put_image_to_window(data.mlx, data.win, data.textures->ground.img , j * 64, i * 64);
            else if (data.map[i][j] == 'E')
                mlx_put_image_to_window(data.mlx, data.win, data.textures->exit[0].img , j * 64, i * 64);
            else if (data.map[i][j] == 'P')
                mlx_put_image_to_window(data.mlx, data.win, data.textures->player[0].img , j * 64, i * 64);
            else if (data.map[i][j] == 'C')
            {
                mlx_put_image_to_window(data.mlx, data.win, data.textures->collec[k].img , j * 64, i * 64);
                if (k == 6)
                    k = 0;
                k++;
            }
            j++;
        }
        i++;
    }
    mlx_loop(data.mlx);
} 
