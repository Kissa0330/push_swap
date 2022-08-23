#include "../push_swap.h"

void	command_rra(t_lists lists)
{
	rotate(-1, lists.a, lists.a_len);
	write(1, "rra\n", 4);
}

void	command_rrb(t_lists lists)
{
	rotate(-1, lists.b, lists.b_len);
	write(1, "rrb\n", 4);
}

void	command_rrr(t_lists lists)
{
	rotate(-1, lists.a, lists.a_len);
	rotate(-1, lists.b, lists.b_len);
	write(1, "rrr\n", 4);
}
