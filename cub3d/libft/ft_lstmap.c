/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:48:24 by bellan            #+#    #+#             */
/*   Updated: 2020/11/20 20:41:19 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *dst;
	t_list *new;

	dst = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		new->content = (*f)(lst->content);
		new->next = NULL;
		ft_lstadd_back(&dst, new);
		lst = lst->next;
	}
	return (dst);
}
