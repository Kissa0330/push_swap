#include "../push_swap.h"

void	command_ra(t_lists lists, size_t length)
{
	rotate(1, lists.a, length);
	write(1, "ra\n", 3);
}

void	command_rb(t_lists lists, size_t length)
{
	rotate(1, lists.b, length);
	write(1, "rb\n", 3);
}

void	command_rr(t_lists lists, size_t length)
{
	rotate(1, lists.a, length);
	rotate(1, lists.b, length);
	write(1, "rr\n", 3);
}
