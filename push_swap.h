/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:56 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/26 01:21:43 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_lists
{
	int		*a;
	int		*b;
	size_t	a_len;
	size_t	b_len;
}	t_lists;

void		push_swap(char **list_origin);
long long	ft_atol(const char *str);
void		error_output(void *stack1, void *stack2);
int			*swap(int *list);
int			*push(int *list1, int *list2, size_t len_1, size_t len_2);
int			*rotate(int mod, int *list, size_t len);
void		command_sa(t_lists lists);
void		command_sb(t_lists lists);
void		command_ss(t_lists lists);
void		command_pa(t_lists lists, size_t *a_len, size_t *b_len);
void		command_pb(t_lists lists, size_t *a_len, size_t *b_len);
void		command_ra(t_lists lists);
void		command_rb(t_lists lists);
void		command_rr(t_lists lists);
void		command_rra(t_lists lists);
void		command_rrb(t_lists lists);
void		command_rrr(t_lists lists);
bool		is_sorted(int *list, size_t len);
void		separate_list(t_lists *lists, int separater, size_t len);
int			get_max(int	*list, size_t len);
int			get_min(int	*list, size_t len);
int			get_lentomax(int *list, size_t len);
int			get_separater(int *a, size_t separate_len);
void		separate_list_b(t_lists *lists, int separater);
void		rotate_list_a(t_lists lists, size_t sorted_len);
void		do_pb(t_lists *lists, size_t remain_len);
int			*three_sort(int *a, t_lists lists);
int			*six_sort(t_lists lists);
void		do_quicksort(t_lists lists, size_t len);
#endif