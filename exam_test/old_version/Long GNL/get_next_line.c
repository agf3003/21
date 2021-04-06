#include "get_next_line.h"
#include <fcntl.h>
// int fd;

int ft_strlen (char *s)
{
	int i;
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return(i);
}

int ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return(i);
		i++;
	}
	return(-1);
}

char *ft_strdup(char *s)
{
	char *dest;
	int l;
	int i;
	l = ft_strlen(s);

	i = 0;
	dest = (char *)malloc(sizeof(char)*(l + 1));
	if(!dest)
		return(NULL);
	while(s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *dest;
	int i;
	int l1;
	int l2;

	i = 0;
	if (s1 == NULL)
		return(ft_strdup(s2));
	if (s2 == NULL)
		return(ft_strdup(s1));	
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!dest)
		return (NULL);
	while(s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while(*s2)
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = '\0';
	return(dest);
}

int get_next_line (char **line)
 {
	static char *remain = NULL;
	char *buf;
	int position;
	int res;
	char *temp;
	position = -1;

	if (line == NULL)
		return(-1);
	if (remain != NULL)
		position = ft_strchr(remain, '\n');
	if (position != -1)
	{
		remain[position] = '\0';
		*line = ft_strjoin("", remain);
		temp = ft_strjoin("", remain + position + 1);
		free(remain);
		remain = temp;
		return(1);
	}
	buf = NULL;
	buf = (char *)malloc(sizeof(char)*11);
	if(!buf)
		return(-1);
	while((res = read(0, buf, 10)) > 0)
	{
		buf[res] = '\0';
		position = ft_strchr(buf, '\n');
		if (position == -1)
		{
			temp = ft_strjoin(remain, buf);
			free(remain);
			remain = temp;
			// free(temp);
		}
		if (position != -1)
		{
			buf[position] = '\0';
			*line = ft_strjoin(remain, buf);
			temp = ft_strjoin("", buf + position + 1);
			free(remain);
			remain = temp;
			free(buf);
			free(temp);
			return(1);
		}
	}
	if (res < 0)
	{
		free(remain);
		free(buf);
		return(-1);
	}
	if (remain == NULL)
		*line = ft_strjoin("","");
	if (remain)
		*line = ft_strjoin("", remain);
	free(remain);
	free(buf);
	free(temp);
	return (0);
}

int main()
{	
	// #if 1 //GNL
	int i;
	char *line;

	line = NULL;
	i = get_next_line(&line);
	printf("i = %d %s\n", i, line);
	free(line);
	return(0);
}
// 	#endif
	
// #if 0 //check ft_strjoin
// 	char *s1 = "Hello world";
// 	char *s2 = "Nice day!";

// 	printf("%s\n",ft_strjoin(s1, s2));

// 	#endif
// 	#if 0 //check ft_strdup
// 	char *s = "Hello world";

// 	printf("%s\n",ft_strdup(s));

// 	#endif
// 	#if 0 //check strlen
// 	int i;
// 	char *s = "Hello world";
// 	i = printf("i = %d", ft_strlen(s));

// 	#endif
// 	#if 0 //check strchr
// 	char *s = "Welcome home";
// 	char c = 'o';
// 	int f = ft_strchr(s, c);
// 	printf("%d\n", f);
// 	#endif
// 	return(0);
// }