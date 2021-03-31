/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:46:27 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 14:45:40 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	a = a + ft_strlen(s);
	if (c == 0)
		return (a);
	while (a != s)
	{
		a--;
		if (*a == c)
			return (a);
	}
	return (NULL);
}
