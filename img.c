/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:04:15 by klopez            #+#    #+#             */
/*   Updated: 2024/01/21 17:30:03 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    imgtowin(t_data *data, void *img, t_axes pos)
{
    mlx_put_image_to_window(data->mlx, data->win, img, pos.x * 64, pos.y * 64);
}

t_img    transparance(void *mlx, t_img bg, char *path)
{
    int        i;
    int        j;
    t_img    c;

    j = -1;
    i = -1;
    c.img = mlx_xpm_file_to_image(mlx, path, &c.width, &c.height);
    c.addr = mlx_get_data_addr(c.img, &c.bpp, &c.size_line,
            &c.endian);
    while (++i < (c.size_line / 4))
    {
        while (++j <= (c.size_line / 4))
        {
            if ((c.addr[(i * c.size_line) \
                + (j * (c.bpp / 8))] == 0) \
                && (c.addr[(i * c.size_line) \
                + (j * (c.bpp / 8)) + 1] == 0) \
                && (c.addr[(i * c.size_line) \
                + (j * (c.bpp / 8)) + 2] == 0))
                swap(bg, &c, i, j);
        }
        j = -1;
    }
    return (c);
}

void    swap(t_img bg, t_img *c, int i, int j)
{
    c->addr[(i * c->size_line) + (j * (c->bpp / 8))]
        = bg.addr[(i * c->size_line) \
        + (j * (c->bpp / 8))];
    c->addr[(i * c->size_line) + (j * (c->bpp / 8)) + 1]
        = bg.addr[(i * c->size_line) \
        + (j * (c->bpp / 8)) + 1];
    c->addr[(i * c->size_line) + (j * (c->bpp / 8)) + 2]
        = bg.addr[(i * c->size_line) \
        + (j * (c->bpp / 8)) + 2];
}

