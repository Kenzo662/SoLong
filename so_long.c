/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:39:01 by klopez            #+#    #+#             */
/*   Updated: 2023/12/18 19:23:42 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* #include "so_long.h"

int main(void)
{
    void *mlx;
    void *img;
    void *win;
    char *path = "./Sprites/textures/sol1.xpm";
    int img_width;
    int img_height;
    int i = 0;
    int j;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 10 * 64, 5 * 64, "so_long");
    img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
    while (i < 10)
    {
        j = 0;
        while(j < 5)
        {
            mlx_put_image_to_window(mlx, win, img, i * 64, j * 64);
            j++;
        }
        i++;
    }
    mlx_loop(mlx);
} */