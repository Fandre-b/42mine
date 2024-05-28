/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:15:07 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/12 23:57:09 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_flags
{
    int plus;
    int hash;
    int space;
    int zero;
    int left;
    int width;
    int precision;
    int print_null;
}   t_flags;

//functions
int     ft_printf(const char *format, ...);

int    ft_conv_char(int argument, char *str_flags);
int     ft_conv_str(char *argument, char *str_flags);
int     ft_conv_itoa(long long argument, char *str_flags);
int     ft_conv_utoa(unsigned long long argument, char *str_flags, char type);
int     ft_conv_adress(void *argument, char *str_flags, char type);

t_flags     *ft_process_flags(char *str_flags, char *accepted_flags);

int		ft_print_wflags (char *str_conv, t_flags *flags);

char	*ft_itoa_base(long long nbr, int base);
char	*ft_utoa_base(unsigned long long nbr, char type, int base);

#endif