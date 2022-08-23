#include "../push_swap.h"

int	*three_sort(int *a, t_lists lists)
{
	if (a[0] > a[1] && a[1] < a[2])
		command_sa(lists);
	if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		command_rra(lists);
	if (a[1] < a[2] && a[0] > a[2])
		command_ra(lists);
	if (a[0] > a[1] && a[1] > a[2])
	{
		command_sa(lists);
		command_rra(lists);
	}
	if (a[1] > a[2] && a[0] < a[2])
	{
		command_rra(lists);
		command_sa(lists);
	}
	return (a);
}

int	*six_sort(t_lists lists)
{
	int		min;

	while (lists.a_len > 3)
	{
		min = get_min(lists.a, lists.a_len);
		if (lists.a[0] == min)
			command_pb(lists, &lists.a_len, &lists.b_len);
		else
			command_ra(lists);
	}
	three_sort(lists.a, lists);
	while (lists.b_len > 0)
		command_pa(lists, &lists.a_len, &lists.b_len);
	return (lists.a);
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
				command_rb(lists);
			command_pa(lists, &lists.a_len, &lists.b_len);
		}
	}
}