#include "push_swap.h"
#include <stdio.h>

void	command_sa(t_lists lists)
{
	swap(lists.a);
	write(1, "sa\n", 3);
}

void	command_sb(t_lists lists)
{
	swap(lists.b);
	write(1, "sb\n", 3);
}

void	command_ss(t_lists lists)
{
	swap(lists.a);
	swap(lists.b);
	write(1, "ss\n", 3);
}

int main(int argc, char const *argv[])
{
	t_lists lists;

	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {5, 4, 3, 2, 1};
	lists.a = a;
	lists.b = b;

	command_sa(lists);
	printf("lists.a\n");
	for (size_t i = 0; i < 5; i++)
		printf("%d ", lists.a[i]);
	printf("\nlists.b\n");
	for (size_t i = 0; i < 5; i++)
		printf("%d ", lists.b[i]);
	printf("\n");
	return 0;
}
