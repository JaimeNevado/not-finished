/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:52 by jnevado-          #+#    #+#             */
/*   Updated: 2022/11/04 15:53:06 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, unsigned int n)
{
	unsigned char	*tmp;
	unsigned char	*src_tmp;

	if (dst == 0 && src == 0)
		return (0);
	tmp = (unsigned char *) dst;
	src_tmp = (unsigned char *) src;
	while (n > 0)
	{
		*tmp++ = *src_tmp++;
		n--;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *save, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!save)
	{
		save = (char *)malloc(1 * sizeof (char));
		save[0] = '\0';
	}
	if (!save || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(save) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buff[j] != '\0')
		str[i++] = buff [j++];
	str[ft_strlen(save) + ft_strlen(buff)] = '\0';
	free(save);
	return (str);
}

int	ft_line_len(char *ptr)
{
	int	len;

	len = 0;
	while (ptr[len] && ptr[len] != '\n')
		len++;
	if (ptr[len] == '\n')
		len++;
	return (len);
}
