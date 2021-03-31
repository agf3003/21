/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:26:55 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 13:52:11 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	char	*src;
	int		i;
	int		del;

	src = (char *)s;
	i = 0;
	del = 0;
	while (src[i] != '\0')
	{
		while (src[i] == c)
			i++;
		if (src[i] != '\0')
			del++;
		while (src[i] != c && src[i] != '\0')
			i++;
	}
	return (del);
}

static char	**ft_free(char **dst, int m)
{
	while (--m >= 0)
		free(dst[m]);
	free(dst);
	return (NULL);
}

static char	**ft_createstring(char **dst, char const *src, char c)
{
	int i;
	int len;
	int m;

	i = 0;
	len = 0;
	m = 0;
	while (src[i] != '\0')
	{
		while (src[i] == c)
			i++;
		if (src[i] == '\0')
			break ;
		while (src[i] != c && src[i] != '\0')
		{
			i++;
			len++;
		}
		if (!(dst[m] = ft_substr(src, i - len, len)))
			return (ft_free(dst, m));
		m++;
		len = 0;
	}
	dst[m] = NULL;
	return (dst);
}

char		**ft_split(char const *src, char c)
{
	char	**dst;
	int		m;
	int		i;
	int		len;

	i = 0;
	m = 0;
	len = 0;
	if (!src)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_count(src, c) + 1));
	if (!dst)
		return (NULL);
	dst = ft_createstring(dst, src, c);
	return (dst);
}
