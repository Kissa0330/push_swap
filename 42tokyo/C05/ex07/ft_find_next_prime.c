int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
		{
			return (ft_find_next_prime(nb + 1));
		}
		i++;
	}
	return (nb);
}
