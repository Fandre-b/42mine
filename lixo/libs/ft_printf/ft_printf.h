/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpais-go <mpais-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:45:04 by mpais-go          #+#    #+#             */
/*   Updated: 2023/10/16 14:41:38 by mpais-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

int	ft_printf(const char *str, ...);

int	ft_numlen(int n);

int	ft_putchar(char c);

int	ft_putadd(unsigned long int nbr);

int	ft_puthexa(unsigned long int nbr, int isup);

int	ft_putnbr(int n);

int	ft_putstr(char *s);

int	ft_putuns(unsigned int n);

#endif