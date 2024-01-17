#include "so_long.h"

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

void    init_textures(t_data *data)
{

    data->textures->exit = (t_img *)malloc(sizeof(t_img));
    data->textures->player = (t_img *)malloc(sizeof(t_img));
    data->textures->wall.img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/sol.xpm", &(int){0}, &(int){0});
    data->textures->ground.img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/sol1.xpm", &(int){0}, &(int){0});
    data->textures->exit[0].img = mlx_xpm_file_to_image(data->mlx,"./Sprites/textures/exit.xpm", &(int){0}, &(int){0});
    data->textures->ground.addr= mlx_get_data_addr(data->textures->ground.img, &data->textures->ground.bpp, &data->textures->ground.size_line,
            &data->textures->ground.endian);
    data->textures->player[0] = ft_get_image_transparance(data->mlx, data->textures->ground, "./Sprites/skins/BrolyFace0.xpm");
}

void    init_collec(t_data *data)
{
    int i = 0;
    char *path;
    data->textures->collec = (t_img *)malloc(sizeof(t_img) * 7);
    while(i < 7)
    {
        path = change_path("./Sprites/items/Crystal", i);
        data->textures->collec[i] = ft_get_image_transparance(data->mlx, data->textures->ground, path);
        i++;
        free(path);
    }
}

t_img    ft_get_image_transparance(void *mlx, t_img bg, char *path)
{
    int        i;
    int        j;
    t_img    c;

    j = -1;
    i = -1;
    c.img = mlx_xpm_file_to_image(mlx, path, &c.width, &c.height);
    c.addr = mlx_get_data_addr(c.img, &c.bpp, &c.size_line,
            &c.endian);
    while (++i < (c.size_line / 4))
    {
        while (++j <= (c.size_line / 4))
        {
            if ((c.addr[(i * c.size_line) \
                + (j * (c.bpp / 8))] == 0) \
                && (c.addr[(i * c.size_line) \
                + (j * (c.bpp / 8)) + 1] == 0) \
                && (c.addr[(i * c.size_line) \
                + (j * (c.bpp / 8)) + 2] == 0))
                ft_swap_px(bg, &c, i, j);
        }
        j = -1;
    }
    return (c);
}

void    ft_swap_px(t_img bg, t_img *c, int i, int j)
{
    c->addr[(i * c->size_line) + (j * (c->bpp / 8))]
        = bg.addr[(i * c->size_line) \
        + (j * (c->bpp / 8))];
    c->addr[(i * c->size_line) + (j * (c->bpp / 8)) + 1]
        = bg.addr[(i * c->size_line) \
        + (j * (c->bpp / 8)) + 1];
    c->addr[(i * c->size_line) + (j * (c->bpp / 8)) + 2]
        = bg.addr[(i * c->size_line) \
        + (j * (c->bpp / 8)) + 2];
}