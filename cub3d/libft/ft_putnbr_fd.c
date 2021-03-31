/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:07:31 by bellan            #+#    #+#             */
/*   Updated: 2020/11/21 13:37:51 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				l;
	unsigned int	b;
	unsigned int	c;

	l = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		b = -n;
	}
	else
		b = n;
	c = b;
	while ((c = c / 10) > 0)
		l *= 10;
	if (b <= 9)
		ft_putchar_fd(b + '0', fd);
	else
		while (l > 0)
		{
			ft_putchar_fd(b / l + '0', fd);
			b %= l;
			l /= 10;
		}
}
