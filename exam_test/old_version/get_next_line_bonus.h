/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:10:06 by bellan            #+#    #+#             */
/*   Updated: 2020/12/05 16:22:45 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

typedef	struct				s_gnl
{
	char					*remain;
	int						fd;
	struct s_gnl			*next;
}							t_gnl;

int							get_next_line(int fd, char **line);
size_t						ft_strlen(char *s);
char						*ft_strjoin(char *s1, char *s2);
int							ft_strchr(char *s, char c);
char						*ft_strdup(char *s1);
int							clean(int f, t_gnl **head, int fd);

#endif
