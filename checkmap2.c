/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klopez <klopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:27:49 by klopez            #+#    #+#             */
/*   Updated: 2024/01/18 13:22:04 by klopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    MallocTab(t_data *data, char *path)
{
    t_utils utils;

    utils.i = 0;
    int fd;

    fd = open(path, O_RDONLY);
    utils.str = get_next_line(fd);
    while(utils.str)
    {
        free(utils.str);
        utils.k++;
        utils.str = get_next_line(fd);
    }
    data->map = (char **)malloc(sizeof(char *) * utils.k + 1);
    close(fd);
}

int checkone(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] != '1' && line[i] != '\n')
            return(1);
        i++;
    }
    return(0);
}

void    Checkmap(t_data *data, int fd)
{
    t_utils utils;

    utils.countE = 0;
    utils.countP = 0;
    utils.line = 0;
    data->map[utils.line] = get_next_line(fd);
    utils.i = ft_strlen(data->map[utils.line]);
    utils.bytes = 1;

    if (checkone(data->map[utils.line]) == 1)
    {
        printf("La map n'est pas valide");
        exit(0);
    }
    CheckChar(data, fd, &utils);
    utils.j = ft_strlen( data->map[utils.line]);
    data->axes.x = ft_strlen(data->map[utils.line]);
    data->axes.y = utils.line + 1;
    if (checkone(data->map[utils.line]) == 0 && utils.i == utils.j + 1 && utils.countE == 1 && utils.countP == 1)
    {
        printf("La map est valide");
    }
    else
    {
        perror("Map Invalid");
        exit(0);
    }
}

void    CheckChar(t_data *data, int fd, t_utils *utils)
{
    utils->bytes = 1;
    data->map[++utils->line] = get_next_line(fd);
    while (utils->bytes == 1)
    {
        utils->bytes = checkone( data->map[utils->line]);
        if (utils->bytes == 0)
            break;
        utils->j = 0;
        if(data->map[utils->line][0] != '1')
        {
            perror("La map n'est pas fermer1\n");
            exit(0);
        }
        CheckWhile(data, fd, utils);
        if (data->map[utils->line][utils->j - 2] != '1' || utils->i != utils->j)
        {
            perror("La map n'est pas fermer20\n");
            exit(0);
        }
        data->map[++utils->line] = get_next_line(fd);
    }
}

void    CheckWhile(t_data *data, int fd, t_utils *utils)
{

    while(data->map[utils->line][utils->j])
    {
        if (data->map[utils->line][utils->j] != '1' &&  data->map[utils->line][utils->j] != '0' &&  data->map[utils->line][utils->j] != 'P' 
        &&  data->map[utils->line][utils->j] != 'E' &&  data->map[utils->line][utils->j] != 'C' &&  data->map[utils->line][utils->j] != '\n')
        {
            perror("La map n'est pas valide");
            exit(0);
        }
        if (data->map[utils->line][utils->j] == 'E')
            utils->countE++;
        if (data->map[utils->line][utils->j] == 'P')
            utils->countP++; 
        utils->j++;
    }
}

/* int main(void)
{
    int fd = open("map.ber", O_RDONLY);
    t_data data;
    MallocTab(&data);
    Checkmap(&data, fd);
} */