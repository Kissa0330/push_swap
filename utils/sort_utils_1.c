/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:33:30 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/25 00:38:23 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	separate_list(t_lists *lists, int separater, size_t len)
{
	size_t	i;
	int		sep_avg;

	i = 0;
	sep_avg = (get_max((*lists).a, len) + separater) / 2;
	while (len > i && separater <= get_max((*lists).a, (*lists).a_len))
	{
		if ((*lists).a[0] >= separater)
			command_pb(*lists, &(*lists).a_len, &(*lists).b_len);
		else
			command_ra(*lists);
		if (sep_avg > (*lists).b[0])
			command_rb(*lists);
		i ++;
	}
}

bool	is_sorted(int *list, size_t len)
{
	size_t	i;

	if (len <= 0)
		return (false);
	i = 1;
	while (i < len)
	{
		if (!(list[i - 1] <= list[i]))
			return (false);
		i ++;
	}
	return (true);
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

int	get_lentomax(int *list, size_t len)
{
	int		max;
	size_t	i;

	max = get_max(list, len);
	i = 0;
	while (list[i] != max)
		i ++;
	return (i);
}
