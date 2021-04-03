# include "cub3d.h"

void ft_createmap(char **array, int start, int size, t_data *data)
{
	int i;
	int j;
	i = start;
	data->map = (char **)malloc((size - start + 1) * sizeof(char *));
	data->max_height = size - start;
	data->scalex = data->res1 / data->max_width;
	data->scaley = data->res2 / data->max_height;
	if (!data->map)
		exit(1);
	while (array[i])
	{
		if(array[i][0] != ' ' && array[i][0] != '1')
		{
			ft_putstr_fd("invalid map\n", 1);
			printf("left: %s\n", array[i]);
			exit(1);
		}
		j = 0;
		while(array[i][j] != '\0')
		{
			if(!ft_strchr("012NSEW ", array[i][j]))
			{
				ft_putstr_fd("invalid map\n", 1);
				printf("inside: %s\n", array[i]);
				exit(1);
			}
			if(array[i][j] == ' ')
			{
				if(array[i][j + 1] != '\0' && array[i][j + 1] != ' ' && array[i][j + 1] != '1')
				{
					ft_putstr_fd("invalid map\n", 1);
					printf("bad right neighbor: %s\n", array[i]);
					exit(1);
				}
				if(j > 0 && array[i][j - 1] != ' ' && array[i][j - 1] != '1')
				{
					ft_putstr_fd("invalid map\n", 1);
					printf("bad left neighbor: %s\n", array[i]);
					exit(1);
				}
				if(i > start && (int)ft_strlen(array[i - 1]) >= j && array[i - 1][j] != ' ' && array[i - 1][j] != '1')
				{
					ft_putstr_fd("invalid map\n", 1);
					printf("bad top neighbor: %s\n", array[i]);
					exit(1);
				}
			}
			j++;
			if (array[i][j] == '\0' && !ft_strchr("1 ", array[i][j - 1]))
			{
				ft_putstr_fd("invalid map\n", 1);
				printf("right: %s\n", array[i]);
				exit(1);
			}
		}
		data->map[i - start] = (char *)ft_calloc(1, data->max_width + 1);
		// ft_memcpy(data->map[i - start], array[i], ft_strlen(array[i]));
		data->map[i - start] = array[i];
		i++;
	}
	j = 0;
	while (array[start][j] != '\0')
	{
		if (!ft_strchr("1 ", array[start][j]))
		{
			ft_putstr_fd("invalid map\n", 1);
			printf("top: %s\n", array[start]);
			exit(1);
		}
		if (array[start][j] == ' ' && (int)ft_strlen(array[start + 1]) >= j && array[start + 1][j] != ' ' && array[start + 1][j] != '1')
		{
			ft_putstr_fd("invalid map\n", 1);
			printf("bad bottom neighbor: %s\n", array[start]);
			exit(1);
		}
		j++;
	}
	j = 0;
	while (array[i - 1][j] != '\0')
	{
		if (!ft_strchr("1 ", array[i - 1][j]))
		{
			ft_putstr_fd("invalid map\n", 1);
			printf("bottom: %s\n", array[i - 1]);
			exit(1);
		}
		j++;
	}
	data->map[i] = NULL;
}

int ft_parcing(char *map, t_data *data)
{
	char **temp;
	int buf1;
	int buf2;
	int buf3;
		if (!ft_strncmp(map, "R ", 2))
		{
			temp = ft_split(map, ' ');
			data->res1 = ft_atoi(temp[1]);
			data->res2 = ft_atoi(temp[2]);
		}
		else if (!ft_strncmp(map, "F ", 2))
		{
			temp = ft_split(map + 2, ',');
			buf1 = ft_atoi(temp[0]);
			buf2 = ft_atoi(temp[1]);
			buf3 = ft_atoi(temp[2]);
			if (buf1 >= 0 && buf1 <= 255 && buf2 >= 0 && buf2 <= 255 && buf3 >= 0 && buf3 <= 255)
				data->floor = (buf1 << 16) + (buf2 << 8) + buf3;
		}
		else if (!ft_strncmp(map, "C ", 2))
		{
			temp = ft_split(map + 2, ',');
			buf1 = ft_atoi(temp[0]);
			buf2 = ft_atoi(temp[1]);
			buf3 = ft_atoi(temp[2]);
			if (buf1 >= 0 && buf1 <= 255 && buf2 >= 0 && buf2 <= 255)
				data->ceiling = (buf1 << 16) + (buf2 << 8) + buf3;
		}
		else if (!ft_strncmp(map, "NO ", 3))
		{
			temp = ft_split(map, ' ');
			data->north.img = mlx_xpm_file_to_image(data->mlx, temp[1], &data->north.x, &data->north.y);
			// if(data->north.img == NULL)
			// 	printf("Error: no texture\n");
			// 	exit(0);
			data->north.addr = mlx_get_data_addr(data->north.img, &data->north.bits_per_pixel, &data->north.line_length, &data->north.endian);
		}
		else if (!ft_strncmp(map, "SO ", 3))
		{
			temp = ft_split(map, ' ');
			data->south.img = mlx_xpm_file_to_image(data->mlx, temp[1], &data->south.x, &data->south.y);
			data->south.addr = mlx_get_data_addr(data->south.img, &data->south.bits_per_pixel, &data->south.line_length, &data->south.endian);
		}
		else if (!ft_strncmp(map, "WE ", 3))
		{
			temp = ft_split(map, ' ');
			data->west.img = mlx_xpm_file_to_image(data->mlx, temp[1], &data->west.x, &data->west.y);
			data->west.addr = mlx_get_data_addr(data->west.img, &data->west.bits_per_pixel, &data->west.line_length, &data->west.endian);
		}
		else if (!ft_strncmp(map, "EA ", 3))
		{
			temp = ft_split(map, ' ');
			data->east.img = mlx_xpm_file_to_image(data->mlx, temp[1], &data->east.x, &data->east.y);
			data->east.addr = mlx_get_data_addr(data->east.img, &data->east.bits_per_pixel, &data->east.line_length, &data->east.endian);
		}
		else if (!ft_strncmp(map, "S ", 2))
		{
			temp = ft_split(map, ' ');
			data->sprite.img = mlx_xpm_file_to_image(data->mlx, temp[1], &data->sprite.x, &data->sprite.y);
			data->sprite.addr = mlx_get_data_addr(data->sprite.img, &data->sprite.bits_per_pixel, &data->sprite.line_length, &data->sprite.endian);
		}
		else if (*map == '1' || *map == ' ')
			return(1);
		else if (*map != '\0')
		{		
			printf("%s\n", map);	
			ft_putstr_fd("invalid map\n", 1);
			exit(1);
		}
		return(0);
}

void ft_map(t_list **head, int size, t_data *data)
{
	char **map = ft_calloc(size + 1, sizeof(char *));
	t_list *tmp;
	tmp = *head;
	int i;
	i = 0;
	size_t max;
	max = 0;
	data->map_size = size;
	while(tmp)
	{
		map[i] = tmp->content;
		if(ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
		tmp = tmp->next;
	}
	data->max_width = max;
	i = 0;
	while (map[i])
	{
		if(ft_parcing(map[i], data))
		{
			ft_createmap(map, i, size, data);
			break;
			// ft_putendl_fd(map[i], 1);
		}
		i++;
	}
}

int ft_gnl(int fd, t_data *data)
{
	t_list *head = NULL;
	char *line = NULL;

	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	ft_map(&head, ft_lstsize(head), data);
	// free(line);
	close(fd);
	return(0);
}
