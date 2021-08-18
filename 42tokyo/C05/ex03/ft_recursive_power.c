int	g_result;
int	ft_recursive_power(int nb, int power)
{
	if (g_result == 0)
		g_result = 1;
	if (nb < 0 || power < 0)
		return (0);
	else if (nb == 0)
		return (1);
	if (power == 0)
		return (1);
	if (power == 1)
	{
		g_result = g_result * nb;
		return (g_result);
	}
	g_result = g_result * nb;
	power--;
	return (ft_recursive_power(nb, power));
}
