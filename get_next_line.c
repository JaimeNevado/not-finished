/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:57 by jnevado-          #+#    #+#             */
/*   Updated: 2022/09/27 17:18:28 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_get_line(char *raw)
{
	char	*str;
	int		i;

	i = 0;
	while (raw[i] != '\n')
		i++;
	str = malloc((sizeof(char) * i) + 1);
	i = 0;
	while (raw[i] != '\n')
	{
		str[i] = raw[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
char	*get_next_line(int fd)
{
	printf("%*u\n", read(fd, BUFFER_SIZE, 4));
	return (0);
}
*/

int	main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	int		nr_bytes;
	char	*string;

	buf[BUFFER_SIZE] = '\0';
	fd = open ("texto.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("No Funciona");
	}
	else
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		close(fd);
		if (nr_bytes == 0)
		{
			printf("Archivo vacio \n");
		}
		else
		{
			printf("El numero de caracteres es %d", nr_bytes);
			printf(" contenido: %s \n ", ft_get_line(buf));
		}
	}
	return (0);
}
