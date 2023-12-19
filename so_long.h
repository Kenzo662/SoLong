/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:38:57 by klopez            #+#    #+#             */
/*   Updated: 2023/12/18 19:26:54 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "./libft/libft.h"

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

# define TSize 64

typedef struct s_axes
{
    int x;
    int y;
}       t_axes;

typedef struct  s_img
{
    void    *img;
    char    *addr;
    int     height;
    int     width;
    char    *path;
    int     bpp;
    int     size_line;
    int     endian;
}           t_img;

typedef struct s_textures
{
    t_img   *player;
    t_img   *ennemies;
    t_img   wall;
    t_img   ground;

}           t_textures;

typedef struct  s_data 
{
    void        *mlx;
    void        *window;
    char        **map;
    t_axes      axes;
    t_img       img;
    t_axes      p_pos;
    t_textures  textures;


}         t_data;

int Checkline(int i, int fd, char *line);
int checkone(char *line);
int CheckTopDown();

#endif