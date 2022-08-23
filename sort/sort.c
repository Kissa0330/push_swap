#include "push_swap.h"

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

int	*six_sort(t_lists lists, size_t len)
{
	int		min;

	while (lists.a_len > 3)
	{
		min = get_min(lists.a, lists.a_len);
		if (lists.a[0] == min)
			command_pb(lists, len);
		else
			command_ra(lists, len);
	}
	three_sort(lists.a, lists, len);

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