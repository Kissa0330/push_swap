/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:10:57 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/24 18:10:58 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	command_ra(t_lists lists)
{
	rotate(1, lists.a, lists.a_len);
	write(1, "ra\n", 3);
}

void	command_rb(t_lists lists)
{
	rotate(1, lists.b, lists.b_len);
	write(1, "rb\n", 3);
}

void	command_rr(t_lists lists)
{
	rotate(1, lists.a, lists.a_len);
	rotate(1, lists.b, lists.b_len);
	write(1, "rr\n", 3);
}
