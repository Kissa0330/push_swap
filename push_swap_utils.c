#include "push_swap.h"

long long	ft_atoi(const char *str)
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

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		*str++ = '\0';
		i++;
	}
}

void	error_output(void *stack1, void *stack2)
{
	if (stack1)
		free(stack1);
	if (stack2)
		free(stack2);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
