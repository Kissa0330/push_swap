int	g_a;
int	g_b;
int	g_count;
int	g_same_count;
int	g_size;

void	swap(int *a, int *b)
{
	g_a = *a;
	g_b = *b;
	*a = g_b;
	*b = g_a;
}

void	judge(int *tab, int i)
{
	int	j;

	j = 0;
	g_count = g_size - 1;
	g_same_count = -1;
	while (j < g_size)
	{
		if (*(tab + i) < *(tab + j))
		{
			g_count--;
		}
		else if (*(tab + i) == *(tab + j))
		{
			g_same_count++;
		}
		j++;
	}
}

void	sort_num(int *tab)
{
	int	i;

	i = 0;
	while (i < g_size)
	{
		judge(tab, i);
		while (g_same_count > 0)
		{
			if (*(tab + g_count - g_same_count) != *(tab + i))
			{
				swap((tab + g_count - g_same_count), (tab + i));
			}
			g_same_count--;
		}
		swap((tab + g_count), (tab + i));
		i++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	g_size = size;
	sort_num(tab);
	sort_num(tab);
}
