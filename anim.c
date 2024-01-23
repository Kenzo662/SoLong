#include "so_long.h"

int     clock(t_data *data)
{
    if (data->clock == 1)
	{
		data->clock = 0;
		if (data->frame == 1)
			data->frame = 0;
		else
			data->frame = 1;
	}
	else
		data->clock++;
	playeranim(data);
	return(0);
}


void	playeranim(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->textures->player[data->player.side + data->frame].img,
	data->player.p_pos.x * 64, data->player.p_pos.y * 64);
}