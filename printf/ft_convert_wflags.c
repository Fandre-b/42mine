/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_wflags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:04:39 by fandre-b          #+#    #+#             */
/*   Updated: 2023/11/03 11:04:40 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_conv_wflags (char *str, t_flags flags)
{
	char	*new_str;
	char	*middle_str;
	int		len;

	len = flags->plus + flags->space + 2*flags->hash;
	len += ft_strlen(str);
	if (flags->precision > 0)
	{
		new_str = ft_padd(middle_str, "0", flags->precision, flags->left);
		return(ft_add_sign(str, flags));
	}
	if else (flags->zero == 1)
	{
		new_str = ft_padd(str, "0", flags->width - len, flags->left);
		flags->width = 0;
		return(ft_add_sign(middle_str, flags));
	}
	if (flags->width > 0)
	{
		new_str = ft_add_sign(middle_str, flags);
		return(new_str = ft_padd(new_str, " ", flags->width - len, flags->left));
	}
	return (str);
}

char	*ft_add_sign(char *str, t_flags flags)
{
	char	*new_str;
	int		len;


	len = flags->plus + flags->space + 2*flags->hash;
	if (len == 0)
		return(str);
	len += ft_strlen(str);
	new_str = (char *) malloc (sizeof(char) (len + 1));
	if (new_str)
		return(NULL);
	if(flags->plus)
		new_str = ft_strjoin("+", str);
	else if(flags->space)
		new_str = ft_strjoin(" ", str);
	else if(flags->hash)
		new_str = ft_strjoin("0x", str);
	free (str);
	return (new_str);
}

char	*ft_pad(char *conv_string, char c, int size, int side)
{
	size_t len;
	char	*new_str;

	len = ft_strlen(conv_string) + size;
	if (size < 0)
		return (conv_string);
	new_str = (char *) malloc (sizeof(char) * (len + 1));
	if(!new_str)
		return(NULL);
	ft_bzero(new_str, len + 1);
	if (side == 0)
	{
		ft_memset(new_str, c, size);
		strlcat (new_str, conv_string, len + 1);
	}
	else if (side == 1)
	{
		ft_memset(new_str, c, len + 1);
		strlcpy (new_str, conv_string, size + 1);
	}
	free(conv_string);
	return (new_str);
}
