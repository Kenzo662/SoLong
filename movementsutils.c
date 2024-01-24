#include "so_long.h"

int    walkable(t_data *data, t_axes pos)
{
    if (data->map[pos.y][pos.x] == '1' || data->map[pos.y][pos.x] == 'Z' || data->map[pos.y][pos.x] == 'E')
        return(0);
    return(1);
}

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

int	keyboard(int keycode, t_data *data)
{
	if (keycode == W)
	{
		moveup(data);
    }
	else if (keycode == A)
	{
		moveleft(data);
	}
	else if (keycode == S)
	{
		movedown(data);
	}
	else if (keycode == D)
	{
		moveright(data);
	}
	return (0);
}

void    printdirection(t_data *data)
{
    mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
    mlx_put_image_to_window(data->mlx, data->win, data->textures->ground.img, data->player.p_pos.x * 64, data->player.p_pos.y * 64);
    data->player.p_pos = data->player.destpos;
    mlx_do_sync(data->mlx);
    usleep(75000);
    data->player.side++;
    mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
    mlx_do_sync(data->mlx);
    usleep(30000);
    data->player.side++;
    mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side].img, data->player.destpos.x * 64, data->player.destpos.y * 64);
}

