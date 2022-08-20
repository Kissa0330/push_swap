#include "../push_swap.h"

int	*three_sort(int *a, t_lists lists, size_t len)
{
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
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
	if (a[0] > a[2])
		command_ra(lists, len);
	if (a[0] > a[1])
		command_sa(lists);
	if (a[1] > a[2])
		command_rra(lists, len);
	return (a);
}

void	separate_list(t_lists lists, int separater, size_t len)
{
	size_t	i;

	i = 0;
	while (len - 1 > i)
	{
		if (lists.a[0] >= separater)
			command_pb(lists, len);
		else
			command_ra(lists, len);
		i ++;
	}
}

void	do_quicksort(t_lists lists, size_t len)
{

}
