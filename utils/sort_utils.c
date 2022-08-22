#include "../push_swap.h"

int	*three_sort(int *a, t_lists lists, size_t len)
{
	if (a[0] > a[1] && a[1] < a[2])
		command_sa(lists);
	if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		command_rra(lists, len);
	if (a[1] < a[2] && a[0] > a[2])
		command_ra(lists, len);
	if (a[0] > a[1] && a[1] > a[2])
	{
		command_sa(lists);
		command_rra(lists, len);
	}
	if (a[1] > a[2] && a[0] < a[2])
	{
		command_rra(lists, len);
		command_sa(lists);
	}
	return (a);
}

void	separate_list(t_lists lists, int separater, size_t len)
{
	size_t	i;

	i = 0;
	while (len > i)
	{
		if (lists.a[0] >= separater)
			command_pb(lists, len);
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

void	do_quicksort(t_lists lists, size_t len)
{
	int	separater;
	int	max;

	separater = -2147483648;
	separate_list(lists, separater, len);
	while (!is_sorted(lists.a, len))
	{
		while (lists.b[0] != 0)
		{
			max = get_max(lists.b, len);
			while (max != lists.b[0])
				command_rb(lists, len);
			command_pa(lists, len);
		}
	}
}
