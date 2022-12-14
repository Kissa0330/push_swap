/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:08 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/24 18:11:09 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*swap(int *list)
{
	int	tmp;

	tmp = list[0];
	list[0] = list[1];
	list[1] = tmp;
	return (list);
}

int	*push(int *list1, int *list2, size_t len_1, size_t len_2)
{
	size_t	i;

	i = len_1;
	while (i > 0)
	{
		list1[i] = list1[i - 1];
		i--;
	}
	list1[0] = list2[0];
	i = 0;
	while (i < len_2 - 1)
	{
		list2[i] = list2[i + 1];
		i++;
	}
	list2[i] = 0;
	return (list1);
}

int	init_i(int mod, size_t len)
{
	if (mod == -1)
		return (len - 1);
	return (0);
}

int	*rotate(int mod, int *list, size_t len)
{
	size_t	i;
	int		tmp;

	i = init_i(mod, len);
	tmp = list[i];
	while (len - 1 >= i && i >= 0)
	{
		list[i] = list[i + mod];
		if ((mod == -1 && i == 0) || (mod == 1 && i == len - 1))
			break ;
		i += mod;
	}
	list[i] = tmp;
	return (list);
}
