#include "cub3d.h"

void    texture_to_image(t_data *data)
{
	void *texture;
	int width;
	int height;
	
	texture = mlx_xpm_file_to_image(data->mlx, "east.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->win, texture, 0, 0);
}