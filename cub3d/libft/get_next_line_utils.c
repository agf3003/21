/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 13:24:24 by bellan            #+#    #+#             */
/*   Updated: 2021/02/21 15:37:13 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		clean(int f, t_gnl **head, int fd)
{
	t_gnl *temp;
	t_gnl *backup;

	if (f == 1)
		return (f);
	temp = *head;
	if (temp->fd == fd)
	{
		backup = temp->next;
		free(temp->remain);
		free(temp);
		*head = backup;
		return (f);
	}
	while (temp->next->fd != fd)
		temp = temp->next;
	backup = temp->next->next;
	free(temp->next->remain);
	free(temp->next);
	temp->next = backup;
	return (f);
}

int		ft_strnchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
