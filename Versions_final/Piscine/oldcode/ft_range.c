#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int N;
    int i;
    int *range;

    if (min >= max)
        return (NULL);
    N = max - min;
    if(!(range = (int *)malloc(sizeof(int) * (N))))
        return (NULL);
    i = 0;
    while (i < N)
    {
        range[i] = min + i;
        i++;
    }
    return (range);
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