/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:45:51 by bellan            #+#    #+#             */
/*   Updated: 2020/11/20 20:22:43 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nb(char *dst, int n, int i)
{
	char			*res;
	unsigned int	b;
	int				l;

	l = 1;
	res = dst;
	if (n < 0)
	{
		*(dst++) = '-';
		i--;
		b = -n;
	}
	else
		b = n;
	while (i--)
		l = l * 10;
	(b <= 9) ? *dst = b + '0' : 0;
	while (l > 0)
	{
		*dst++ = b / l + '0';
		b = b % l;
		l /= 10;
	}
	*dst = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	b;
	char			*dst;

	i = 0;
	if (n < 0)
	{
		i++;
		b = -n;
	}
	else
		b = n;
	while ((b = b / 10) > 0)
		i++;
	if (!(dst = malloc(sizeof(char) * i + 2)))
		return (NULL);
	return (ft_nb(dst, n, i));
}
