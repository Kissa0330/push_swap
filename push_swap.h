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

	int			*push_swap(size_t length, char **list_origin);
	long long	ft_atoi(const char *str);
	void		error_output(void *stack1, void *stack2);
	void		ft_bzero(void *s, size_t n);
#endif