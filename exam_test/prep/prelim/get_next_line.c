/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:12:04 by bellan            #+#    #+#             */
/*   Updated: 2021/02/17 19:37:30 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int ft_strlen(char *str)
{
	int len = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return(len);
}
int ft_strchr(char *str, char c)
{
	int position = 0;
	while (str[position] != '\0')
	{
		if (str[position] == c)
			return(position);
		position++;
	}
	return(-1);
}
char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	char *dest;
	if (s1 == NULL)
		return(ft_strjoin("", s2));
	if (s2 == NULL)
		return(ft_strjoin("", s1));
	int l1 = ft_strlen(s1);
	int l2 = ft_strlen(s2);
	dest = (char *)malloc(l1 + l2 + 1);
	if(!dest)
		return(NULL);
	while(s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = '\0';
	return(dest);
}
int get_next_line(char **line)
{
	static char *remain = NULL;
	char *buf;
	char *temp;
	int position = -1;
	int res = 0;

	if(!line)
		return(-1);
	if(remain)
		position = ft_strchr(remain, '\n');
	if (position != -1)
	{
		remain[position] = '\0';
		*line = ft_strjoin("", remain);
		temp = ft_strjoin("", remain + position + 1);
		free(remain);
		remain = temp;
		return(1);
	}
	buf = NULL;
	buf = (char *)malloc(11);
	if(!buf)
		return(-1);
	while ((res = read(0, buf, 10)) > 0)
		{
			buf[res] = '\0';
			position = ft_strchr(buf, '\n');
			if (position == -1)
			{
				temp = ft_strjoin(remain, buf);
				free(remain);
				remain = temp;
			}
			else
			{
				buf[position] = '\0';
				*line = ft_strjoin(remain, buf);
				temp = ft_strjoin("", buf + position + 1);
				free(remain);
				remain = temp;
				free(buf);
				return(1);
			}
		}
	if (res < 0)
	{
		free(remain);
		free(buf);
		return(-1);
	}
	if (remain)
		*line = ft_strjoin("", remain);
	else
		*line = ft_strjoin("", "");
	free(remain);
	free(buf);
	return(0);
}
