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

static t_lists	atoi_list(char **list_origin, size_t len)
{
	size_t		i;
	size_t		j;
	long long	tmp;
	t_lists		lists;

	lists.a = malloc((len) * sizeof(int));
	if (!lists.a)
		error_output(NULL, NULL);
	i = 0;
	while (list_origin[i] != NULL)
	{
		tmp = ft_atol(list_origin[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_output(lists.a, NULL);
		j = 0;
		while (j < i)
		{
			if (lists.a[j] == tmp)
				error_output(lists.a, NULL);
			j++;
		}
		lists.a[i] = tmp;
		i ++;
	}
	return (lists);
}

static int	*do_sort(t_lists lists, size_t len)
{
	if (len == 1)
		return (lists.a);
	if (len == 2)
	{
		if(lists.a[0] > lists.a[1])
			command_sa(lists);
		return (lists.a);
	}
	if (len == 3)
		return (three_sort(lists.a, lists));
	if (len <= 6)
		return (six_sort(lists, len));
	if (is_sorted(lists.a, len))
		return (lists.a);
	lists.b = malloc((len) * sizeof(int));
	if (!lists.b)
		error_output(lists.a, NULL);
	do_quicksort(lists, len);
	return (lists.a);
}

int	*push_swap(char **list_origin)
{
	t_lists	lists;
	size_t	len;
	int		*res;

	if (list_origin == NULL || list_origin[0] == NULL)
		return (NULL);
	list_check(list_origin);
	len = 0;
	while (list_origin[len] != NULL)
		len++;
	lists = atoi_list(list_origin, len);
	lists.a_len = len;
	lists.b_len = 0;
	res = do_sort(lists, len);
	free (lists.a);
	free (lists.b);
	return (res);
}
