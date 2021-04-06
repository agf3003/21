/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:15:32 by bellan            #+#    #+#             */
/*   Updated: 2021/04/06 18:34:28 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <math.h>

typedef struct s_image
{
	// void *mlx;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
	int x;
	int y;
}				t_image;
typedef struct s_player
{
	float x;
	float y;
	float angle;
}				t_player;

typedef struct s_data
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	char **map;
	float scalex;
	float scaley;
	t_player player;
	t_player ray;
	int bits_per_pixel;
	int line_length;
	int endian;
	char wall_type;
	int map_size;
	float indicator_dx;
	float indicator_dy;
	int x;
	int y;
	int res1;
	int res2;
	int floor;
	int ceiling;
	int max_width;
	int max_height;
	int param_counter;
	t_image sprite;
	t_image north;
	t_image south;
	t_image east;
	t_image west;
}				t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void mlx_player(t_data *data, int color);
int move(int keycode, t_data *data);
void ft_createmap(char **array, int start, int size, t_data *data);
int ft_parcing(char *map, t_data *data);
void ft_map(t_list **head, int size, t_data *data);
int ft_gnl(int fd, t_data *data);
int destroy(t_data *data);
int check_obstacle(t_data *data, char direction);
void player_position(t_data *data);
int check_player(t_data *data);
void    texture_to_image(t_data *data);
int ft_validity_check(t_data *data);

#endif