/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:38:57 by klopez            #+#    #+#             */
/*   Updated: 2024/01/21 18:00:37 by klopez           ###   ########.fr       */
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

typedef struct s_utils
{
    char    *str;
    int     countE;
    int     countP;
    int     countC;
    int     bytes;
    int     line;
    int     i;
    int     j;
    int     k;
}           t_utils;

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
    t_img   *exit;
    t_img   *collec;
}           t_textures;

typedef struct s_player
{
    t_axes  p_pos;
    t_axes  destpos;
}       t_player;

typedef struct  s_data 
{
    void        *mlx;
    void        *win;
    char        **map;
    t_axes      axes;
    t_img       img;
    t_textures  *textures;
    t_utils     utils;
    t_player    player;
}         t_data;



int     checkone(char *line);
void    CheckWhile(t_data *data, int fd, t_utils *utils);
void    CheckChar(t_data *data, int fd, t_utils *utils);
void    Checkmap(t_data *data, int fd);
void    MallocTab(t_data *data, char *path);
void    init_textures(t_data *data);
char    *change_path(char *str, int index);
void    init_collec(t_data *data);
t_img   transparance(void *mlx, t_img bg, char *path);
void    swap(t_img bg, t_img *c, int i, int j);
int     walkable(t_data *data, t_axes pos);
void    imgtowin(t_data *data, void *img, t_axes pos);
void    init_data(t_data *data);
int	    keyboard(int keycode, t_data *data);
void    moveup(t_data *data);
void    movedown(t_data *data);
void    moveleft(t_data *data);
void    moveright(t_data *data);

#endif