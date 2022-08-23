#include "../push_swap.h"

void	separate_list(t_lists lists, int separater, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		if (lists.a[0] >= separater)
			command_pb(lists, len, &lists.a_len, &lists.b_len);
		else
			command_ra(lists, len);
		i ++;
	}
}

bool	is_sorted(int *list, size_t len)
{
	size_t	i;

	i = 1;
	if (list[0] == 0 && list[len/2] == 0 && list[len-1] == 0)
		return (false);
	while (i < len)
	{
		if(!(list[i - 1] <= list[i]))
			return (false);
		i ++;
	}
	return (true);
}

int	get_max(int	*list, size_t len)
{
	int		max;
	size_t	i;

	max = list[0];
	i = 1;
	while (i < len)
	{
		if (max < list[i] && list[i] != 0)
			max = list[i];
		i ++;
	}
	return (max);
}

int	get_min(int	*list, size_t len)
{
	int		min;
	size_t	i;

	min = list[0];
	i = 1;
	while (i < len)
	{
		if (min > list[i] && list[i] != 0)
			min = list[i];
		i ++;
	}
	return (min);
}