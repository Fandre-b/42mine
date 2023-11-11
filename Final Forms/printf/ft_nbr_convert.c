/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:21:50 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/11 15:44:33 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_numsize(long long nbr, unsigned int base)
{
	size_t	count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr != 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

static size_t	ft_h_numsize(unsigned long long nbr, int base)
{
	size_t	count;

	count = 0;
	if (!nbr)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa(long long nbr, int base)
{
	int		num_size;
	char	*str_conv;

	num_size = ft_numsize(nbr, base);
	str_conv = (char *) malloc (sizeof(char) * (num_size + 1));
	if (!str_conv)
		return (NULL);
	if (nbr < 0)
		str_conv[0] = '-';
	if (nbr == 0)
		str_conv[0] = '0';
	str_conv[num_size] = '\0';
	while (nbr != 0)
	{
		if (nbr < 0)
			str_conv[--num_size] = (char)(-(nbr % base) + '0');
		else
			str_conv[--num_size] = (char)((nbr % base) + '0');
		nbr /= base;
	}
	return (str_conv);
}

char	*ft_htoa(unsigned long long nbr, char type, int base)
{
	int		num_size;
	char	*str_conv;

	num_size = ft_h_numsize(nbr, base);
	str_conv = (char *) malloc (sizeof(char) * (num_size + 1));
	if (!str_conv)
		return (NULL);
	if (!nbr || nbr == 0)
		str_conv[0] = '0';
	str_conv[num_size] = '\0';
	while (nbr != 0)
	{
		if (nbr % base <= 9)
			str_conv[--num_size] = (char)(nbr % base + '0');
		else
		{
			if (type == 'x' || type == 'p')
				str_conv[--num_size] = (char)(nbr % base - 10 + 'a');
			if (type == 'X')
				str_conv[--num_size] = (char)(nbr % base - 10 + 'A');
		}
		nbr /= base;
	}
	return (str_conv);
}

int	ft_put_adress(void *ptr)
{
	int		count;
	char	*str_conv;

	count = 0;
	if (!ptr)
		count += ft_putstr("(nil)", 0);
	else
	{
		count += ft_putstr("0x", 0);
		str_conv = ft_htoa((unsigned long long)ptr, 'x', 16);
		count += ft_putstr(str_conv, 1);
	}
	return (count);
}
