/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wflags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:04:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/13 09:10:13 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_add_sign(t_flags *flags);
static int    ft_padd(char *str_conv, t_flags *flags, char c, int size, int side);
//static int		ft_print_padd(char *tr_conv, char *pad_str, t_flags *flags, int side);
static int	ft_putstr_free(char *str, int do_free);


int		ft_print_wflags (char *str_conv, t_flags *flags)
{
	int		len;
	int		count;

	count = 0;
	len = flags->plus + flags->space + 2 * flags->hash;
	len += ft_strlen(str_conv);
	if (flags->zero == 1 && flags->precision == -1)
	{
		count += ft_padd("", flags, '0', flags->width - len, 0);
		flags->width = 0;	
	}
	count += ft_add_sign(flags);
	if (flags->precision >= 0)
		count += ft_padd(str_conv, flags, '0', flags->precision, 0);		
	count += ft_add_sign(flags);
	count += ft_padd(str_conv, flags, ' ', flags->width - len, flags->left);
	free(flags);
	return (count);
}

static int	ft_add_sign(t_flags *flags)
{
	int		count;

	count = 0;
	if(flags->plus)
		count += ft_putstr_free("+", 0);
	else if(flags->space)
		count += ft_putstr_free(" ", 0);
	else if(flags->hash)
		count += ft_putstr_free("0x", 0);
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	return (count);
}

static int		ft_padd(char *str_conv, t_flags *flags, char c, int size, int side)
{
	int		count;

	count = 0;
	if (side == 0)
	{
		while(size-- != 0)
			count += write(1, &c, 1);
		//count += ft_putstr_free(pad_str , 1);
	}
	else if (side == 1)
    {
		if (flags->print_null == 1)
			count += write(1, "\0", 1);
		else
			count += ft_putstr_free(str_conv, 1);
		while(size-- != 0)
			count += write(1, &c, 1);
		//count += ft_putstr_free(pad_str , 1);
    }
	return (count);
}

/*
static int    ft_padd(char *str_conv, t_flags *flags, char c, int size, int side)
{
	int count;
    char    *pad_str;

	while(size++ != 0)
		count += write(1, &c, 1);
	count = 0;
	if (size <= 0)
		pad_str = ft_strdup("");
	else
	pad_str  = (char *)malloc(size + 1);
	if (!pad_str )
		return (-1);
	ft_memset(pad_str , c, size);
	pad_str [size + 1] = '\0';
	ft_print_padd(str_conv, pad_str, flags, side);
    return (count);

}

static int		ft_print_padd(char *str_conv, char *pad_str, t_flags *flags, int side)
{
	int		count;

	count = 0;
	if (side == 0)
		count += ft_putstr_free(pad_str , 1);
	else if (side == 1)
    {
		if (flags->print_null == 1)
			count += write(1, "\0", 1);
		else
			count += ft_putstr_free(str_conv, 1);
		count += ft_putstr_free(pad_str , 1);
    }
	return (count);
}*/

static int		ft_putstr_free(char *str, int do_free)
{
	int	i;
    int count;

	i = 0;
    count = 0;
	while (str && str[i])
		count += write(1, &str[i++], 1);
	if (do_free)
		free(str);
	return (count);
}
