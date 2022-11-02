/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimenevado <jaimenevado@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:57 by jnevado-          #+#    #+#             */
/*   Updated: 2022/11/02 17:42:26 by jaimenevado      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(save);
		save = NULL;
		return (0);
	}
	save = ft_read_fd(fd, save);
	if (!save)
		return (NULL);
	line = ft_extract_line(save);
	save = ft_new_save(save);
	return (line);
}

char	*ft_read_fd(int fd, char *save)
{
	int		nbytes_read;
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	nbytes_read = 1;
	while (!ft_strchr(save, '\n') && nbytes_read != 0)
	{
		nbytes_read = read(fd, buff, BUFFER_SIZE);
		if (nbytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes_read] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_extract_line(char *save)
{
	unsigned int	i;
	char			*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_save(char *save)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new_save)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}
