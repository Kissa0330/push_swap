/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:33:35 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/25 01:19:14 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_med(int a, int b, int c)
{
	if (a < b && a < c)
	{
		if (b < c)
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

int	get_separater(int *a, size_t separate_len)
{
	size_t	div_len;
	int		m1;
	int		m2;
	int		m3;

	div_len = separate_len / 3;
	m1 = get_med(a[0], a[div_len / 2], a[div_len - 1]);
	m2 = get_med(a[div_len], a[div_len - div_len / 2], a[div_len * 2 - 1]);
	m3 = get_med(a[div_len * 2], a[div_len - div_len / 2], a[separate_len - 1]);
	return (get_med(m1, m2, m3));
}

void	separate_list_b(t_lists *lists, int separater)
{
	int	sep_avg;

	sep_avg = (get_max((*lists).b, (*lists).b_len) + separater) / 2;
	while ((*lists).b_len >= 0 && sep_avg <= get_max((*lists).b, (*lists).b_len))
	{
		if ((*lists).b[0] > sep_avg)
			command_pb(*lists, &(*lists).a_len, &(*lists).b_len);
		while (!((*lists).b[0] >= sep_avg))
				command_rb(*lists);
	}
}

void	rotate_list_a(t_lists lists, size_t sorted_len)
{
	size_t	i;

	i = lists.a_len - sorted_len;
	if (sorted_len <= lists.a_len / 2)
		i = sorted_len;
	while (i > 0)
	{
		if (sorted_len >= lists.a_len / 2)
			command_rra(lists);
		else
			command_ra(lists);
		i --;
	}
}
