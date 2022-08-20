#include "../push_swap.h"

void	command_rra(t_lists lists, size_t len)
{
	rotate(-1, lists.a, len);
	write(1, "rra\n", 4);
}

void	command_rrb(t_lists lists, size_t len)
{
	rotate(-1, lists.b, len);
	write(1, "rrb\n", 4);
}

void	command_rrr(t_lists lists, size_t len)
{
	rotate(-1, lists.a, len);
	rotate(-1, lists.b, len);
	write(1, "rrr\n", 4);
}
