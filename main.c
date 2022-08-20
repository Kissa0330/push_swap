#include "push_swap.h"

int	main(int argc, char const *argv[])
{
	push_swap((char **)&argv[1]);
	push_swap(NULL);
	return (0);
}

/*
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