/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjang <youjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:09:24 by youjang           #+#    #+#             */
/*   Updated: 2024/10/18 17:00:19 by youjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H	
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, const char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strncpy(char *dest, const char *src, size_t n);
char	*get_next_line(int fd);

#endif
