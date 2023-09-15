#include <stdio.h>

int ft_recursive_power(int nb, int power)
{
    int res;

    res = nb;
    if (power < 0)
        return (0);
    else if (power == 0)
        return (1);
    else
        return (res * ft_recursive_power(nb ,power - 1));
}

int main(void)
{
  int nbr;

  nbr = 4;
  printf("resultado: %d\n", ft_recursive_power(nbr, -10));
}