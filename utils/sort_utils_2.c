/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:33:35 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/26 01:21:18 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*comp_array(int *org, int *copy, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ranking;

	i = 0;
	while (i < len)
	{
		ranking = 1;
		j = 0;
		while (j < len)
		{
			if (org[i] > org[j])
				ranking ++;
			j ++;
		}
		copy[i] = ranking;
		i ++;
	}
	return (copy);
}

int	get_separater(int *a, size_t separate_len)
{
	size_t	i;
	int		*copy;
	int		sep;

	sep = a[0];
	i = 0;
	copy = malloc(separate_len * sizeof(int));
	while (i < separate_len)
	{
		copy[i] = a[i];
		i ++;
	}
	comp_array(a, copy, separate_len);
	i = 0;
	while (i < separate_len)
	{
		if (separate_len / 2 == copy[i])
			sep = a[i];
		i ++;
	}
	free(copy);
	return (sep);
}

void	separate_list_b(t_lists *lists, int sep)
{
	int	*b;

	b = (*lists).b;
	while ((*lists).b_len > 0 && sep < get_max(b, (*lists).b_len))
	{
		if ((*lists).b[0] >= sep)
			command_pa(*lists, &(*lists).a_len, &(*lists).b_len);
		while (!(b[0] >= sep) && sep < get_max(b, (*lists).b_len))
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

void	do_pb(t_lists *lists, size_t remain_len)
{
	while (remain_len > 0)
	{
		command_pb(*lists, &(*lists).a_len, &(*lists).b_len);
		remain_len --;
	}
}
