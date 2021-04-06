# include "cub3d.h"
# include <stdio.h>
# include <stdlib.h>
#include <fcntl.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

double put_ray(t_data *data, int color, float angle)
{
	float x;
	float y;
	int scale = 10;
	double distance;
	x = data->player.y + 0.5;
	y = data->player.x + 0.5;
	while(1)
	{
		my_mlx_pixel_put(data, y * scale, x * scale, color);
		x -= sin(angle + data->player.angle) / 100;
		if (data->map[(int)x][(int)y] == '1' || data->map[(int)x][(int)y] == '2')
			break;
		y += cos(angle + data->player.angle) / 100;
		if (data->map[(int)x][(int)y] == '1' || data->map[(int)x][(int)y] == '2')
			break;
	}
	float dx;
	dx = fabs(x - lround(x));
	data->indicator_dx = dx;
	float dy;
	dy = fabs(y - lround(y));
	data->indicator_dy = dy;
	if (dx > dy)
	{
		if(y > data->player.x + 0.5)
			data->wall_type = 'E';
		else
			data->wall_type = 'W';
	}
	else
	{
		if(x > data->player.y + 0.5)
			data->wall_type = 'S';
		else
			data->wall_type = 'N';
 	}
	// float orient;
	// orient = atan2(x - data->player.y - 0.5, y - data->player.x - 0.5) * 180 / M_PI;
	// orient = atan2(x - data->player.y - 0.5, y - data->player.x - 0.5); // + data->player.angle;
	// if (orient > M_PI)
	// 	orient -= 2 * M_PI;
	// else if (orient < - M_PI)
	// 	orient += 2 * M_PI;
	// if (orient > - M_PI_4 && orient < M_PI_4)
	// 	data->wall_type = 'N';
	//else if (orient <  && orient > - M_PI)
	//	data->wall_type = 'S';
	// else
	// 	data->wall_type = '0';
	distance = sqrt((x - data->player.y - 0.5) * (x - data->player.y - 0.5) + (y - data->player.x - 0.5) * (y - data->player.x - 0.5));
	return (distance);
}

void put_line(t_data *data, int number, double distance)
{
	int color;
	int count = data->res1;
	int x = data->res1 * number / count;
	int y0 = data->res2 / 2;
	int height = data->res2 / 2 / distance;
	if (height >= data->res2 / 2)
		height = data->res2 / 2 - 1;
	if (data->wall_type == 'N')
		color = 0x00FF00;
	else if (data->wall_type == 'S')
		color = 0x0000FF;
	else if (data->wall_type == 'W')
		color = 0x000000;
	else
		color = 0xFF0000;
	while (height >= 0)
	{
		my_mlx_pixel_put(data, x, y0 + height, color);
		my_mlx_pixel_put(data, x, y0 - height, color);
		height--;
	}
}

void put_rays(t_data *data, int color)
{
	int count = 0;
	double distance;
	float start_angle = - M_PI / 6;
	float end_angle = 1 * M_PI  / 6;
	float step = (end_angle - start_angle) / data->res1;
	while (count < data->res1)
	{
		distance = put_ray(data, color, start_angle + step * count);
		distance *= cos(start_angle + step * count);
		put_line(data, data->res1 - 1 - count, distance);
		count++;
	}
}

void put_square(t_data *data, int color)
{
	(void)color;
	int x;
	int y;
	int scale;
	scale = 10;
	x = data->x;
	y = data->y;
	while(x < scale + data->x)
	{
		while(y < scale + data->y)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		y = data->y;
		x++;
	}
}
int mlx_map(int keycode, t_data *data)
{
	int x;
	x = 0;
	int y;
	y = 0;
	int scale = 10;
	while (y < data->res2 / 2)
	{
		x = 0;
		while(x < data->res1)
		{
			my_mlx_pixel_put(data, x, y, data->ceiling);
			my_mlx_pixel_put(data, x, y + data->res2 / 2, data->floor);
			x++;
		}
		y++;
	}
	x = 0;
	y = 0;
	// put_rays(data, 0xFFFF00);
	while (x < data->max_height)
	{
		while(data->map[x][y])
		{
			data->x = scale * y;
			data->y = scale * x;
			if (data->map[x][y] == '1')
				put_square(data, 0xBEBEBE);
			else if (data->map[x][y] == '0')
				put_square(data, 0xFFFAFA);
			else if (data->map[x][y] == '2')
				put_square(data, 0x0000EE);
			else
				put_square(data, 0x000000);
			y++;
		}
		y = 0;
		x++;
	}
	put_rays(data, 0xFFFF00);
	//move(keycode, data);
	(void)keycode;
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return(0);
}

