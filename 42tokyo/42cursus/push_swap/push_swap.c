#include "push_swap.h"

void	list_check(char **list_origin)
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
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	atoi_list(char **list_origin, t_lists *lists)
{

}

int push_swap(char **list_origin)
{
	t_lists lists;

	if(list_origin[0] == NULL)
		return (0);
	list_check(list_origin);
	atoi_list(list_origin, &lists);
	swap(lists);
}
