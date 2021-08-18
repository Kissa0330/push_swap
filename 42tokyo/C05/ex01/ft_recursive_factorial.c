#include <stdio.h>
int	g_result;

int	ft_recursive_factorial(int nb)
{
	if (g_result == 0)
	{
		g_result = 1;
	}
	if (nb <= 1)
	{
		return (g_result);
	}
	g_result = g_result * nb;
	nb = nb - 1;
	return (ft_recursive_factorial(nb));
}
