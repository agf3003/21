/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:52:28 by bellan            #+#    #+#             */
/*   Updated: 2020/11/20 19:37:43 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	i;
	size_t	l;

	i = 0;
	l = count * size;
	dst = malloc(l);
	if (dst == NULL)
		return (NULL);
	ft_bzero(dst, l);
	return (dst);
}
