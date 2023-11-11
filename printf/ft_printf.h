/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:15:07 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/11 11:17:43 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

/*
typedef struct s_flags
{
    int plus;
    int hash;
    int zero;
    int side;
    int width;
    int precision;
}   t_flags;*/

//functions
int     ft_printf(const char *format, ...);

char    *ft_conv_char(int c);
char    *ft_conv_str(char *argument);
char    *ft_conv_itoa(long long argument);
char    *ft_conv_utoa(unsigned long long argument, char type);

char	*ft_itoa_base(long long nbr, int base);
char	*ft_utoa_base(unsigned long long nbr, char type, int base);


#endif