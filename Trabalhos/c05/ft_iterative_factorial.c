#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int fact;

    fact = 1;
    while (nb > 0)
        fact *= nb--;
    return (fact);
}

int main(void)
{
    int nbr;

    nbr = 1;
    printf("resultado: %d\n", ft_iterative_factorial(nbr));
}