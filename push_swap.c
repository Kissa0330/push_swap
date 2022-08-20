#include "push_swap.h"

static void	list_check(char **list_origin)
{
	size_t	i;
	size_t	j;
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
	size_t		i;
	long long	tmp;
	t_lists		lists;

	lists.a = malloc((length + 1) * sizeof(int));
	if (!lists.a)
		error_output(NULL, NULL);
	lists.b = malloc((length + 1) * sizeof(int));
	if (!lists.b)
		error_output(lists.a, NULL);
	i = 0;
	while (list_origin[i] != NULL)
	{
		tmp = ft_atoi(list_origin[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_output(lists.a, lists.b);
		lists.a[i] = tmp;
		i ++;
	}
	return (lists);
}

static int	*do_swap(t_lists lists, size_t length)
{
	int	separater;

	if (length == 1)
		return (lists.a);
	if (length == 2)
	{
		if(lists.a[0] > lists.a[1])
			command_sa(lists);
		return (lists.a);;
	}
	if (length == 3)
		return (three_sort(lists));
	separater = lists.a[0];
	separate_list(lists, separater);
	do_quicksort(lists, length);
	return (lists.a);
}

int	*push_swap(char **list_origin)
{
	t_lists	lists;
	size_t	length;

	if (list_origin == NULL)
		return (NULL);
	list_check(list_origin);
	length = 0;
	while (list_origin[length] != NULL)
		length++;
	lists = atoi_list(list_origin, length);
	return (do_swap(lists, length));
}
