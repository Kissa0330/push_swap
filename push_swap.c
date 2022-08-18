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
		if (list_origin[i][0] == '+' || list_origin[i][0] == '-')
			j ++;
		while (list_origin[i][j] != '\0')
		{
			c = list_origin[i][j];
			if (!(c >= '0' && c <= '9'))
				error_output(NULL, NULL);
			j++;
		}
		i++;
	}
}

static t_lists	atoi_list(char **list_origin, size_t length)
{
	int			i;
	long long	tmp;
	t_lists		lists;

	lists.a = malloc((length + 1)* sizeof(int));
	if(!lists.a)
		error_output(NULL, NULL);
	lists.b = malloc((length + 1)* sizeof(int));
	if(!lists.b)
		error_output(lists.a, NULL);
	ft_bzero(lists.b, length);
	i = 0;
	while(list_origin[i] != NULL)
	{
		tmp = ft_atoi(list_origin[i]);
		if(tmp > 2147483647 || tmp < -2147483648)
			error_output(lists.a, lists.b);
		lists.a[i] = tmp;
		i ++;
	}
	return (lists);
}

static void	*swap(t_lists lists)
{
	return NULL;
}

int	*push_swap(size_t length, char **list_origin)
{
	t_lists lists;

	if(list_origin[0] == NULL)
		return (NULL);
	list_check(list_origin);
	lists = atoi_list(list_origin, length);
	swap(lists);
	return (lists.a);
}
