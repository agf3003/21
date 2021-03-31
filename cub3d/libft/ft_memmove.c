/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:20:23 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 13:19:47 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *new;
	unsigned char *old;

	new = (unsigned char *)dst;
	old = (unsigned char *)src;
	if (len > 0 && (dst || src))
	{
		if (new < old)
		{
			while (len--)
				*new++ = *old++;
		}
		else
		{
			while (len--)
				*(new + len) = *(old + len);
		}
	}
	return (dst);
}
