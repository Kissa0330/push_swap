void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	i;
	int	j;

	i = a / b;
	j = a % b;
	*div = i;
	*mod = j;
}
