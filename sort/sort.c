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
	size_t	sorted_len;
	size_t	separate_len;
	size_t	len_to_max;
	int		separater;
	int		max;

	sorted_len = 0;
	// printf("a_len == %zu\n", lists.a_len);
	// printf("b_len == %zu\n", lists.b_len);
	while (!is_sorted(lists.a, lists.a_len))
	// for (size_t j = 0; j < 5; j++)
	{
		separate_len = lists.a_len - sorted_len;
		separater = get_median(get_median(lists.a[0], lists.a[separate_len / 3 / 2], lists.a[separate_len / 3 - 1]),get_median(lists.a[separate_len / 3], lists.a[separate_len / 3 - separate_len / 3 / 2], lists.a[separate_len / 3 * 2 - 1]), get_median(lists.a[separate_len / 3 * 2], lists.a[separate_len / 3 - separate_len / 3 / 2], lists.a[separate_len - 1]));
		if (sorted_len >= len / 2)
			separater = get_min(lists.a, separate_len);
		// printf("---separete start---\nseparater == %d\n", separater);
		separate_list(&lists, separater, separate_len);
		// printf("---separete finish---\n");
		i = lists.b_len;
		// printf("a_len == %zu\n", lists.a_len);
		// printf("b_len == %zu\n", lists.b_len);
		// printf("---sort start---\n");
		while (lists.b_len > 0)
		{
			max = get_max(lists.b, lists.b_len);
			len_to_max = get_lentomax(lists.b, lists.b_len);
			// for (size_t j = 0; j < len; j++)
			// 	printf("%d ", lists.b[j]);
			// printf("\n");
			// printf("len_to_max == %zu, len == %zu\n", len_to_max, len);
			if (len_to_max >= lists.b_len / 2)
			{
				while (max != lists.b[0])
					command_rrb(lists);
			}
			else if (len_to_max <= lists.b_len / 2)
			{
				while (max != lists.b[0])
					command_rb(lists);
			}
			command_pa(lists, &lists.a_len, &lists.b_len);
		}
		// for (size_t j = 0; j < len; j++)
		// 	printf("%d ", lists.a[j]);
		// printf("\n");
		// printf("---sort finish---\n");
		// printf("---rotate start---\n");
		sorted_len += i;
		if (sorted_len >= lists.a_len / 2)
		{
			i = lists.a_len - sorted_len;
			while (i > 0 && !is_sorted(lists.a, lists.a_len))
			{
				command_rra(lists);
				i --;
			}
		}
		else if (sorted_len <= lists.a_len / 2)
		{
			i = sorted_len;
			while (i > 0 && !is_sorted(lists.a, lists.a_len))
			{
				command_ra(lists);
				i --;
			}
		}
		// printf("sorted_len == %zu\n", sorted_len);
		// for (size_t j = 0; j < len; j++)
		// 	printf("%d ", lists.a[j]);
		// printf("\n");
		// printf("---rotate finish---\n");
	}
}
