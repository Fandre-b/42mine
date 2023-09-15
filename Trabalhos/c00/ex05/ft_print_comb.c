/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 17:24:09 by fandre-b          #+#    #+#             */
/*   Updated: 2023/08/06 18:33:04 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	putchar(a, b, c)
{
	write(1,&a,1);
	write(1,&a,1);
	write(1,&a,1);
	write(1,&a,1);
	write(1,&a,1);
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = 48
	while (a < 55);
	{
		b= a + 1;
		while (b < 56)
		{
			while (c < 57)
			{
				putchar (a,b,c);
				c++;
			}
			b++;
		}
		a++
	}
}

void	main(void)
{
	ft_pint_comb();
}
