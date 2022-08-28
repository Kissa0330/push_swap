/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:33:30 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/29 00:59:09 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	juduge_min(t_lists *lists, int min, int sep, size_t *min_count)
{
	command_pb(*lists, &(*lists).a_len, &(*lists).b_len);
	if (min == get_min((*lists).b, (*lists).b_len) && min == (*lists).b[0])
	{
		if ((*lists).a[0] > sep)
			command_rr(*lists);
		else
			command_rb(*lists);
			min_count ++;
	}
}

void	push_min_to_a(t_lists *lists, size_t min_count)
{
	size_t	i;

	i = 0;
	while (min_count > i)
	{
		command_rrb(*lists);
		command_pa(*lists, &(*lists).a_len, &(*lists).b_len);
		i ++ ;
	}
	rotate_list_a(*lists, min_count);
}

void	separate_list(t_lists *lists, int sep, size_t len, size_t *srt_len)
{
	size_t	i;
	size_t	min_count;
	int		min;

	i = 0;
	min_count = 0;
	while (len > i && sep >= get_min((*lists).a, (*lists).a_len))
	{
		min = get_min((*lists).a, len);
		if ((*lists).a[0] <= sep)
		{
			juduge_min(lists, min, sep, &min_count);
			if (sep < get_min((*lists).a, (*lists).a_len))
				break ;
		}
		else
			command_ra(*lists);
		i ++;
	}
	*srt_len += min_count;
	push_min_to_a(lists, min_count);
}

int	get_max(int *list, size_t len)
{
	int		max;
	size_t	i;

	max = list[0];
	i = 1;
	while (i < len)
	{
		if (max < list[i])
			max = list[i];
		i ++;
	}
	return (max);
}

int	get_min(int *list, size_t len)
{
	int		min;
	size_t	i;

	min = list[0];
	i = 1;
	while (i < len)
	{
		if (min > list[i])
			min = list[i];
		i ++;
	}
	return (min);
}
