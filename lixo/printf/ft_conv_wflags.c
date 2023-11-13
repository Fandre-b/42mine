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

static char    *ft_padd(char *conv_string, char c, int size, int side)
{
    size_t len;
    char    *new_str;

    len = strlen(conv_string) + size;
    if (size < 0)
        return (conv_string);
    new_str = (char *) malloc (sizeof(char) * (len + 1));
    if(!new_str)
        return(NULL);
    bzero(new_str, len + 1);
    if (side == 0)
    {
        memset(new_str, c, size);
        ft_strlcat (new_str, conv_string, len + 1);
    }
    else if (side == 1)
    {
        ft_strlcpy (new_str, conv_string, size + 1);
        memset(&new_str[len - size], c, size);
    }
    free(conv_string);
    return (new_str);
}

static char	*ft_add_sign(char *conv_str, t_flags strc_flags)
{
	char	*new_str;
	int		len;

	len = strc_flags.plus + strc_flags.space + 2 * strc_flags.hash;
	if (len == 0)
		return(conv_str);
	len += ft_strlen(conv_str);
	new_str = (char *) malloc (sizeof(char) * (len + 1));
	if (!new_str)
		return(NULL);
	if(strc_flags.plus)
		new_str = ft_strjoin("+", conv_str);
	else if(strc_flags.space)
		new_str = ft_strjoin(" ", conv_str);
	else if(strc_flags.hash)
		new_str = ft_strjoin("0x", conv_str);
	strc_flags.plus = 0;
	strc_flags.space = 0;
	strc_flags.hash = 0;
	free (conv_str);
	return (new_str);
}

char	*ft_conv_wflags (char *str, t_flags strc_flags)
{
	char	*new_str;
	int		len;

	len = strc_flags.plus + strc_flags.space + 2*strc_flags.hash;
	len += ft_strlen(str);
	new_str = ft_strdup(str);
	if (strc_flags.precision >= 0)
	{
		new_str = ft_padd(new_str, '0', strc_flags.precision, strc_flags.left);
		new_str = ft_add_sign(new_str, strc_flags);
	}
	else if (strc_flags.zero == 1)
	{
		new_str = ft_padd(new_str, '0', strc_flags.width - len, strc_flags.left);
		strc_flags.width = 0;
		new_str = ft_add_sign(new_str, strc_flags);
	}
	if (strc_flags.width > 0)
	{
		new_str = ft_add_sign(new_str, strc_flags);
		new_str = ft_padd(new_str, ' ', strc_flags.width - len, strc_flags.left);
	}
	return (new_str);
}
