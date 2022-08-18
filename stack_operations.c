#include "push_swap.h"

int *swap(int *list)
{
	int tmp;

	list[0] = tmp;
	list[0] = list[1];
	list[1] = tmp;
	return (list);
}



int	*rotate(int mod, t_lists lists, int length)
{
	int i;

	if (!mod)
		i = length;
	else if (mod)
		i = 0;
	while (length >= i || i >= 0)
	{
		/* code */
	}
}