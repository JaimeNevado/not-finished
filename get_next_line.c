/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:57 by jnevado-          #+#    #+#             */
/*   Updated: 2022/10/18 15:11:19 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_clean_memory(char	**memory)
{
	char	*new_memo;
	int 	len;
	int 	new_size;

	if (*memory == NULL)
	{
		*memory = (char *) malloc (sizeof(char));
		**memory = '\0';
		return ;
	}
	len = ft_line_len(*memory);
	new_size = ft_strlen(&(*memory)[len]) + 1;
	new_memo = (char *) malloc(sizeof(char) * new_size);
	ft_memcpy(new_memo, &(*memory)[len], new_size);
	free(*memory);
	*memory = new_memo;
}

int	ft_fill_memory(char **memory, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;
	char	*tmp;

	ft_clean_memory(memory);
	ret = 1;
	while (!ft_strchr(*memory, '\n') && ret)
	{
		ret = reaf(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
		{
			return (ret);
		}
		buffer[ret] = '\0';
		tmp = *memory;
		*memory = ft_strjoin(*memory, buffer);
		free(tmp);
	}
}

char	*get_next_line(int fd)
{
	static	char	*memory = NULL;
	char			*line;

	if (ft_fill_memory(&memory, fd) == -1)
	{
		free(memory);
		memory = NULL;
		return (NULL);
	}
	line = ft_get_line(&memory);
	if (!line)
	{
		free(memory);
		memory = NULL;
	}
	return (line);
}
