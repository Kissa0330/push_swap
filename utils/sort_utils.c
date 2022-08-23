#include "../push_swap.h"
void	separate_list(t_lists *lists, int separater, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		if ((*lists).a[0] >= separater)
			command_pb(*lists, &(*lists).a_len, &(*lists).b_len);
		else
			command_ra(*lists);
		i ++;
	}
}

bool	is_sorted(int *list, size_t len)
{
	size_t	i;

	if (len <= 0)
		return (false);
	i = 1;
	while (i < len)
	{
		if(!(list[i - 1] <= list[i]))
			return (false);
		i ++;
	}
	return (true);
}

int	get_max(int *list, size_t len)
{
	int		max;
	size_t	i;

	max = list[0];
	i = 1;
	while (i < len)
	{
		if (max < list[i])
			max = list[i];
		i ++;
	}
	return (max);
}

int	get_min(int *list, size_t len)
{
	int		min;
	size_t	i;

	min = list[0];
	i = 1;
	while (i < len)
	{
		if (min > list[i])
			min = list[i];
		i ++;
	}
	return (min);
}

int	get_median(int a, int b, int c)
{
	if (a < b && a < c)
	{
		if(b < c)
			return (b);
		else
			return (c);
	}
	if (b < a && b < c)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	if (c < a && c < b)
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	return (a);
}
