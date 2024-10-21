#ifndef GET_NEXT_LINE_BONUS_H	//헤더 가드 시작
#define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>	// malloc

// 버퍼 사이즈 정의
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// 구조체 정의
typedef struct s_fd
{
	int	fd;	// 파일 디스크립터
	char	*backup;	// 개행 이후 문자열을 저장할 변수
	struct s_fd *next;	// 다음 노드를 가르키는 포인터
} t_fd;	// 이 구조체를 간단히 사용하기 위한 이름

// 함수 원형 정의
char	get_next_line_bonus(int fd);

#endif	// 헤더 가드 끝