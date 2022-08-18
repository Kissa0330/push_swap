#include "push_swap.h"

long long ft_atoi(const char *str)
{
	int				negativeflag;
	long long		num;

	num = 0;
	negativeflag = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negativeflag = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str ++;
	}
	return (num * negativeflag);
}

void	error_output(void *stack)
{
	if (stack)
		free(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}