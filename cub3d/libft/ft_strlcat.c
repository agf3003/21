/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:35:48 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 14:16:00 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (*dst != '\0')
	{
		dst++;
		i++;
	}
	while (*src != '\0' && i < dstsize - 1)
	{
		*dst = *src;
		i++;
		src++;
		dst++;
	}
	*dst = '\0';
	return (i + ft_strlen(src));
}
