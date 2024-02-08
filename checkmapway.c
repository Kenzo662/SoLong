/* #include "so_long.h"

void    dfs(t_data *data, t_axes pos)
{
        char **mapcheck;
        int i;
        t_axes  nextway[4];

        i = -1;
        mapcheck = mallocnewtab(data);
        if (pos.y < 0 || pos.y >= data->axes.y || pos.x < 0
                || pos.x >= data->axes.x)
                return ;
        if (data->map[pos.y][pos.x] == '1' || mapcheck[pos.y][pos.x] == '1')
                return ;
        mapcheck[pos.y][pos.x] = '1';
        if (data->map[pos.y][pos.x] == 'C')
                data->utils.c_way++;
        if (data->map[pos.y][pos.x] == 'E')
                data->utils.e_way++;
        while (++i < 4)
                nextway[i] = find_dir(pos, i * 2);
        i = -1;
        while (++i < 4)
                dfs(data, nextway[i]);
        if (data->utils.c_way != data->utils.countc || data->utils.e_way != data->utils.counte)
        {
            ft_printf("The way to the exit is wrong, please send a new map!");
            leave(data);
        }
}

char    **mallocnewtab(t_data *data)
{
        int     i;
        int             fd;
    char    *str;
    char    **tab;

        i = 0;
        fd = open(data->img.path, O_RDONLY);
        str = get_next_line(fd);
        while (str)
        {
                free(str);
                i++;
                str = get_next_line(fd);
        }
        tab = (char **)malloc(sizeof(char *) * i + 1);
        close(fd);
    return(tab);
}

t_axes  find_dir(t_axes pos, int dir)
{
        if (dir == 0)
                pos.y++;
        else if (dir == 2)
                pos.y--;
        else if (dir == 4)
                pos.x--;
        else if (dir == 6)
                pos.x++;
        return (pos);
} */