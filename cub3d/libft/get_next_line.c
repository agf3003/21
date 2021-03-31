/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:36:58 by bellan            #+#    #+#             */
/*   Updated: 2021/02/21 13:47:20 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_remain(char **remain, int position, char **line)
{
	char *temp;

	(*remain)[position] = '\0';
	*line = ft_strdup(*remain);
	temp = ft_strdup(*remain + position + 1);
	free(*remain);
	*remain = temp;
	return (1);
}

static	int	check_buf(char *buf, int res, char **remain, char **line)
{
	char	*temp;
	int		position;

	buf[res] = '\0';
	position = ft_strnchr(buf, '\n');
	buf[position] = '\0';
	*line = ft_strjoin(*remain, buf);
	temp = ft_strdup(buf + position + 1);
	free(*remain);
	*remain = temp;
	free(buf);
	return (1);
}

static int	result(char **line, char **remain, char *buf, int res)
{
	*line = (*remain == NULL) ? ft_strdup("") : ft_strdup(*remain);
	free(*remain);
	*remain = NULL;
	free(buf);
	if (res < 0)
		return (-1);
	return (0);
}

static int	get_line(int fd, char **line, char **remain)
{
	char	*buf;
	int		res;
	int		position;
	char	*temp;

	if (BUFFER_SIZE < 1 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	if (*remain != NULL && (position = ft_strnchr(*remain, '\n')) != -1)
		return (check_remain(remain, position, line));
	if ((buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
		return (-1);
	while ((res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		position = ft_strnchr(buf, '\n');
		if (position == -1)
		{
			temp = ft_strjoin(*remain, buf);
			free(*remain);
			*remain = temp;
		}
		if (position >= 0)
			return (check_buf(buf, res, remain, line));
	}
	return (result(line, remain, buf, res));
}

int			get_next_line(int fd, char **line)
{
	static t_gnl	*head = NULL;
	t_gnl			*temp;

	if (head == NULL)
	{
		if ((head = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
			return (-1);
		head->fd = fd;
		head->next = NULL;
		head->remain = NULL;
	}
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
		{
			if ((temp->next = (t_gnl *)malloc(sizeof(t_gnl))) == NULL)
				return (-1);
			temp->next->next = NULL;
			temp->next->remain = NULL;
			temp->next->fd = fd;
		}
		temp = temp->next;
	}
	return (clean(get_line(temp->fd, line, &temp->remain), &head, fd));
}
