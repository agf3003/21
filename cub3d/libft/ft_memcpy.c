/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:50:48 by bellan            #+#    #+#             */
/*   Updated: 2021/03/23 19:35:48 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *new;
	char *old;

	new = (char *)dst;
	old = (char *)src;
	if (n > 0)
	{
		while (n--)
			*new++ = *old++;
	}
	return (dst);
}
