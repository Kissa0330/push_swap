/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:16 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/24 18:18:49 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_median(int a, int b, int c)
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
