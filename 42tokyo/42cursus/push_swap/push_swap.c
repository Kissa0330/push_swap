#include "push_swap.h"

int push_swap(char *list_origin[])
{
	t_lists lists;

	if(list_origin[0] == NULL)
		return (0);
	if(list_check(list_origin))
		write("Error\n");
	atoi_list(list_origin, &lists);
	swap(lists);
}