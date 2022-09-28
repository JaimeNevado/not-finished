/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:04:52 by jnevado-          #+#    #+#             */
/*   Updated: 2022/09/28 12:34:58 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_get_line_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
		i++;
	return (i);
}
