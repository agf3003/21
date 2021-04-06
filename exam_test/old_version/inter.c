/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 14:12:26 by bellan            #+#    #+#             */
/*   Updated: 2021/02/09 19:02:01 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int res[127];

void ft_inter(char *s1, char *s2)
{
	int i;

	i = 0;
	while(*s1)
	{
		while(s2[i] != '\0')
		{
			if (*s1 == s2[i] && res[(int)*s1] == 0)
			{
				res[(int)*s1] = 1;
				write(1, s1, 1);
			}
			i++;
		}
		s1++;
		i = 0;
	}
}
int main(int argc, char *argv[])
{
	//char *s1 = "Hiello, world";
	//char *s2 = "Hi honeymoon";
	char *s1;
	char *s2;	
	int i;

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
		ft_inter(s1, s2);
	}
	write(1,"\n",1);
	return(0);
}
