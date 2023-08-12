#include <stdio.h>

char    *ft_spaces(char *str)
{
    while ((*str > 8 && *str < 14) || *str == 32)
        str++;
    return (str);
}

int ft_sign(char *str, int index)
{
    int count;

    count = 1;
    while ((str[index - 1] == 43 || str[index - 1] == 45) && index >= 0)
    {
        if(str[index] == 45)
            count++;
        index--;
    }
    return ((-1) * count);
}

int ft_atoi(char *str)
{
    int    sign;
    int number;
    int i;

    ft_spaces(str);
    i = 0;
    while (str[i++] != '\0')
    {
        if (str[i] > 47 && str[i] < 58)
        {
            sign = ft_sign(str, i);
            number = 0;
            while (str[i++] > 47 && str[i] < 58)
            {
                number = (number * 10) + (str[i] - 48);
            }
            return (sign * number);
        }
    }
    return (0);
}

int main (void)
{
    char *str =  " ---+----2147483ab567";
    printf("é iss: %d\n", ft_atoi(str));
}