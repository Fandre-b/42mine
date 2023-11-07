/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:19:11 by fandre-b          #+#    #+#             */
/*   Updated: 2023/10/23 17:36:49 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_print_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	width;
	int	plus;
	int	space;
	int	hash;
	int	precision;
	int	zero;
	int	left;
}		t_flags;

int ft_printf(const char *string, ...);

t_flags ft_process_flags(char *str, char *accepted_flags);
char	*ft_conv_wflags(char *str, t_flags flags);

char    *ft_conv_char(char c, char *flags);
char    *ft_conv_str(char *argument, char *flags);
char	*ft_conv_addr(unsigned long int argument, char *flags);
char	*ft_conv_num(int argument, char *flags);
char	*ft_conv_unsigned(unsigned int argument, char *flags);
char	*ft_conv_octal(unsigned int argument, char *flags, char type);

char	*ft_utoa(unsigned int n);
char	*ft_htoa(unsigned int n, char type);
char	*ft_addr(unsigned long int num);


#endif
