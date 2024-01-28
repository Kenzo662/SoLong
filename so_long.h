/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:38:57 by klopez            #+#    #+#             */
/*   Updated: 2024/01/24 15:15:13 by klopez           ###   ########.fr       */
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
# define E 101

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
    int     l;
    int     loopcount;
    int     loopcount1;
    int     whichside;
    int     collect;
    int     loop;
    int     loop1;
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
    t_img   *player_start;
    t_img   *player_attack;
    t_img   *buu_start;
    t_img   *buu_death;
    t_img   *enemiesattack;

}           t_textures;

typedef struct s_player
{
    t_axes  p_pos;
    t_axes  destpos;
    t_axes     exitpos;
    int     side;
    int     attack_side;
    t_axes  enemiespos;
    t_axes  e_destpos;
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
void    CheckWhile(t_data *data, t_utils *utils);
void    CheckChar(t_data *data, int fd, t_utils *utils);
void    Checkmap(t_data *data, int fd);
void    MallocTab(t_data *data, char *path);
void    init_textures(t_data *data);
char    *change_path(char *str, int index);
void    init_collec(t_data *data);
t_img   transparance(void *mlx, t_img bg, char *path);
void    swap(t_img bg, t_img *c, int i, int j);
int     walkable(t_data *data, t_axes pos);
void    init_data(t_data *data);
int	    keyboard(int keycode, t_data *data);
void    moveup(t_data *data);
void    movedown(t_data *data);
void    moveleft(t_data *data);
void    moveright(t_data *data);
void    printmap(t_data *data);
void    movedirection(t_data *data, int dir);
int     clock(t_data *data);
void    init_player(t_data *data);
void	playeranim(t_data *data);
void	init_clock(t_data *data);
void    printdirection(t_data *data);
void    startplayeranim(t_data *data);
void    init_start(t_data *data);
void    init_attack(t_data *data);
void	attack_anim(t_data *data);
void    init_destpos(t_data *data);
void    init_startenemies(t_data *data);
int     startenemiesanim(t_data *data);
void    init_enemiesdeath(t_data *data);
void    leave(t_data *data);
void    printchar(t_data *data, void *img);
void    endgame(t_data *data);
void    init_exit(t_data *data);
void    init_enemiesattack(t_data *data);
void    init_enemiesdestpos(t_data *data, int side);
void    printattackanim(t_data *data, void *img);
void	enemies_attack_anim(t_data *data);
void    init_enemiespos(t_data *data);
void	enemies_anim(t_data *data);
int    find_enemies_destpos(t_data *data);

#endif