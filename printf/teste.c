#include <stdio.h>
#include "ft_printf.h"

t_flags *ft_flag_intialize(void)
{
    t_flags *flags;

    flags = (t_flags *)malloc(sizeof(t_flags));
    if (!flags)
        return (NULL);
    flags->width = 0;
    flags->plus = 0;
    flags->space = 0;
    flags->hash = 0;
    flags->precision = 0;
    flags->zero = 0;
    flags->left = 0;
    return (flags);
}


t_flags *ft_process_flags(char *str_flags, char *accepted_flags)
{
	t_flags	*flags;
    int i;

    flags = ft_flag_intialize;
    i = 0;
    flags->precision = ft_get_precision(str_flags);
    flags->width = ft_get_width(str_flags);
    while(str_flags[i]) 
    {
        if (strrchr(accepted_flags, str_flags[i]))
        {
            if (str_flags[i] == '0' && !ft_isdigit(str_flags[i - 1]))
                flags->zero = 1;
            else if (str_flags[i] == '-')
                flags->left = 1;
            else if (str_flags[i] == ' ' && !strchr(str_flags, '+'))
                flags->space = 1;
            else if (str_flags[i] == '+')
                flags->plus = 1;
            else (str_flags[i] == '#');
                flags->hash = 1;    
        }
        i++;
    }
    printf("rodou criar flags stroc\n");
    return (flags);
}

int main()
{
    char *str = "0-+ 1234567890";
    char *accepted_flags = "-0. +";
    t_flags *flags;

    flags = ft_process_flags(str, accepted_flags);
    printf("width: %d\n", flags->width);
    printf("plus: %d\n", flags->plus);
    printf("space: %d\n", flags->space);
    printf("hash: %d\n", flags->hash);
    printf("precision: %d\n", flags->precision);
    printf("zero: %d\n", flags->zero);
    printf("left: %d\n", flags->left);
    return (0);
}