/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:57 by jnevado-          #+#    #+#             */
/*   Updated: 2022/09/28 15:06:06 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{	
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_get_line_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*ft_get_line(char *raw)
{
	static char	*str;
	static char	*rest;
	int			i;
	int			j;

	i = ft_get_line_lenght(raw);
	str = malloc((sizeof(char) * i) + 1);
	j = 0;
	while (raw[j] != '\n')
	{
		str[j] = raw[j];
		j++;
	}
	i = 0;
	rest = malloc((sizeof(char) * (BUFFER_SIZE - j)) + 1);
	while (j < BUFFER_SIZE)
	{
		rest[i] = raw[j];
		i++;
		j++;
	}
	str[j] = '\0';
	return (ft_strjoin(str, rest));
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			nr_bytes;

	buf[BUFFER_SIZE] = '\0';
	if (fd == -1)
	{
		return (NULL);
	}
	else
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == 0)
			return (NULL);
	}
	return (ft_get_line(buf));
}

int	main(void)
{
	int			fd;

	fd = open ("texto.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf(" contenido: %s \n ", get_next_line(fd));
	close(fd);
	return (0);
}
