#include <stdio.h>
int ft_is_prime(int nb);

int main(void)
{
	int nb;

	nb = 97;
	printf("%d ==> %d\n", nb, ft_is_prime(nb));
	return (0);
}
