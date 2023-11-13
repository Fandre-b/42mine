/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:12:49 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/12 21:44:39 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int ft_get_precision(char *str_flags)
{
    int len;
    int res;

    len = ft_strlen(str_flags);
    res = -1;
    while (len >= 0 && str_flags[len] != '.')
        len--;
    if (str_flags[len] == '.')
    {
        res = 0;
        while(str_flags[++len] && ft_isdigit(str_flags[len]))
            res = (res * 10 + (str_flags[len] - '0'));
    }
    return (res);
}

int main()
{
    char *str = ".82382398-420+0#-00";

    printf("%d\n", ft_get_precision(str));
}
