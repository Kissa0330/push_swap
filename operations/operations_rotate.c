#include "../push_swap.h"

void	command_ra(t_lists lists, size_t len)
{
	rotate(1, lists.a, len);
	write(1, "ra\n", 3);
}

void	command_rb(t_lists lists, size_t len)
{
	rotate(1, lists.b, len);
	write(1, "rb\n", 3);
}

void	command_rr(t_lists lists, size_t len)
{
	rotate(1, lists.a, len);
	rotate(1, lists.b, len);
	write(1, "rr\n", 3);
}
