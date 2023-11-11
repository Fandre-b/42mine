#include <stdio.h>
#include <stdlib.h>

int len_str_matrix(int size, char **strs, char *sep)
{
    int i;
    while(i < size)
    {
        len += ft_strlen(strs[i++]);
    }
    len += ft_strlen(sep)*size-2+1
}
//Adicionar ft_cat e reutilizar em ft catma
char    *ft_cat_str(int size, char **strs, char *sep)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < size)
    {    k = 0
        while(strs[i][j] != '\0')
        {
            dest[j] = strs[i][k];
            if ((i > 0 || i < size) && strs[i][j + 1] == '\0')
            { 
                k = 0;
                while(sep[k] =! '\0')
                {   
                    dest[j] = strs[i][k];
                    j++;
                }
            }
            j++;
        }
    }
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    char    *dest;

    len = len_str_matrix(size, strs, sep);
    if(!(dest = ((char *)malloc(sizeof(char) * len))))
        return (NULL);
    dest = ft_cat_str(size, strs, sep);
    printf("%s\n", dest);
    free(dest);
}
