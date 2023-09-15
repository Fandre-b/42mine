#include <stdio.h>

int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    else if (index == 0)
        return (0);
    else if (index == 1)
        return (1);
    else if (index > 0)
        return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));

}

int main(void)
{
  int nbr;

  nbr = 4;
  printf("resultado: %d\n", ft_fibonacci(2));
}