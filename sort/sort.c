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
#include <stdio.h>
void	do_quicksort(t_lists lists, size_t len)
{
	size_t	i;
	int	separater;
	int	max;

	// while (!is_sorted(lists.a, lists.a_len))
	for (size_t j = 0; j < 5; j++)
	{
		separater = lists.a[0];
		// printf("---separete start---\nseparater == %d\n", separater);
		separate_list(&lists, separater, len);
		// printf("---separete finish---\n");
		i = 0;
		// printf("---sort start---\n");
		while (lists.b_len > 0)
		{
			max = get_max(lists.b, lists.b_len);
			while (max != lists.b[0])
				command_rb(lists);
			command_pa(lists, &lists.a_len, &lists.b_len);
			i ++;
		}
		// for (size_t j = 0; j < 10; j++)
		// 	printf("%d ", lists.a[j]);
		// printf("\n");
		// printf("---sort finish---\n");
		// printf("---rotate start---\n");
		while (i > 0 && !is_sorted(lists.a, lists.a_len))
		{
			command_ra(lists);
			i --;
		}
		// for (size_t j = 0; j < 10; j++)
		// 	printf("%d ", lists.a[j]);
		// printf("\n");
		// printf("---rotate finish---\n");
	}
}
