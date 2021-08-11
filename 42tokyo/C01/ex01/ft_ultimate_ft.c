int	********g_nbr0;
int	*******g_nbr1;
int	******g_nbr2;
int	*****g_nbr3;
int	****g_nbr4;
int	***g_nbr5;
int	**g_nbr6;
int	*g_nbr7;
int	g_data;

void	ft_ultimate_ft(int *********nbr)
{
	g_data = 42;
	g_nbr7 = &g_data;
	g_nbr6 = &g_nbr7;
	g_nbr5 = &g_nbr6;
	g_nbr4 = &g_nbr5;
	g_nbr3 = &g_nbr4;
	g_nbr2 = &g_nbr3;
	g_nbr1 = &g_nbr2;
	g_nbr0 = &g_nbr1;
	*nbr = g_nbr0;
}
