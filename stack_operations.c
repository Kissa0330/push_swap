#include "push_swap.h"
#include <stdio.h>

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

int	*rotate(int mod, int *list, size_t length)
{
	int	i;
	int	tmp;

	if (mod == -1)
		i = length - 1;
	else if (mod == 1)
		i = 0;
	tmp = list[i];
	printf("i == %d  length == %zu\n", i, length);
	while (length >= i + 1 && i >= 0)
	{
		list[i] = list[i + mod];
		printf("list[i] == %d\n", list[i]);
		printf("i == %d\n", i);
		i += mod;
	}
	list[i - mod] = tmp;
	return (list);
}

int main(int argc, char const *argv[])
{
	int	i;
	int	list[5] = {1, 2, 3, 4, 5};
	int	*new_list;
	
	new_list = rotate(-1, list, 5);
	i = 0;
	while(i < 5)
	{
		printf("%d\n", new_list[i]);
		i ++;
	}
	return 0;
}
