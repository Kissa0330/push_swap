#include "push_swap.h"

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

void	command_pa(t_lists lists)
{
	push(lists.a, lists.b);
	write(1, "pa\n", 3);
}

void	command_pb(t_lists lists)
{
	push(lists.b, lists.a);
	write(1, "pb\n", 3);
}
