#include "../push_swap.h"
#include <stdio.h>

int	*three_sort(t_lists lists, size_t len)
{
	int *a;

	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		command_sa(lists);
	if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		command_rra(lists, len);
	if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		command_ra(lists, len);
	if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
	{
		command_sa(lists);
		command_rra(lists, len);
	}
	if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		command_rra(lists, len);
		command_sa(lists);
	}
	return (a);
}

void	separate_list(t_lists lists, int separater, size_t len)
{
	size_t	i;

	i = 0;
	while (len - 1 > i)
	{
		if (lists.a[0] >= separater)
			command_pb(lists, len);
		else
			command_ra(lists, len);
		printf("lists A \n");
		for (size_t i = 0; i < len; i++)
		{
			printf("%d ", lists.a[i]);
		}
		printf("\nlists B \n");
		for (size_t i = 0; i < len; i++)
		{
			printf("%d ", lists.b[i]);
		}
		printf("\n\n");
		i ++;
	}
}

void do_quicksort(t_lists lists, size_t len)
{

}
