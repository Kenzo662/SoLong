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
	else if (keycode == D)
	{

		moveright(data);
	}
	else if (keycode == S)
	{
		movedown(data);
	}
	else if (keycode == E)
	{
		attack_anim(data);
	}
	return (0);
}

