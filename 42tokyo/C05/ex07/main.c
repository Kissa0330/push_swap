#include <stdio.h>
int ft_find_next_prime(int nb);

int main(void)
{
	int nb;

	nb = 102;
	printf("%d ==> %d\n", nb, ft_find_next_prime(nb));
	return (0);
}