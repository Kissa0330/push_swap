#include "../push_swap.h"

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

void	command_pa(t_lists lists, size_t len, size_t *a_len, size_t *b_len)
{
	if (lists.b_len > 0)
	{
		push(lists.a, lists.b, len);
		lists.a_len ++;
		lists.b_len --;
	}
	write(1, "pa\n", 3);
}

void	command_pb(t_lists lists, size_t len, size_t *a_len, size_t *b_len)
{
	if (lists.a_len > 0)
	{
		push(lists.b, lists.a,len);
		*a_len -= 1;
		*b_len += 1;
	}
	write(1, "pb\n", 3);
}

#include <stdio.h>
int main(int argc, char const *argv[])
{
	t_lists lists;

	int a[5] = {1, 2, 3, 4, 5};
	int b[5] = {0, 0, 0, 0, 0};
	lists.a = a;
	lists.b = b;
	lists.a_len = 5;
	lists.b_len = 0;

	command_pb(lists, 5, &lists.a_len, &lists.b_len);
	printf("lists.a\n");
	for (size_t i = 0; i < 5; i++)
		printf("%d ", lists.a[i]);
	printf("\nlists.b\n");
	for (size_t i = 0; i < 5; i++)
		printf("%d ", lists.b[i]);
	printf("\n");
	printf("%zu ", lists.a_len);
	printf("%zu \n", lists.b_len);
	return 0;
}
