/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:55:04 by bellan            #+#    #+#             */
/*   Updated: 2020/11/24 11:20:18 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *a;
	unsigned char f;

	a = (unsigned char *)s;
	f = (unsigned char)c;
	while (n--)
	{
		if (*a == f)
			return (a);
		a++;
	}
	return (NULL);
}
