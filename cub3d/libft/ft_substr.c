/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:41:11 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 15:09:06 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	char	*dst;
	char	*res;
	size_t	l;

	if (s == NULL)
		return (0);
	l = ft_strlen(s);
	src = (char *)s + start;
	if (start > l)
		return (ft_strdup(""));
	dst = malloc(sizeof(char) * (len + 1));
	res = dst;
	if (dst == NULL)
		return (NULL);
	while (*src && len--)
		*dst++ = *src++;
	*dst = '\0';
	return (res);
}
