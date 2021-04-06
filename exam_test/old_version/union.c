/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:16:09 by bellan            #+#    #+#             */
/*   Updated: 2021/01/06 21:26:34 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int res [127];

void ft_union(char *s1, char *s2)
{
	while (*s1 != '\0')
	{
	   if (res[(int)*s1] == 0)
		{
			write(1, s1, 1);
			res[(int)*s1] = 1;
		}
	   s1++;
	}
	while (*s2 != '\0')
	{
		if (res[(int)*s2] == 0)
		{
			write(1,s2,1);
			res[(int)*s2] = 1;
		}
		s2++;
	}
}

int main(int argc, char **argv)
{
	int i;
	char *s1;
	char *s2;

	i = 0;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (i < 127)
		{
			res[i] = 0;
			i++;
		}
		ft_union(s1, s2);
	}
	write(1,"\n",1);

	return(0);
}
