#include "push_swap.h"

int *swap(int *list)
{
	int	tmp;

	list[0] = tmp;
	list[0] = list[1];
	list[1] = tmp;
	return (list);
}

int	*push(int *list1, int *list2)
{
	list1[0] = list2[0];
	return (list1);
}

int	*rotate(int mod, int *list, int length)
{
	int i;
	int tmp;

	if (!mod)
		i = length - 1;
	else if (mod)
		i = 0;
	tmp = list[i];
	while (length > i || i > 0)
	{
		list[i] = list[i + mod];
		i + mod;
	}
	list[i] = tmp;
	return (list);
}