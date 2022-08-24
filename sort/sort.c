/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:10:42 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/25 02:24:51 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	sort_lists(t_lists *lists, int separater, size_t *sorted_len)
{
	size_t	len;
	bool	is_separated;

	separater = 0;
	len = (*lists).b_len;
	is_separated = false;
	// if ((*lists).b_len > 10)
	// {
	// 	separate_list_b(lists, separater);
	// 	is_separated = true;
	// }
	len -= ((*lists).b_len);
	sort_b_and_push_a(lists);
	if (is_sorted((*lists).a, (*lists).a_len))
		return ;
	rotate_list_a(*lists, *sorted_len);
	// if (is_separated)
	// {
	// 	while (len > 0)
	// 	{
	// 		command_pa(*lists, &(*lists).a_len, &(*lists).b_len);
	// 		len --;
	// 	}
	// 	sort_b_and_push_a(lists);
	// 	if (is_sorted((*lists).a, (*lists).a_len))
	// 		return ;
	// 	rotate_list_a(*lists, *sorted_len);
	// }
}

void	do_quicksort(t_lists lists, size_t len)
{
	size_t	sorted_len;
	int		separater;

	sorted_len = 0;
	while (!is_sorted(lists.a, lists.a_len))
	{
		separater = get_separater(lists.a, lists.a_len - sorted_len);
		if (sorted_len >= len / 2)
			separater = get_min(lists.a, lists.a_len - sorted_len);
		separate_list(&lists, separater, lists.a_len - sorted_len);
		sorted_len += lists.b_len;
		sort_lists(&lists, separater, &sorted_len);
	}
}
