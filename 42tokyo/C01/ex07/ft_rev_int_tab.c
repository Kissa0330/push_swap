void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	while (i <= size / 2)
	{
		if (i == size / 2)
		{
			a = *(tab + size - i - 1);
			b = *(tab + i);
			*(tab + size - i - 1) = a;
			*(tab + i) = b;
		}
		else
		{
			a = *(tab + size - i - 1);
			b = *(tab + i);
			*(tab + size - i - 1) = b;
			*(tab + i) = a;
		}
		i++;
	}
}
