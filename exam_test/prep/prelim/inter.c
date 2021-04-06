#include <unistd.h>

int res[127];

void ft_inter(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*s1 != '\0')
	{
		while (s2[i] != '\0')
		{
			if (*s1 == s2[i] && res[(int)*s1] == 0)
			{
				write(1, s1, 1);
				res[(int)*s1] = 1;
			}
			i++;
		}
		s1++;
		i = 0;
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
		ft_inter(s1, s2);
	}
	write(1,"\n",1);
	return(0);
}