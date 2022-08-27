/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takanoraika <takanoraika@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:11:48 by takanoraika       #+#    #+#             */
/*   Updated: 2022/08/28 00:39:02 by takanoraika      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	list_check(char **list_origin)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (list_origin[i] != NULL)
	{
		j = 0;
		if (list_origin[i][0] == '+' || list_origin[i][0] == '-')
			j ++;
		if (j > 0 && list_origin[i][j] == '\0')
			error_output(NULL, NULL);
		while (list_origin[i][j] != '\0')
		{
			c = list_origin[i][j];
			if (!(c >= '0' && c <= '9'))
				error_output(NULL, NULL);
			j++;
		}
		i++;
	}
}

static t_lists	atoi_list(char **list_origin, size_t len)
{
	size_t		i;
	size_t		j;
	long long	tmp;
	t_lists		lists;

	lists.a = malloc((len) * sizeof(int));
	if (!lists.a)
		error_output(NULL, NULL);
	i = 0;
	while (list_origin[i] != NULL)
	{
		tmp = ft_atol(list_origin[i], lists);
		j = 0;
		while (j < i)
		{
			if (lists.a[j] == tmp)
				error_output(lists.a, NULL);
			j++;
		}
		lists.a[i] = tmp;
		i ++;
	}
	return (lists);
}

static void	do_sort(t_lists lists, size_t len)
{
	if (len == 1)
		return ;
	if (len == 2)
	{
		if (lists.a[0] > lists.a[1])
			command_sa(lists);
	}
	if (len == 3)
		three_sort(lists.a, lists);
	if (is_sorted(lists.a, len))
		return ;
	lists.b = malloc((len) * sizeof(int));
	if (!lists.b)
		error_output(lists.a, NULL);
	if (len <= 6)
		six_sort(lists);
	do_quicksort(lists, len);
}

void	push_swap(char **list_origin)
{
	t_lists	lists;
	size_t	len;

	if (list_origin == NULL || list_origin[0] == NULL)
		return ;
	list_check(list_origin);
	len = 0;
	while (list_origin[len] != NULL)
		len++;
	lists = atoi_list(list_origin, len);
	lists.a_len = len;
	lists.b_len = 0;
	lists.b = NULL;
	do_sort(lists, len);
	if (lists.a != NULL)
		free (lists.a);
	if (lists.b != NULL)
		free (lists.b);
}
