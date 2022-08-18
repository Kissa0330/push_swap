#ifndef FT_PRINTF_H
# define FT_PRINTF_H
	#include <stddef.h>
	#include <unistd.h>
	#include <stdlib.h>
	typedef struct s_lists
	{
		int *a;
		int *b;
	}	t_lists;

	int	push_swap(char **list_origin);
	int	ft_atoi(const char *str);
#endif