#include <stdio.h>

int ft_recursive_factorial(int nbr)
{
  if (nbr == 1)
    return (1);
  else
    return (nbr * ft_recursive_factorial(--nbr));
}

int main(void)
{
  int nbr;

  nbr = 4;
  printf("resultado: %d\n", ft_recursive_factorial(nbr));
}