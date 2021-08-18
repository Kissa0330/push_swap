#include <stdio.h>
int ft_iterative_power(int nb, int power);

int main(void)
{
	int nb;
	int power;

	nb = 2;
	power = 21;
	printf("%d", ft_iterative_power(nb, power));
	return (0);
}