void mlx_player(t_data *data, int color)
{
	int x;
	int y;
	int scale = 10;

	x = data->player.x * scale;
	y = data->player.y * scale;
	int zx = scale / 2;
	int zy = scale / 2;
	while (x - zx < data->player.x * scale + zx)
	{
		while (y - zy < data->player.y * scale + zy)
		{
			// if ((x - (data->player.x * data->res1 / data->max_width + 50)) * (x - (data->player.x * data->res1 / data->max_width + 50)) + (y - (data->y + 0.5)) * (y - (data->y + 0.5)) <= 0.25)
			{
				my_mlx_pixel_put(data, x, y, color);
			}
			y++;
		}
		y = data->player.y * scale;
		x++;
	}
}

int destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int move(int keycode, t_data *data)
{
	int color;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 13 || keycode == 126)
	{
		if (check_obstacle(data, 'N') == 0)
		{
			// data->player.y -= sin(data->player.angle);
			// data->player.x += cos(data->player.angle);
			data->player.y -= sin(data->player.angle) * (float)1 / 5;
			data->player.x += cos(data->player.angle) * (float)1 / 5;
		}
	}
	else if (keycode == 0)
	{
		if (check_obstacle(data, 'W') == 0)
		{
			// data->player.y -= cos(data->player.angle);
			// data->player.x -= sin(data->player.angle);
			data->player.y -= cos(data->player.angle) * (float)1 / 5;
			data->player.x -= sin(data->player.angle) * (float)1 / 5;
		}
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (check_obstacle(data, 'S') == 0)
		{
			// data->player.y += sin(data->player.angle);
			// data->player.x -= cos(data->player.angle);
			data->player.y += sin(data->player.angle) * (float)1 / 5;
			data->player.x -= cos(data->player.angle) * (float)1 / 5;
		}
	}
	else if (keycode == 2)
	{
		if (check_obstacle(data, 'E') == 0)
		{
			// data->player.y += cos(data->player.angle);
			// data->player.x += sin(data->player.angle);
			data->player.y += cos(data->player.angle) * (float)1 / 5;
			data->player.x += sin(data->player.angle) * (float)1 / 5;
		}
	}
	else if (keycode == 124)
	{
		// data->player.angle += M_PI_2 / 6;
		data->player.angle -= M_PI_2 / 6;
		if (data->player.angle < 0)
			data->player.angle += 2 * M_PI;
	}
	else if (keycode == 123)
	{
		data->player.angle += M_PI_2 / 6;
		if (data->player.angle > 2 * M_PI)
			data->player.angle -= 2 * M_PI;
		// data->player.angle -= M_PI_2 / 6;
	}
	color = 0xFF0000;
	mlx_map(keycode, data);
	mlx_player(data, color);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_data *data;
		data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
		data->north.img = NULL;
	data->south.img = NULL;
	data->east.img = NULL;
	data->west.img = NULL;
	data->sprite.img = NULL;
	int fd;
	if (argc != 2)
		return(1);
	fd = open(argv[1], O_RDONLY);
	ft_gnl(fd, data);	
	if (ft_validity_check(data) != 0)
		{
			ft_putstr_fd("invalid map\n", 1);
			exit(1);
		}
	data->win = mlx_new_window(data->mlx, data->res1, data->res2, "Hello world!");
	data->img = mlx_new_image(data->mlx, data->res1, data->res2);

	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	player_position(data);
	mlx_map(0, data);
	mlx_player(data, 0xFF0000);

    // texture_to_image(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 2, 1L<<0, move, data);
	mlx_hook(data->win, 17, 1L, destroy, data);
	mlx_loop(data->mlx);
}

