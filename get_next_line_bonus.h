/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimenevado <jaimenevado@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:41:53 by jaimenevado       #+#    #+#             */
/*   Updated: 2022/11/02 17:42:02 by jaimenevado      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> //read
# include <fcntl.h> //open
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// GET_NEXT_LINE
char	*get_next_line(int fd);
char	*ft_read_fd(int fd, char *save);
char	*ft_extract_line(char *save);
char	*ft_new_save(char *save);

// UTILS
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *save, char *buff);

#endif