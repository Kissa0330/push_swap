#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	int	*new_list;
	// push_swap((char **)&argv[1]);
	new_list = push_swap((char **)&argv[1]);
	// for (size_t i = 0; i < argc - (size_t)1; i++)
	// 	printf("%d ", new_list[i]);
	// printf("\n");
	return (argc);
}

/*
#include <stdio.h>
int main(int argc, char const *argv[])
{
	t_lists lists;

	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {5, 4, 3, 2, 1};
	lists.a = a;
	lists.b = b;

	command_rr(lists, 5);
	printf("lists.a\n");
	for (size_t i = 0; i < 5; i++)
		printf("%d ", lists.a[i]);
	printf("\nlists.b\n");
	for (size_t i = 0; i < 5; i++)
		printf("%d ", lists.b[i]);
	printf("\n");
	return 0;
}
*/