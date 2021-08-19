int	ft_recursive_power(int nb, int power)
{
	if (power == 1)
		return (nb * 1);
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}
