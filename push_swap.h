#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_lists
{
	int	*a;
	int	*b;
}	t_lists;

int			*push_swap(char **list_origin);
long long	ft_atoi(const char *str);
void		error_output(void *stack1, void *stack2);
void		ft_bzero(void *s, size_t n);
int			*swap(int *list);
int			*push(int *list1, int *list2);
int			*rotate(int mod, int *list, size_t length);
void		command_sa(t_lists lists);
void		command_sb(t_lists lists);
void		command_ss(t_lists lists);
void		command_pa(t_lists lists);
void		command_pb(t_lists lists);
void		command_ra(t_lists lists, size_t length);
void		command_rb(t_lists lists, size_t length);
void		command_rr(t_lists lists, size_t length);
void		command_rra(t_lists lists, size_t length);
void		command_rrb(t_lists lists, size_t length);
void		command_rrr(t_lists lists, size_t length);
#endif