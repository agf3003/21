/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:37:54 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 15:02:38 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contain(char const *set, char sym)
{
	if (sym == '\0')
		return (1);
	while (*set != '\0')
	{
		if (*set == sym)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char *new;
	char *slast;
	char *res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	slast = (char *)s1 + ft_strlen(s1);
	while (*s1 != '\0' && ft_contain(set, *s1))
		s1++;
	while (slast != s1 && ft_contain(set, *slast))
		slast--;
	new = malloc(sizeof(char) * (slast - s1 + 2));
	if (new == 0)
		return (0);
	res = new;
	while (s1 <= slast)
		*new++ = *s1++;
	*new = '\0';
	return (res);
}
