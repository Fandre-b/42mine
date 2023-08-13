#include <stdio.h>
#include <stdlib.h>

int
ft_ultimate_range(int **range, int min, int max)
{
    int i;
    int *res;

    if (min >= max)
    {
        res = NULL;
        return (0);
    }
    if(!(res = (int *)malloc(sizeof(int) * (max - min))))
        return (-1);
    i = 0;
    while (i < max - min)
    {
        res[i] = min + i;
        i++;
    }
    *range = res;
    return (res);
}

int main(void)
{
    int *array;
    int min = -10;
    int max = 20;
    int i;

    array = ft_range(min, max);
    i = 0;
    while (i < max - min)
        fprintf(stdout, "%d,", array[i++]);
    free (array);
    return (0);
}