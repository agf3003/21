#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int g_width;
int g_precision;
int g_result;

static void ft_putchar(char c)
{
	write(1, &c, 1);
	g_result++;
}

static int ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i] != '\0')
		i++;
	return(i);
}

static void ft_putstr(char *s, int i)
{
	while (*s != '\0' && i > 0)
	{
		ft_putchar(*s);
		s++;
		i--;
	}
}
static char *ft_itoa(unsigned long nbr, int factor)
{
	char *str = NULL;
	int temp_nbr;
	int len;
	
	len = 0;
	temp_nbr = nbr;
	if(nbr == 0)
		len++;
	while(temp_nbr > 0)
	{
		temp_nbr = temp_nbr / factor;
		len++;
	}
	str = (char *)malloc(len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = nbr % factor;
		if (nbr % factor > 9)
			str[len - 1] = str[len - 1] + 'a' - 10;
		else
			str[len - 1] = str[len - 1] + '0';
		len--;
		nbr = nbr / factor;
	}
	return(str);
}
static void ft_ptf_s(char *s)
{
	int len;
	if(s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (g_precision != -1 && g_precision < len)
		len = g_precision;
	while (g_width > len)
	{
		ft_putchar(' ');
		g_width--;
	}
	ft_putstr(s, len);
}
static void ft_ptf_x(unsigned long nbr)
{
	char *str;
	str = ft_itoa(nbr, 16);
	int len;
	len = ft_strlen(str);
	if (g_precision != -1 && g_precision > len)
		len = g_precision;
	if (nbr == 0 && g_precision == 0)
		len = 0;
	while (g_width > len)
	{
		ft_putchar(' ');
		g_width--;
	}
	while (len > ft_strlen(str))
	{
		ft_putchar('0');
		len--;
	}
	if (nbr == 0 && g_precision == 0)
		ft_putstr(str, 0);
	else
		ft_putstr(str, ft_strlen(str));
	free(str);
}

static void ft_ptf_d(int nbr)
{
	char *str;
	int minus;

	minus = 0;
	if (nbr < 0)
	{
		minus = 1;
		nbr = nbr * -1;
	}
	str = ft_itoa(nbr, 10);
	int len;
	len = ft_strlen(str);
	if (g_precision != -1 && g_precision > len)
		len = g_precision;
	if (nbr == 0 && g_precision == 0)
		len = 0;
	if (minus == 1 && g_width > 0)
		g_width--;
	while (g_width > len)
	{
		ft_putchar(' ');
		g_width--;
	}
	if (minus == 1)
		ft_putchar('-');
	while (len > ft_strlen(str))
	{
		ft_putchar('0');
		len--;
	}
	if (nbr == 0 && g_precision == 0)
		ft_putstr(str, 0);
	else
		ft_putstr(str, ft_strlen(str));	
    free(str);
}

// int ft_printf(const char *str,...)
// {
// 	g_result = 0;
// 	int i = 0;
// 	va_list(ap);

// 	va_start(ap, str);
// 	while(str[i] != '\0')
// 	{
// 		if (str[i] == '%' && str[i+1] != '\0')
// 		{
// 			i++;
// 			g_width = 0;
// 			g_precision = -1;
// 			while(str[i] >= '0' && str[i] <= '9')
// 				{
// 					g_width = g_width * 10 + (str[i] - '0');
// 					i++;
// 				}
// 			if (str[i] == '.')
// 				{
// 					i++;
// 					g_precision = 0;
// 					while(str[i] >= '0' && str [i] <= '9')
// 					{
// 						g_precision = g_precision * 10 + (str[i] - '0');
// 						i++;
// 					}
// 				}
// 			if (str[i] == 's')
// 				ft_ptf_s(va_arg(ap, char *));
// 			else if (str[i] == 'x')
// 				ft_ptf_x(va_arg(ap, unsigned int));
// 			else if (str[i] == 'd')
// 				ft_ptf_d(va_arg(ap, int));
// 			else
// 				ft_putchar(str[i]);
// 		}
// 		else
// 			ft_putchar(str[i]);
// 		i++;
// 	}
// 	va_end(ap);
// 	return(g_result);
// }

int ft_printf(char *str,...)
{
	g_result = 0;
	int i = 0;
	va_list(ap);
	va_start(ap, str);

	while(str[i] != '\0')
	{
		if(str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			g_width = 0;
			g_precision = -1;
			while(str[i] >= '0' && str[i] <= '9')
			{
				g_width = g_width * 10 + (str[i] - '0');
				i++;
			}
			if(str[i] == '.')
			{
				i++;
				g_precision = 0;
				while(str[i] >= '0' && str[i] <= '9')
				{
					g_precision = g_precision * 10 + (str[i] - '0');
					i++;
				}
			}
			if(str[i] == 's')
				ft_ptf_s(va_arg(ap, char *));
			else if (str[i] == 'd')
				ft_ptf_d(va_arg(ap, int));
			else if (str[i] == 'x')
				ft_ptf_x(va_arg(ap, unsigned int));
			else
				ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return(g_result);
}


int main()
{
	char *str = NULL;
	printf("\n\nTEST %%s\n\n");
	printf("\n___TEST %%s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", str));
	printf("Original - %d\n", printf("|%s|\n", str));

	printf("\n___TEST %%ss___\n");
	printf("No original - %d\n", ft_printf("|%ss|\n", str));
	printf("Original - %d\n", printf("|%ss|\n", str));

	printf("\n___TEST %%20s___\n");
	printf("No original - %d\n", ft_printf("|%20s|\n", str));
	printf("Original - %d\n", printf("|%20s|\n", str));

	printf("\n___TEST %%2s___\n");
	printf("No original - %d\n", ft_printf("|%2s|\n", str));
	printf("Original - %d\n", printf("|%2s|\n", str));

	printf("\n___TEST %%.2s___\n");
	printf("No original - %d\n", ft_printf("|%.2s|\n", str));
	printf("Original - %d\n", printf("|%.2s|\n", str));

	printf("\n___TEST %%.20s___\n");
	printf("No original - %d\n", ft_printf("|%.20s|\n", str));
	printf("Original - %d\n", printf("|%.20s|\n", str));

	printf("\n___TEST %%2.20s___\n");
	printf("No original - %d\n", ft_printf("|%2.20s|\n", str));
	printf("Original - %d\n", printf("|%2.20s|\n", str));

	printf("\n___TEST %%22.20s___\n");
	printf("No original - %d\n", ft_printf("|%22.20s|\n", str));
	printf("Original - %d\n", printf("|%22.20s|\n", str));

	printf("\n___TEST %%12.20s___\n");
	printf("No original - %d\n", ft_printf("|%12.20s|\n", str));
	printf("Original - %d\n", printf("|%12.20s|\n", str));

	printf("\n___TEST %%12.s___\n");
	printf("No original - %d\n", ft_printf("|%12.s|\n", str));
	printf("Original - %d\n", printf("|%12.s|\n", str));

	printf("\n___TEST %%.s___\n");
	printf("No original - %d\n", ft_printf("|%.s|\n", str));
	printf("Original - %d\n", printf("|%.s|\n", str));

	printf("\n___TEST %%20.s___\n");
	printf("No original - %d\n", ft_printf("|%20.s|\n", str));
	printf("Original - %d\n", printf("|%20.s|\n", str));

	printf("\n___TEST %%2.s___\n");
	printf("No original - %d\n", ft_printf("|%2.s|\n", str));
	printf("Original - %d\n", printf("|%2.s|\n", str));



	printf("\n\nTEST %%d\n\n");
	int num = 0;
	printf("\n___TEST %%d___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", num));
	printf("Original - %d\n", printf("|%d|\n", num));

	printf("\n___TEST %%dd___\n");
	printf("No original - %d\n", ft_printf("|%dd|\n", num));
	printf("Original - %d\n", printf("|%dd|\n", num));

	printf("\n___TEST %%20d___\n");
	printf("No original - %d\n", ft_printf("|%20d|\n", num));
	printf("Original - %d\n", printf("|%20d|\n", num));

	printf("\n___TEST %%2d___\n");
	printf("No original - %d\n", ft_printf("|%2d|\n", num));
	printf("Original - %d\n", printf("|%2d|\n", num));

	printf("\n___TEST %%.2d___\n");
	printf("No original - %d\n", ft_printf("|%.2d|\n", num));
	printf("Original - %d\n", printf("|%.2d|\n", num));

	printf("\n___TEST %%.20d___\n");
	printf("No original - %d\n", ft_printf("|%.20d|\n", num));
	printf("Original - %d\n", printf("|%.20d|\n", num));

	printf("\n___TEST %%2.20s___\n");
	printf("No original - %d\n", ft_printf("|%2.20d|\n", num));
	printf("Original - %d\n", printf("|%2.20d|\n", num));

	printf("\n___TEST %%22.20d___\n");
	printf("No original - %d\n", ft_printf("|%22.20d|\n", num));
	printf("Original - %d\n", printf("|%22.20d|\n", num));

	printf("\n___TEST %%12.20d___\n");
	printf("No original - %d\n", ft_printf("|%12.20d|\n", num));
	printf("Original - %d\n", printf("|%12.20d|\n", num));

	printf("\n___TEST %%12.d___\n");
	printf("No original - %d\n", ft_printf("|%12.d|\n", num));
	printf("Original - %d\n", printf("|%12.d|\n", num));

	printf("\n___TEST %%.d___\n");
	printf("No original - %d\n", ft_printf("|%.d|\n", num));
	printf("Original - %d\n", printf("|%.d|\n", num));

	printf("\n___TEST %%20.d___\n");
	printf("No original - %d\n", ft_printf("|%20.d|\n", num));
	printf("Original - %d\n", printf("|%20.d|\n", num));

	printf("\n___TEST %%2.d___\n");
	printf("No original - %d\n", ft_printf("|%2.d|\n", num));
	printf("Original - %d\n", printf("|%2.d|\n", num));

	printf("\n\nTEST %%x\n\n");
	unsigned int un = 0;
	printf("\n___TEST %%x___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", un));
	printf("Original - %d\n", printf("|%x|\n", un));

	printf("\n___TEST %%xx___\n");
	printf("No original - %d\n", ft_printf("|%xx|\n", un));
	printf("Original - %d\n", printf("|%xx|\n", un));

	printf("\n___TEST %%20x___\n");
	printf("No original - %d\n", ft_printf("|%20x|\n", un));
	printf("Original - %d\n", printf("|%20x|\n", un));

	printf("\n___TEST %%2x___\n");
	printf("No original - %d\n", ft_printf("|%2x|\n", un));
	printf("Original - %d\n", printf("|%2x|\n", un));

	printf("\n___TEST %%.2x___\n");
	printf("No original - %d\n", ft_printf("|%.2x|\n", un));
	printf("Original - %d\n", printf("|%.2x|\n", un));

	printf("\n___TEST %%.20x___\n");
	printf("No original - %d\n", ft_printf("|%.20x|\n", un));
	printf("Original - %d\n", printf("|%.20x|\n", un));

	printf("\n___TEST %%2.20x___\n");
	printf("No original - %d\n", ft_printf("|%2.20x|\n", un));
	printf("Original - %d\n", printf("|%2.20x|\n", un));

	printf("\n___TEST %%22.20x___\n");
	printf("No original - %d\n", ft_printf("|%22.20x|\n", un));
	printf("Original - %d\n", printf("|%22.20x|\n", un));

	printf("\n___TEST %%12.20x___\n");
	printf("No original - %d\n", ft_printf("|%12.20x|\n", un));
	printf("Original - %d\n", printf("|%12.20x|\n", un));

	printf("\n___TEST %%12.x___\n");
	printf("No original - %d\n", ft_printf("|%12.x|\n", un));
	printf("Original - %d\n", printf("|%12.x|\n", un));

	printf("\n___TEST %%.x___\n");
	printf("No original - %d\n", ft_printf("|%.x|\n", un));
	printf("Original - %d\n", printf("|%.x|\n", un));

	printf("\n___TEST %%20.x___\n");
	printf("No original - %d\n", ft_printf("|%20.x|\n", un));
	printf("Original - %d\n", printf("|%20.x|\n", un));

	printf("\n___TEST %%2.x___\n");
	printf("No original - %d\n", ft_printf("|%2.x|\n", un));
	printf("Original - %d\n", printf("|%2.x|\n", un));

	return (0);
}
// 	printf("[%10.2s]\n", "toto"); 
// 	ft_printf("[%10.2s]\n", "toto"); 
// 	printf("Magic [%s] is [%10.5d]\n", "number", -42); 
// 	ft_printf("Magic [%s] is [%10.5d]\n", "number", -42);
// 	printf("Hexadecimal for [%.5d] is [%10.5x]\n", -42, 42); 
// 	ft_printf("Hexadecimal for [%.5d] is [%10.5x]\n", -42, 42);
// 	return(0);
// }
