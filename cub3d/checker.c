
#include "cub3d.h"

int check_obstacle(t_data *data, char direction)
{
	float mapx = data->player.x + 0.5;
	float mapy = data->player.y + 0.5;
	
	if (direction == 'N')
	{
		mapy -= sin(data->player.angle);
		mapx += cos(data->player.angle);
		// mapy -= sin(data->player.angle) * (float)1 / 5;
		// mapx += cos(data->player.angle) * (float)1 / 5;
	}
	else if (direction == 'S')
	{
		mapy += sin(data->player.angle);
		mapx -= cos(data->player.angle);
		// mapy += sin(data->player.angle) * (float)1 / 5;
		// mapx -= cos(data->player.angle) * (float)1 / 5;
	}
	else if (direction == 'W')
	{
		// mapy += cos(data->player.angle);
		// mapx += sin(data->player.angle);
		mapy -= cos(data->player.angle);
		mapx -= sin(data->player.angle);
		// mapy -= cos(data->player.angle) * (float)1 / 5;
		// mapx -= sin(data->player.angle) * (float)1 / 5;
	}
	else if (direction == 'E')
	{
		// mapy -= cos(data->player.angle);
		// mapx -= sin(data->player.angle);
		mapy += cos(data->player.angle);
		mapx += sin(data->player.angle);
		// mapy += cos(data->player.angle) * (float)1 / 5;
		// mapx += sin(data->player.angle) * (float)1 / 5;
	}
	int rx = (int)(mapx);
	int ry = (int)(mapy);
	if ((data->map[ry][rx] == '1') || (data->map[ry][rx] == '2'))
		return (1);
	return (0);
}

int check_player(t_data *data)
{
	int i;
	i = 0;
	int x;
	x = 0;
	int y;
	y = 0;

	while(x < data->max_height)
	{
		while(data->map[x][y])
		{
		if (data->map[x][y] == 'N' || data->map[x][y] == 'S' || data->map[x][y] == 'W' || data->map[x][y] == 'E')
			i++;
		y++;
		}
		y = 0;
		x++;
	}
	if (i != 1)
		return(1);
	return(0);
}

void player_position(t_data *data)
{
	int x;
	x = 0;
	int y;
	y = 0;
	while(x < data->max_height)
	{
		while(data->map[x][y])
		{
		if (data->map[x][y] == 'N' || data->map[x][y] == 'S' || data->map[x][y] == 'W' || data->map[x][y] == 'E')
			{
				data->player.y = x;
				data->player.x = y;
				if (data->map[x][y] == 'N')
					data->player.angle = M_PI * 0.5;
				else if (data->map[x][y] == 'S')
					data->player.angle = M_PI * 1.5;
				else if (data->map[x][y] == 'W')
					data->player.angle = M_PI;
				else
					data->player.angle = M_PI * 0;
				mlx_player(data, 0xFF0000);
				data->map[x][y] = '0';
			}
			y++;
		}
		y = 0;
		x++;
	}
}

int check_parameters(t_data *data)
{
	data->param_counter = 0;
	if(data->north.img != NULL)
		data->param_counter++;
	if(data->south.img != NULL)
		data->param_counter++;
	if(data->sprite.img != NULL)
		data->param_counter++;
	if(data->west.img != NULL)
		data->param_counter++;
	if(data->east.img != NULL)
		data->param_counter++;
	if(data->res1 != 0)
		data->param_counter++;
	if(data->res2 != 0)
		data->param_counter++;
	if(data->floor != 0)
		data->param_counter++;
	if(data->ceiling != 0)
		data->param_counter++;
	if(data->param_counter != 9)
		return(1);
	return(0);
}

// int check_map(t_data *data)
// {
// 	int x;
// 	x = 0;
// 	int y;
// 	y = 0;
// 	while (data->map[x])
// 	{
// 		while(data->map[x][y])
// 		{
// 			if(data->map[x][y] == '1')
// 				y++;
// 			else if (data->map[x][y] == '0')
// 				put_square(data, 0xFFFAFA);
// 			else if (data->map[x][y] == '2')
// 				put_square(data, 0x0000EE);
// 			else
// 				put_square(data, 0x000000);
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}


int ft_validity_check(t_data *data)
{
	if(check_player(data) != 0)
		return(1);
	if(data->res1 < 400 && data->res2 < 200)
		return(1);
	if(check_parameters(data) != 0)
		return(1);
	// if(check_map(data) != 0)
	// 	return(1);
	return(0);
}