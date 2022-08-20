#include "../push_swap.h"

void	separate_list(t_lists lists, int separater, size_t length)
{
	size_t	i;

	i = 0;
	while (length > i)
	{
		if(lists.a[0] >= separater)
			command_pa(lists, length);
		else
			command_ra(lists, length);
		i ++;
	}
}

int	*three_sort(t_lists *lists)
{

}