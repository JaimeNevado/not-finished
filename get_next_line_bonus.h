/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnevado- <jnevado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:41:53 by jaimenevado       #+#    #+#             */
/*   Updated: 2022/11/04 16:03:18 by jnevado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

unsigned int	ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_line_len(char *ptr);

void			ft_clean_memory(char **memory);
int				ft_fill_memory(char **memory, int fd);
char			*ft_get_line(char **memory);
char			*get_next_line(int fd);

#endif
