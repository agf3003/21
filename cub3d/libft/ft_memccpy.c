/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:00:24 by bellan            #+#    #+#             */
/*   Updated: 2020/11/20 20:52:35 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *new;
	unsigned char *old;

	new = (unsigned char *)dst;
	old = (unsigned char *)src;
	c = (unsigned char)c;
	while (n--)
	{
		*new = *old;
		if (*old == c)
			return (new + 1);
		new++;
		old++;
	}
	return (0);
}
