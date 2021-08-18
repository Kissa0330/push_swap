int	ft_is_prime(int nb)
{
	int	i;
	int	cnt;

	cnt = 0;
	if (nb <= 1)
	{
		return (0);
	}
	i = 1;
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			cnt++;
		}
		i++;
	}
	if (cnt == 2)
	{
		return (1);
	}
	return (0);
}
