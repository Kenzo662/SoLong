/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:03:28 by klopez            #+#    #+#             */
/*   Updated: 2024/02/06 04:53:38 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	transparance(void *mlx, t_img bg, char *path)
{
	int		i;
	int		j;
	t_img	c;

	j = -1;
	i = -1;
	c.img = mlx_xpm_file_to_image(mlx, path, &c.width, &c.height);
	c.addr = mlx_get_data_addr(c.img, &c.bpp, &c.size_line, &c.endian);
	while (++i < (c.size_line / 4))
	{
		while (++j <= (c.size_line / 4))
		{
			if ((c.addr[(i * c.size_line) + (j * (c.bpp / 8))] == 0)
				&& (c.addr[(i * c.size_line) + (j * (c.bpp / 8)) + 1] == 0)
				&& (c.addr[(i * c.size_line) + (j * (c.bpp / 8)) + 2] == 0))
				swap(bg, &c, i, j);
		}
		j = -1;
	}
	return (c);
}

void	swap(t_img bg, t_img *c, int i, int j)
{
	c->addr[(i * c->size_line) + (j * (c->bpp / 8))] = bg.addr[(i
			* c->size_line) + (j * (c->bpp / 8))];
	c->addr[(i * c->size_line) + (j * (c->bpp / 8)) + 1] = bg.addr[(i
			* c->size_line) + (j * (c->bpp / 8)) + 1];
	c->addr[(i * c->size_line) + (j * (c->bpp / 8)) + 2] = bg.addr[(i
			* c->size_line) + (j * (c->bpp / 8)) + 2];
}
