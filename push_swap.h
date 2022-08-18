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

	void		push_swap(long long length, char **list_origin);
	long long	ft_atoi(const char *str);
	void		error_output(void *stack);
#endif