/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:39:39 by bellan            #+#    #+#             */
/*   Updated: 2021/01/14 19:38:04 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
int main()
{
    int i;
    
    char *line;
    
    line = NULL;
    while((i = get_next_line(0, &line)))
    {
        if (i < 0)
        {
            printf("i = %d", i);
            return (1);
        }
        printf("i = %d %s\n", i, line);
        free(line);
    }
    printf("i = %d %s\n", i, line);
    free(line);
    return(0);
}

//int main(int argc, char **argv)
// {
// 	int i;
// 	int fd[4];
// 	int j;
//
// 	char *line;
//
// 	line = NULL;
// 	j = 1;
// 	while (j < argc)
// 	{
// 		fd[j] = open(argv[j], O_RDONLY);
// 		while((i = get_next_line(fd[j], &line)))
// 		{
// 			if (i < 0)
// 			{
// 				printf("i = %d", i);
// 				return (1);
// 			}
// 			printf("i = %d %s\n", i, line);
// 			free(line);
// 		}
// 	printf("i = %d %s\n", i, line);
// 		free(line);
// 		close (fd[j]);
// 		j++;
// 	}
// 	return(0);
//}
