#include <stdio.h>
int ft_recursive_power(int nb, int power);

int main(void)
{
	int nb;
	int power;

	nb = 13;
	power = 2;
	printf("%d", ft_recursive_power(nb, power));
	return (0);
}
