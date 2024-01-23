#include "so_long.h"

int    walkable(t_data *data, t_axes pos)
{
    if (data->map[pos.y][pos.x] == '1' || data->map[pos.y][pos.x] == 'Z' || data->map[pos.y][pos.x] == 'E')
        return(0);
    return(1);
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

void    movedirection(t_data *data, int dir)
{
    if (dir != data->player.side)
    {
        data->player.side = dir;
        mlx_put_image_to_window(data->mlx, data->win , data->textures->ground.img, data->player.p_pos.x, data->player.p_pos.y);
    }
}

