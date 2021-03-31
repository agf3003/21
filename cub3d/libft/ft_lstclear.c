/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:56:34 by bellan            #+#    #+#             */
/*   Updated: 2020/11/20 20:33:10 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;

	if (lst)
	{
		while (*lst != NULL)
		{
			del((*lst)->content);
			ptr = (*lst)->next;
			free(*lst);
			*lst = ptr;
		}
		lst = NULL;
	}
}
