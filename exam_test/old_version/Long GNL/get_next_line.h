/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bellan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:47:59 by bellan            #+#    #+#             */
/*   Updated: 2021/02/15 19:07:04 by bellan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int get_next_line(char **line);
int ft_strlen(char *s);
char *ft_strdup(char *s);
int ft_strchr(char *s, char c);
char *ft_strjoin(char *s1, char *s2);

#endif
