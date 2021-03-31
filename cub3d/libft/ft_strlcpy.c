/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:30:50 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 14:17:17 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (src == NULL || dst == NULL)
		return (0);
	while (*src != '\0')
	{
		if (i + 1 < dstsize)
		{
			*dst = *src;
			dst++;
		}
		i++;
		src++;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (i);
}
