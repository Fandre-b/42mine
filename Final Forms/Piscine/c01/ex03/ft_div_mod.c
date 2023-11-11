/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:52:06 by fandre-b          #+#    #+#             */
/*   Updated: 2023/07/31 12:07:25 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	val_div;
	int	val_mod;
	int	*div;
	int	*mod;

	div = &val_div;
	mod = &val_mod;
	ft_div_mod(42, 13, div, mod);
}
*/
