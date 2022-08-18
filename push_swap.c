#include "push_swap.h"

static void	list_check(char **list_origin)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (list_origin[i] != NULL)
	{
		j = 0;
		while (list_origin[i][j] != '\0')
		{
			c = list_origin[i][j];
			if (!(c >= '0' && c <= '9' || c == '+' || c == '-'))
				error_output(NULL);
			j++;
		}
		i++;
	}
}

static t_lists	atoi_list(char **list_origin, long long length)
{
	int			i;
	long long	tmp;
	t_lists		lists;

	lists.a = malloc((length + 1)* sizeof(int));
	if(lists.a)
		error_output(NULL);
	lists.b = malloc((length + 1)* sizeof(int));
	if(lists.b)
		error_output(NULL);
	i = 0;
	while(list_origin[i] != NULL)
	{
		tmp = ft_atoi(list_origin[i]);
		if(tmp > 2147483647 || tmp < -2147483648)
			error_output(&lists);
		lists.a[i] = tmp;
		i ++;
	}
	return lists;
}

void	push_swap(long long length, char **list_origin)
{
	t_lists lists;

	if(list_origin[0] == NULL)
		return ;
	list_check(list_origin);
	lists = atoi_list(list_origin, length);
	// swap(lists);
}
