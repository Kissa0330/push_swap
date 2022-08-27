/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:11 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/28 00:39:22 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	ft_atol(const char *str, t_lists lists)
{
	int				negativeflag;
	long long		num;

	num = 0;
	negativeflag = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negativeflag = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > 2147483647 || num < -2147483648)
			error_output(lists.a, NULL);
		str ++;
	}
	return (num * negativeflag);
}

void	error_output(void *stack1, void *stack2)
{
	if (stack1 != NULL)
		free(stack1);
	if (stack2 != NULL)
		free(stack2);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
