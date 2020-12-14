/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoracho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:49 by amoracho          #+#    #+#             */
/*   Updated: 2020/12/13 18:02:12 by amoracho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_empty(char **line)
{
	int i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}
//char	*duplicate(char *cache, int len)
//{
//	char	aux[len];
//	int		i;
//
//	i = 0;
//	while (i < len)
//	{
//		aux[i] = cache[i];
//	}
//	return (aux);
//}

int		get_next_line(int fd, char **line)
{
	char cache[1000000];
	char buf[1];
	ssize_t bytes_read;
	int i;

	i = 0;
	bytes_read = read(fd, buf, 1);
	while ((buf[0] != '\n') && (bytes_read != 0))
	{
		cache[i] = buf[0];
		bytes_read = read(fd, buf, 1);
		i++;
	}
	cache[i] = '\0';
	if (buf[0] == '\n')
	{
		cache[i] = '\0';
		line[get_empty(line)] = ft_strdup(cache);
		return (1);
	}
	line[get_empty(line)] = ft_strdup(cache);
	return (0);
}