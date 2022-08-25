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

static void	sort_b_and_push_a(t_lists *lists)
{
	size_t	len_to_max;
	int		max;

	while ((*lists).b_len > 0)
	{
		max = get_max((*lists).b, (*lists).b_len);
		len_to_max = get_lentomax((*lists).b, (*lists).b_len);
		while (max != (*lists).b[0])
		{
			if (len_to_max >= (*lists).b_len / 2)
				command_rrb(*lists);
			else if (len_to_max <= (*lists).b_len / 2)
				command_rb(*lists);
		}
		command_pa(*lists, &(*lists).a_len, &(*lists).b_len);
	}
}
#include <stdio.h>
static void	sort_lists(t_lists *lists, size_t *sorted_len)
{
	size_t	bf_sorted_len;
	size_t	remain_len;
	size_t	separate_len;
	bool	is_separated;

	bf_sorted_len = *sorted_len;
	while ((*lists).b_len > 0)
	{
		is_separated = false;
		remain_len = (*lists).b_len;
		if ((*lists).b_len > 10)
		{
			// printf("---second separate start---\nseparater == %d\n", get_separater((*lists).b, (*lists).b_len));
			separate_list_b(lists, get_separater((*lists).b, (*lists).b_len));
			// printf("list a\n");
			// for (size_t i = 0; i < (*lists).a_len; i++)
			// 	printf("%d ", (*lists).a[i]);
			// printf("\nlist b\n");
			// for (size_t i = 0; i < (*lists).b_len; i++)
			// 	printf("%d ", (*lists).b[i]);
			// printf("\n---second separate finish---\n");
			is_separated = true;
		}
		separate_len = (*lists).b_len;
		*sorted_len += separate_len;
		remain_len -= ((*lists).b_len);
		// printf("---sort start---\n");
		sort_b_and_push_a(lists);
		if (is_sorted((*lists).a, (*lists).a_len))
			return ;
		// printf("sorted len == %zu\n", *sorted_len);
		// printf("list a\n");
		// for (size_t i = 0; i < (*lists).a_len; i++)
		// 	printf("%d ", (*lists).a[i]);
		// printf("\n---sort finish---\n");
		if (is_sorted((*lists).a, (*lists).a_len))
			return ;
		// printf("---rotate start---\n");
		rotate_list_a(*lists, separate_len);
		// printf("list a\n");
		// for (size_t i = 0; i < (*lists).a_len; i++)
		// 	printf("%d ", (*lists).a[i]);
		// printf("\n---rotate finish---\n");
		if (is_separated)
		{
			// printf("---push b from a start---\n");
			while (remain_len > 0)
			{
				command_pb(*lists, &(*lists).a_len, &(*lists).b_len);
				remain_len --;
			}
			// for (size_t i = 0; i < (*lists).a_len; i++)
			// 	printf("%d ", (*lists).a[i]);
			// printf("\nlist b\n");
			// for (size_t i = 0; i < (*lists).b_len; i++)
			// 	printf("%d ", (*lists).b[i]);
			// printf("\n---push b from a finish---\n");
		}
	}
	// printf("---rotate start---\n");
	rotate_list_a(*lists, bf_sorted_len);
	// printf("list a\n");
	// for (size_t i = 0; i < (*lists).a_len; i++)
	// 	printf("%d ", (*lists).a[i]);
	// printf("\n---rotate finish---\n");
}

void	do_quicksort(t_lists lists, size_t len)
{
	size_t	sorted_len;
	int		separater;

	sorted_len = 0;
	while (!is_sorted(lists.a, lists.a_len))
	// for (size_t i = 0; i < 2; i++)
	{
		separater = get_separater(lists.a, lists.a_len - sorted_len);
		// printf("---separate start---\nseparater == %d\n",separater);
		separate_list(&lists, separater, lists.a_len - sorted_len);
		// printf("list b\n");
		// for (size_t i = 0; i < lists.b_len; i++)
		// 	printf("%d ", lists.b[i]);
		// printf("\n---separate finish---\n");
		sort_lists(&lists, &sorted_len);
		// printf("list a\n");
		// for (size_t i = 0; i < len; i++)
		// 	printf("%d ", lists.a[i]);
		// printf("\n");
	}
}
