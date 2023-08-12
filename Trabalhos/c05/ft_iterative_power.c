#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int res;

    res = 1;
    if (power < 0)
      return (0);
    if (power == 0)
      return (1);
    while (power > 0)
    {
      res *= nb;
      power--;
    }
    return (res);
}

int main(void)
{
  int nbr;

  nbr = 4;
  printf("resultado: %d\n", ft_iterative_power(nbr, 3));
}