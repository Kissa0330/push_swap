int	ft_find_next_prime(int nb)
{
	int	i;
	int	cnt;

	cnt = 0;
	if (nb <= 1)
		return (2);
	i = 1;
	while (i <= nb)
	{
		if (nb % i == 0)
			cnt++;
		i++;
	}
	if (cnt == 2)
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
