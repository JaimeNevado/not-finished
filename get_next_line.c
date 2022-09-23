/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:57 by jnevado-          #+#    #+#             */
/*   Updated: 2022/09/23 15:21:07 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
char	*get_next_line(int fd)
{
	fd = open ("texto.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	close (fd);
	return (0);
}
*/

int	main(void)
{
	int	fd;

	fd = open ("texto.txt", O_RDONLY);
	if (fd == -1)
		printf("Funciona");
	close (fd);
	return (0);
}
