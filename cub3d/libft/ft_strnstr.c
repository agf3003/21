/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:56:02 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 14:42:11 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*a;
	char	*b;
	size_t	l;

	a = (char *)haystack;
	b = (char *)needle;
	l = ft_strlen(b);
	if (l == 0)
		return (a);
	while (*a && len >= l && len--)
	{
		if (ft_strncmp(a, b, l) == 0)
			return (a);
		a++;
	}
	return (NULL);
}
