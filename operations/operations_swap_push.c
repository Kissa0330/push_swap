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

void	command_pa(t_lists lists, size_t *a_len, size_t *b_len)
{
	if (lists.b_len > 0)
	{
		push(lists.a, lists.b, lists.a_len, lists.b_len);
		*a_len += 1;
		*b_len -= 1;
	}
	write(1, "pa\n", 3);
}

void	command_pb(t_lists lists, size_t *a_len, size_t *b_len)
{
	if (lists.a_len > 0)
	{
		push(lists.b, lists.a, lists.b_len, lists.a_len);
		*a_len -= 1;
		*b_len += 1;
	}
	write(1, "pb\n", 3);
}
