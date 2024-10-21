/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjang <youjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:27:14 by youjang           #+#    #+#             */
/*   Updated: 2024/10/18 22:00:12 by youjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// 예외처리, 함수를 실행
char	*get_next_line_bonus(int fd)
{
	
	char	*line;	// 한 줄을 저장할 포인터
	static t_fd	*head;	// fd 데이터의 시작점을 가리킬 포인터

	if (fd < 0 || BUFFER_SIZE == 0)	// 예외처리
		return (NULL);
	
	
}

// 한줄을 읽는 함수
char	*read_file(fd, backup)
{
	
}

// 메모리 해제하는 함수

