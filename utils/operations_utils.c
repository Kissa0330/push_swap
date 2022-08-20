#include "../push_swap.h"

int	*swap(int *list)
{
	int	tmp;

	tmp = list[0];
	list[0] = list[1];
	list[1] = tmp;
	return (list);
}

int	*push(int *list1, int *list2, size_t length)
{
	size_t	i;

	i = length - 1;
	while (i > 0)
	{
		list1[i] = list1[i - 1];
		i--;
	}
	list1[0] = list2[0];
	i = 0;
	while (i < length - 1)
	{
		list2[i] = list2[i + 1];
		i++;
	}
	list2[i] = 0;
	return (list1);
}

int	*rotate(int mod, int *list, size_t length)
{
	size_t	i;
	int		tmp;

	if (mod == -1)
		i = length - 1;
	else if (mod == 1)
		i = 0;
	tmp = list[i];
	while (length >= i + 1 && i >= 0)
	{
		list[i] = list[i + mod];
		i += mod;
	}
	list[i - mod] = tmp;
	return (list);
}
