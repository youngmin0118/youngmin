/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjang <youjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 23:04:24 by youjang           #+#    #+#             */
/*   Updated: 2024/10/19 01:49:53 by youjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*process_line(char **save, char *newline_ptr)
{
	char	*line;
	char	*temp;
	size_t	line_len;

	if (!newline_ptr)
		line_len = gnl_strlen(*save);
	else
		line_len = newline_ptr - *save + 1;
	line = (char *)malloc(line_len + 1);
	if (!line)
		return (NULL);
	gnl_strncpy(line, *save, line_len);
	line[line_len] = '\0';
	if (newline_ptr)
		temp = gnl_strjoin(NULL, newline_ptr + 1);
	else
		temp = NULL;
	free(*save);
	*save = temp;
	return (line);
}

static char	*read_and_process(int fd, char **save)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	char	*newline_ptr;
	ssize_t	read_byte;

	while (1)
	{
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		buf[read_byte] = '\0';
		temp = gnl_strjoin(*save, buf);
		if (!temp)
			return (free(*save), *save = NULL);
		*save = temp;
		newline_ptr = gnl_strchr(*save, '\n');
		if (newline_ptr)
			return (process_line(save, newline_ptr));
	}
	if (!*save || !**save)
		return (free(*save), *save = NULL);
	return (process_line(save, NULL));
}

static char	*handle_eof(char **save)
{
	if (*save && **save)
		return (process_line(save, NULL));
	free(*save);
	*save = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = NULL;
	line = read_and_process(fd, &save);
	if (!line)
		line = handle_eof(&save);
	return (line);
}
